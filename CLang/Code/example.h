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
	_prtendl();
	_prtoutmsg($version_title);
	_prtoutmsg("By FoxaXu        sign : " + to_string(aaa));
	_prtoutmsg("Github Page :   https://github.com/FoxaXuDecvin/OpenCppLangTab");
	_prtoutmsg("Report      :    https://github.com/FoxaXuDecvin/OpenCppLangTab/issues");
	_prtendl();
	_prtoutmsg("---------------------------------------------------");
	_prtoutmsg("OpenCLT ...   " + $version_code_str);
    _prtoutmsg("Copyright FoxaXu  " + $year_message);
	_prtoutmsg("Core Time :  " + $buildtime + "   " + _Run_SysKernel);
	_prtoutmsg("---------------------------------------------------");
	_prtoutmsg("Running File :  " + _$GetSelfFull);
	_prtoutmsg("File Path :  " + _$GetSelfPath);
	_prtoutmsg($version_msg);
	_pause();
	return 0;
}