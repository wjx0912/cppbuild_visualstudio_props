@echo off

cd /d "D:/sdk/props_build_vs2022/opencv-4.9.0/build/x64-cpu"
call "C:/Program Files/Microsoft Visual Studio/2022/Enterprise/VC/Auxiliary/Build/vcvars64.bat"
msbuild ALL_BUILD.vcxproj /p:Configuration=Release
msbuild INSTALL.vcxproj /p:Configuration=Release
msbuild ALL_BUILD.vcxproj /p:Configuration=Debug
msbuild INSTALL.vcxproj /p:Configuration=Debug

cd /d "D:/sdk/props_build_vs2022/opencv-4.9.0/build/x86-cpu"
call "C:/Program Files/Microsoft Visual Studio/2022/Enterprise/VC/Auxiliary/Build/vcvars32.bat"
msbuild ALL_BUILD.vcxproj /p:Configuration=Release
msbuild INSTALL.vcxproj /p:Configuration=Release
msbuild ALL_BUILD.vcxproj /p:Configuration=Debug
msbuild INSTALL.vcxproj /p:Configuration=Debug

pause
