//Switch Tools
#pragma once
#include"include.h"
using namespace std;

//Message
string $_pause = "Press Enter...   ";


//Main
void _pause() {
	printf($_pause.c_str());
	getchar();
	return;
}