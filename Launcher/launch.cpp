#include"..\main.h"
//EDIT ON MAIN_H
using namespace std;

string readbuffer;

void printmsgoclt() {
    _prtoutmsg("Build By OpenCLT");
    _prtoutmsg($version_title + "   " + to_string($version_code));
    _prtoutmsg("OpenCLT " + $version_msg);
    _prtoutmsg("Code Name :   " + $codename);
    _prtoutmsg("    Copyright FoxaXu " + $year_message);
    _prtoutmsg(" Github :  " + $github_website);
    _pause();
    return;

}

int main(int argc, char* argv[]) {
    for (int readargc = 1, fileswitch = 0; readargc != argc; readargc++) {
        readbuffer = argv[readargc];
        if (readbuffer == "--oclt-version") {
            printmsgoclt();
            return 0;
        }
    }

    int return_code = _HeadMainLoad();

    return return_code;
}
