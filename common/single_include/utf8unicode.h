/*
 * Copyright (C) 2015 Advanced Software Engineering Limited.
 *
 * This file is part of the ChartDirector software. Usage of this file is
 * subjected to the ChartDirector license agreement. See the LICENSE.TXT
 * file that comes with the ChartDirector software release, or visit
 * Advanced Software Engineering's web site at www.advsofteng.com or
 * email to support@advsofteng.com for information.
 *
 */
// from ChartDirector chartdir.h
#ifndef CCHARTDIR_HDR_20200827
#define CCHARTDIR_HDR_20200827

//
// Utility to convert from WCHAR string to UTF8 string
//
class WCHARtoUTF8
{
public :
	WCHARtoUTF8(const wchar_t *w_string) : utf8_string(0)
	{
		if (0 == w_string)
			utf8_string = 0;
		else
		{
			int string_len = 0;
			while (w_string[string_len]) ++string_len;
			char *ptr = utf8_string = new char[string_len * 3 + 1];
			for (int w = *w_string; w != 0; w = *(++w_string))
			{
				// only support 16 bit unicode
				int uw = w & 0xffff;
				if (uw < 0x80)
					*(ptr++) = (char)uw;
				else if (uw < 0x800)
				{
					*(ptr++) = (char)(0xC0 | (uw >> 6));
					*(ptr++) = (char)(0x80 | (uw & 0x3F));
				}
				else
				{
					*(ptr++) = (char)(0xE0 | (uw >> 12));
					*(ptr++) = (char)(0x80 | ((uw >> 6) & 0x3F));
					*(ptr++) = (char)(0x80 | (uw & 0x3F));
				}
			}
			*ptr = 0;
		}
	}

	operator const char*()
	{
		return utf8_string;
	}

	~WCHARtoUTF8()
	{
		delete[] utf8_string;
	}

private :
	char *utf8_string;

	//disable assignment
	WCHARtoUTF8(const WCHARtoUTF8 &rhs);
	WCHARtoUTF8 &operator=(const WCHARtoUTF8 &rhs);
};

//
// Utility to convert from UTF8 string to WCHAR string
//
class UTF8toWCHAR
{
public :
	UTF8toWCHAR(const char *utf8_string) : w_string(0)
	{
		if (0 == utf8_string)
			w_string = 0;
		else
		{
			int string_len = 0;
			while (utf8_string[string_len]) ++string_len;
			wchar_t *ptr = w_string = new wchar_t[string_len + 1];
			for (int i = 0; i < string_len; ++i)
			{
				int c = utf8_string[i];			
				if (((c & 0xf0) == 0xe0) && (i + 2 < string_len))
				{
					*ptr = (wchar_t)(((c & 0xf) << 12) | ((utf8_string[++i] & 0x3f) << 6));
					*ptr = (*ptr) | (utf8_string[++i] & 0x3f);
					++ptr;
				}
				else if (((c & 0xe0) == 0xc0) && (i + 1 < string_len))
					*(ptr++) = (wchar_t)(((c & 0x1f) << 6) | ((utf8_string[++i] & 0x3f) << 6));
				else
					*(ptr++) = (wchar_t)c;
			}

			*ptr = 0;
		}
	}

	operator const wchar_t*()
	{
		return w_string;
	}

	~UTF8toWCHAR()
	{
		delete[] w_string;
	}

private :
	wchar_t *w_string;

	//disable assignment
	UTF8toWCHAR(const UTF8toWCHAR &rhs);
	UTF8toWCHAR &operator=(const UTF8toWCHAR &rhs);
};


#endif
