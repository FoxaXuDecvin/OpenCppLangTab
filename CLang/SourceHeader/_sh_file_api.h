//Source Header
// File API
// Copyright FoxaXu 2024

#include"include.h"

//API

int CountLines(string filename)
{
	ifstream ReadFile;
	int n = 0;
	string tmp;
	ReadFile.open(filename.c_str());
	if (ReadFile.fail())
	{
		return 0;
	}
	else
	{
		while (getline(ReadFile, tmp, '\n'))
		{
			n++;
		}
		ReadFile.close();
		return n;
	}
}

//Main
bool _existfile(const std::string& filename) {
	std::ifstream file(filename);
	if (file.is_open()) {
		return true;
	}
	else {
		return false;
	}
}

bool _fileapi_createmark(string File, string info) {
	ofstream CMark;
	CMark.open(File);
	CMark << info << endl;
	CMark.close();

	if (_existfile(File)) {
		return true;
	}
	else {
		return false;
	}
}

string _fileapi_textread(string File, int line_number) {
	if (_existfile(File)) {}
	else {
		_sh_throw_error("FileAPI.TextRead :  File Not Exist");
		return "FileNotExist";
	}
	int lines, i = 0;
	string temp;
	fstream file;
	file.open(File.c_str());
	lines = CountLines(File);

	if (line_number <= 0)
	{
		_sh_throw_error("FileAPI.TextRead :  Line Error On : " + File +" .  Line :  " + to_string(line_number));
		return "LineError";
	}
	if (file.fail())
	{
		_sh_throw_error("FileAPI.TextRead :  File Read Failed :  " + File);
		return "ReadFailed";
	}
	if (line_number > lines)
	{
		return "overline";
	}
	while (getline(file, temp) && i < line_number - 1)
	{
		i++;
	}
	file.close();
	return temp;
}

