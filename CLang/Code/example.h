#pragma once

#include"shload.h"

//Args API
void argsApi(string args$api) {

	if (args$api == args$api) {
		_prtoutmsg("Args = " + args$api);
		return;
	}

	_prtoutmsg("Unknown Args :  " + args$api);
	return;
}

//Put Code Here
int _HeadMainLoad() {
	_prtendl();
	_prtoutmsg("Open Cpp Lang Tab");
	_prtoutmsg("By FoxaXu");
	_prtoutmsg("Github Page :   https://github.com/FoxaXuDecvin/OpenCppLangTab");
	_prtoutmsg("Report      :    https://github.com/FoxaXuDecvin/OpenCppLangTab/issues");
	_prtendl();
	_prtoutmsg("---------------------------------------------------");
	_prtoutmsg("OpenCLT ...   " + $version_code_str);
    _prtoutmsg("Copyright FoxaXu  " + $year_message);
    _prtoutmsg("Core Time :  " + $buildtime);
	_prtoutmsg($version_msg);
	_pause();
	return 0;
}