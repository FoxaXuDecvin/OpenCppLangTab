//Based old Project https://github.com/FoxaXuDecvin/Calcium-Project
//Based on CASK.h
//Copyright FoxaXu 2024	

#pragma once
#include"../shload.h"

int maxread = 1;
string ReadNULLCheck;
int _textapi_getdocmax(string file) {
	if (!check_file_existence(file)) {
		cout << "Textapi.filemissing.getdocmax" << endl;
		return 0;
	}

	maxread = 1;

	while (true) {
		ReadNULLCheck = LineReader(file, maxread);
		if (ReadNULLCheck == "overline") {
			maxread--;
			return maxread;
		}
		maxread++;
	}

}

int maxdocsize;
void _textapi_typetext(string file) {
	if (check_file_existence(file)) {
		maxdocsize = getdocmax(file);

		maxdocsize++;

		for (int startRoll = 1; maxdocsize != startRoll; startRoll++) {
			cout << LineReader(file, startRoll) << endl;
		}
		return;
	}
	else {
		cout << "ERROR FILE NOT EXIST : " << file << endl;
		return;
	}
}