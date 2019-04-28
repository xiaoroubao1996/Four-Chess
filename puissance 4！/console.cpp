#include "console.h"




void console::error_exit(const string& s) const {
	cerr << s;
    ExitProcess(0); 
}

console::console(void){
hScreenBuffer = GetStdHandle(STD_OUTPUT_HANDLE);
if (hScreenBuffer == INVALID_HANDLE_VALUE) {
error_exit("Can't get screen handle");
}
GetConsoleScreenBufferInfo (hScreenBuffer, &screenInfo);
clear();
}

console::~console(void){
SetConsoleTextAttribute(hScreenBuffer, screenInfo.wAttributes);

}
void console::set_title(const wstring& s) {
	SetConsoleTitle(s.c_str());
}

void console::set_cursor_color(color c) {
switch(c) {
case default_color:
SetConsoleTextAttribute(hScreenBuffer, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
break;
case red:
SetConsoleTextAttribute(hScreenBuffer, FOREGROUND_RED | FOREGROUND_INTENSITY);
break;
case green:
SetConsoleTextAttribute(hScreenBuffer, FOREGROUND_GREEN| FOREGROUND_INTENSITY);
break;
case blue:
SetConsoleTextAttribute(hScreenBuffer, FOREGROUND_BLUE| FOREGROUND_INTENSITY);
break;
case yellow:
SetConsoleTextAttribute(hScreenBuffer, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
break;
case white:
SetConsoleTextAttribute(hScreenBuffer, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
break;
default:
error_exit("Unknown color in set_cursor_color");
}
}


void console::set_cursor_position(const COORD& p) {
	SetConsoleCursorPosition(hScreenBuffer, p);
}

void console::clear() {
system("CLS");
}

void console::set_dimensions(unsigned int w, unsigned int h) {
	CONSOLE_SCREEN_BUFFER_INFO info;
	COORD coordMax;
	coordMax = GetLargestConsoleWindowSize(hScreenBuffer);
	if (h > (unsigned int)coordMax.Y) h = coordMax.Y;
	if (w > (unsigned int)coordMax.X) w = coordMax.X;
	if (!GetConsoleScreenBufferInfo(hScreenBuffer, &info)) 
		error_exit("erreur!SetConsoleScreenBufferSize");
	info.srWindow.Left = 0; 
	info.srWindow.Right = info.dwSize.X - 1; 
	info.srWindow.Top = 0;
	info.srWindow.Bottom = h - 1; 
	if (h < (unsigned int)info.dwSize.Y){
		if (!SetConsoleWindowInfo(hScreenBuffer, TRUE, &info.srWindow))
			error_exit("erreur!SetConsoleWindowInfo");
		info.dwSize.Y = h;
		if (!SetConsoleScreenBufferSize(hScreenBuffer, info.dwSize))
			error_exit("erreur!SetConsoleScreenBufferSize");
	}else if (h > (unsigned int)info.dwSize.Y){
		info.dwSize.Y = h;
		if (!SetConsoleScreenBufferSize(hScreenBuffer, info.dwSize))
			error_exit("erreur!SetConsoleScreenBufferSize");
		if (!SetConsoleWindowInfo(hScreenBuffer, TRUE, &info.srWindow))
			error_exit("erreur!SetConsoleWindowInfo");
	}
	if (!GetConsoleScreenBufferInfo(hScreenBuffer, &info))
		error_exit("erreur!SetConsoleWindowInfo");;
	info.srWindow.Left = 0; 
	info.srWindow.Right = w - 1;
	info.srWindow.Top = 0;
	info.srWindow.Bottom = info.dwSize.Y - 1; 
	if (w < (unsigned int)info.dwSize.X){
		if (!SetConsoleWindowInfo(hScreenBuffer, TRUE, &info.srWindow))
			error_exit("erreur!SetConsoleWindowInfo");
		info.dwSize.X = w;
		if (!SetConsoleScreenBufferSize(hScreenBuffer, info.dwSize))
			error_exit("erreur!SetConsoleScreenBufferSize");
	}else if (w > (unsigned int)info.dwSize.X){
		info.dwSize.X = w; 
		if (!SetConsoleScreenBufferSize(hScreenBuffer, info.dwSize))
			error_exit("erreur!SetConsoleScreenBufferSize");
		if (!SetConsoleWindowInfo(hScreenBuffer, TRUE, &info.srWindow))
			error_exit("erreur!SetConsoleWindowInfo");
	}
}


void console::clear(COORD &p){
set_cursor_position(p);
std::cout<<' ';
}




