#include "CommandProcessor.h"
#include <iostream>

//====== CLASS that handles all inputted command ======

bool CommandProcessor::executeCommand(const std::string& cmd, Console& console) {
    if (cmd == "exit") {
        return false;
    } else if (cmd == "clear") {
        console.clearScreen();
        console.printDefaultDisplay();
    } else if (cmd == "COMMAND 1") {    //! ADD MORE COMMANDS
        std::cout << "COMMAND 1 recognized. Doing something." << std::endl;
    } else {
        std::cout << "invalid command" << std::endl;
    }
    return true; 
}
