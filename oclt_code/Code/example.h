#pragma once

#include"../shload.h"

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
	_p("Open CPP Lang Tab       " + $version_title);
	_p("Build version :   " + $version_code_str);
	_p("CodeName   :   " + $codename + "  " + $version_msg);
	_p("Release time (string)  : " + $buildtime);
	_p("OS Kernel £º  " + _Run_SysKernel);
	_p("----------------------------------------------------------");
	_p("Copyright FoxaXu " + $year_message);
	_p("Open Cpp Lang Tab    .....");
	_p("Github : https://github.com/FoxaXuDecvin/OpenCppLangTab");
	_p("Run ArgsLonger   " + _get_argslonger());
	_p("Argument :  " + native_argument);

	_pause();
	return 0;
}