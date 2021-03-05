#ifndef __UNICODE_UTF8_CONVERT_20210205_H__
#define __UNICODE_UTF8_CONVERT_20210205_H__
#include <string>
#include "wxx_textconv.h"

static std::string unicode_to_utf8(std::wstring unicode)
{
    std::string utf8 = Win32xx::CWtoA(unicode.c_str(), CP_UTF8);
    return utf8;
}

static std::wstring utf8_to_unicode(std::string buffer)
{
    std::wstring unicode = Win32xx::CAtoW(buffer.c_str(), CP_UTF8);
    return unicode;
}

static std::string ansi_to_utf8(std::string buffer)
{
    std::wstring unicode = Win32xx::CAtoW(buffer.c_str());
    std::string utf8 = Win32xx::CWtoA(unicode.c_str(), CP_UTF8);
    return utf8;
}

static std::string utf8_to_ansi(std::string buffer)
{
    std::wstring unicode = Win32xx::CAtoW(buffer.c_str(), CP_UTF8);
    std::string ansi = Win32xx::CWtoA(unicode.c_str());
    return ansi;
}

#endif
