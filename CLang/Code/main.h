#pragma once

#include"SourceHeader/shload.h"

void argsApi(string args$api) {

	if (args$api == args$api) {
		_prtoutmsg("Args = " + args$api);
		return;
	}

	_prtoutmsg("Unknown Args :  " + args$api);
	return;
}

int _HeadMainLoad() {
	_prtendl();
	
	_dapi_rmdir("HelloWorld");
	_dapi_mkdir("HelloWorld");

	_fileapi_createmark("HelloWorld/Hel.txt", "114514");

	_prtoutmsg("Hello World");
	_prtoutmsg("This is Open Cpp Lang Tab");
	_prtoutmsg("SEED :   " + _get_random_s(1, 11111));

	_pause();
	return 0;
}