#pragma once
#include"SourceHeader/include.h"

void _LaunchScreen(void) {
    _prtendl();
    _prtoutmsg("Open Cpp Lang Tab ...   " + $version_code_str);
    _prtoutmsg("Copyright FoxaXu  " + $year_message);
    _prtoutmsg("Core Build Time :  " + $buildtime);
    _prtendl();
    _prtendl();
}