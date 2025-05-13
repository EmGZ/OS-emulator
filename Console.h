#ifndef CONSOLE_H
#define CONSOLE_H

#include <windows.h>

class Console {  
public:
    void setColor(WORD color);
    void clearScreen();
    void printDefaultDisplay();
};

#endif 
