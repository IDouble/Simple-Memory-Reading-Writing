#include <iostream>
#include <Windows.h>

using namespace std;

int main(){

	int readTest = 0;

	// HWND (Windows window) by Window Name
	HWND hwnd = FindWindowA(NULL, "Tutorial-x86_64");

	// Check if HWND found the Window
	if (hwnd == NULL) {
		cout << "Can't find Process." << endl;
		Sleep(3000); // Sleep 3 seconds
		exit(-1); // Exit the program if it did not find the Window
	} else {
		// A 32-bit unsigned integer, DWORDS are mostly used to store Hexadecimal Addresses
		DWORD procID;
		GetWindowThreadProcessId(hwnd, &procID);
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);

		if (procID == NULL) {
			cout << "Can't find Process." << endl;
			Sleep(3000); // Sleep 3 seconds
			exit(-1); // Exit the program if it did not find the Window
		} else {
			ReadProcessMemory(handle, (PBYTE*)0x03007640, &readTest, sizeof(readTest), 0);
			cout << readTest << endl;
			Sleep(10000); // Sleep 10 seconds
		}
	}
}