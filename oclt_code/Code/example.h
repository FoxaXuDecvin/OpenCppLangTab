//Everything is Possible
//On OpenCppLangTab
//Code on _HeadMainLoad() 

#pragma once

#include"../shload.h"
#define _CRT_SECURE_NO_WARNINGS

bool PreLaunchLoad(void) {
	//Put Preload code here
	//

	//End
	return true;
}

//Args API
void argsApi(string args$api) {

	//if (argsSetExit) set true
	//Process will close after args run

	if (args$api == args$api) {
		_prtoutmsg("Argument = " + args$api);
		return;
	}

	_prtoutmsg("Unknown Args :  " + args$api);
	return;
}

//Put Code Here
int _HeadMainLoad() {
	//main
	_p("----------------------------------------------------------");
	_p("Launch Time :   " + __GetFullTime());
	_p("OpenCppLangTab  " + $version_title + " " + $version_code_str);
	_p("System :    " + _Run_SysKernel);
	_p("Build Time (string)  : " + $buildtime + "  " + $version_msg);
	_p("System :  " + _Run_SysKernel);
	_p("Github : https://github.com/FoxaXuDecvin/OpenCppLangTab");
	_p("----------------------------------------------------------");
	_p("Copyright FoxaXu " + $year_message);
	_p("Default Temple.");
	_p("Edit :   Code/example.h  -->  int _HeadMainLoad()");
	_p("Public Engine Path :   " + _Build_Path);
	sleepapi_ms(1600);
	return 0;
}