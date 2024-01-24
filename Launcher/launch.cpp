#include"..\main.h"
//EDIT ON MAIN_H
using namespace std;

string readbuffer;

void printmsgoclt() {
    _prtoutmsg("Open Cpp Lang Tab __  Version");
    _prtoutmsg("Copyright " + $year_message);
    _prtoutmsg("");

}

int main(int argc, char* argv[]) {
    for (int readargc = 1, fileswitch = 0; readargc != argc; readargc++) {
        readbuffer = argv[readargc];
        if (readbuffer == "--oclt-version") {
            printmsgoclt();

        }
    }
}
