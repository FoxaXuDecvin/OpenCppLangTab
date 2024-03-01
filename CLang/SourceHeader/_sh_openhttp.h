// Http/Https Download Toolkit
// Base System API
// Copyright FoxaXu 2024

#include"include.h"


bool _$BufferCache;

//URLDown

//return True/False  =   result
bool _urldown_api(string url, string savepath) {
	//Disabled Cache
	_$BufferCache = URLDown(url, savepath);

	//Decide
	if (check_file_existenceA(savepath)) {
		return true;
	}
	else {
		return false;
	}

	//No Code
}

//END