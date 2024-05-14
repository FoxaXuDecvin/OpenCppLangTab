@echo off
set MSVCBinHostx64=123

echo= Open Build.bat
echo= Set MSVCBinHostx64 Path

%MSVCBinHostx64%\cl.exe launch.cpp
pause
exit