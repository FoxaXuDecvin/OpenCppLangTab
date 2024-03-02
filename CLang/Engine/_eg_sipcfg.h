//Base Engine
//Simple File config Engine
//Copyright FoxaXu 2024

#include"..\shload.h"

//Design On Calcium Project

string _load_sipcfg(string _sc_File,string _sc_ID) {
	string readbufferA;
	int readptr = 1;
	if (check_file_existenceA(_sc_File)) {
		while (true) {
			readptr++;
			string tempptr = _fileapi_textread(_sc_File, readptr);
			if (tempptr == "ReadFailed") {
				cout << "Failed to Load Simple Config" << endl;
				cout << "Open File Failed :  " << _sc_File << endl;
				break;
			}
			if (tempptr == "overline") {
				_sh_throw_error("Load Simple Config Error :  Unknown Config :  Not Found  ----  On File :    _" + _sc_File + "_");
				return "";
			}
			readbufferA = _api_PartRead(tempptr, "$", "=");

			//cout << "Read Up :  Line " << readptr << "   INFO :  _" << tempptr << "_" << endl;

			if (readbufferA == _sc_ID) {
				return _api_PartRead(tempptr, "=", ";");
			}

			if (tempptr == "")break;

			continue;
		}
		return "";
	}
	else {
		_sh_throw_error("Load Simple Config Error :  File Not Found   _" + _sc_File + "_");
		return "";
	}
}