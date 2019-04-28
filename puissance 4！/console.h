#if !defined(CONSOLE)
#define CONSOLE


#include <Windows.h>
#include <string>
#include <iostream>
#include <exception>


using namespace std;

enum color {default_color, blue, yellow, red, green, white}; 

class console{
public:
console(void);
~console(void);
void set_title(const wstring& s);
void set_dimensions(unsigned int width, unsigned int height);
void set_cursor_position(const COORD& p);
void set_cursor_color(color c);
void clear(COORD &p);
void clear();
private:
HANDLE hScreenBuffer;
CONSOLE_SCREEN_BUFFER_INFO screenInfo;
void error_exit(const string& s) const;
};


#endif
