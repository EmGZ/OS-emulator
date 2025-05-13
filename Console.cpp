#include "Console.h"
#include <iostream>

//====== CLASS that handles main display ======

// changes text color
void Console::setColor(WORD color) {  
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// clear screen on 'clear' command
void Console::clearScreen() {
    system("cls");
}

// print the default display
void Console::printDefaultDisplay() {
    std::cout << "  ____    ____      ___     ____    _______    ____    __   __		" << std::endl;
	std::cout << " / ___|  / ___|    / _ \\   |  _ \\   |  ___|   / ___|   \\ \\ / /	" << std::endl;
	std::cout << "| |      \\___ \\   | | | |  | |_) |  |  __|    \\___ \\    \\ V /	" << std::endl;
	std::cout << "| |___    ___) |  | |_| |  |  __/   | |___     ___) |    | |			" << std::endl;
	std::cout << " \\____|  |____/    \\___/   |_|      |_____|   |____/     |_|		" << std::endl;
    setColor(10);  
    std::cout << "Hello, Welcome to CSOPESY commandline!" << std::endl;
    setColor(14);  
    std::cout << "Type 'exit' to quit, 'clear' to clear the screen\n";
    setColor(7);  // Reset to white

}
