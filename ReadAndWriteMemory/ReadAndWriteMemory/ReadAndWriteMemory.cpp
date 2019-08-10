#include <iostream>
#include <Windows.h>
using namespace std;

int main(){

	int readTest = 0;

	HWND hwnd = FindWindowA(NULL, "Tutorial-x86_64");

	if (hwnd == NULL) {
		cout << "Can't find Process." << endl;
		Sleep(3000);
		exit(-1);
	} else {
		DWORD procID;
		GetWindowThreadProcessId(hwnd, &procID);
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);

		if (procID == NULL) {
			cout << "Can't find Process." << endl;
			Sleep(3000);
			exit(-1);
		} else {
			ReadProcessMemory(handle, (PBYTE*)0x03007640, &readTest, sizeof(readTest), 0);
			cout << readTest << endl;
			Sleep(10000);
		}
	}

}