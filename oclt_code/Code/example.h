#pragma once

#include"../shload.h"

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
		_prtoutmsg("Args = " + args$api);
		return;
	}

	_prtoutmsg("Unknown Args :  " + args$api);
	return;
}

//Put Code Here
int _HeadMainLoad() {
	//main
	_p("----------------------------------------------------------");
	_p("Open Cpp Lang Tab       " + $version_title);
	_p("Build version :   " + $version_code_str);
	_p("CodeName   :   " + $codename + "  " + $version_msg);
	_p("RT (string)  : " + $buildtime);
	_p("System ��  " + _Run_SysKernel);
	_p("Github : https://github.com/FoxaXuDecvin/OpenCppLangTab");
	_p("----------------------------------------------------------");
	_p("Copyright FoxaXu " + $year_message);
	_p("A Cpp Development platform");

	_pause();
	return 0;
}