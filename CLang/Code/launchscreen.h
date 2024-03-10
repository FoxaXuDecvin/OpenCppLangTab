#pragma once
#include"SourceHeader/include.h"

void _LaunchScreen(void) {
    _prtendl();
    _prtoutmsg("OpenCLT ...   " + $version_code_str);
    _prtoutmsg("Copyright FoxaXu  " + $year_message);
    _prtoutmsg("Core Time :  " + $buildtime);
    _prtendl();
    _prtendl();
}