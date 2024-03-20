//Cpp Includer
#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<random>

#include"SourceHeader/Settings/_sh_version.h"
#include"SourceHeader/Settings/sh_settings.h"
#include"SourceHeader/System/pub.h"

void _sh_throw_error(string message) {
	if (__settings_throwErrorMode == false)return;
	_api_prtmsg("----[ERROR](MESSAGE) :  " + message + "\n");
	return;
}


#ifdef _WIN32
//Windows
#include"System\WIN.h"

#else
//LINUX
#include"System\LUX.h"

#endif // _SystemAPI


//END