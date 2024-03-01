//Cpp Includer
#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<random>

#include"Settings\_sh_version.h"
#include"Settings\sh_settings.h"
#include"System/pub.h"

void _sh_throw_error(string message) {
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