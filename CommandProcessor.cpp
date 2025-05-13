#include "CommandProcessor.h"
#include <iostream>

//====== CLASS that handles all inputted command ======

bool CommandProcessor::executeCommand(const std::string& cmd, Console& console) {
    if (cmd == "exit") {
        return false;
    } else if (cmd == "clear") {
        console.clearScreen();
        console.printDefaultDisplay();
    } else if (cmd == "initialize") {  
        std::cout << cmd << " command recognized. Doing something." << std::endl;
        // Commands to be added
    } else if (cmd == "screen") { 
        std::cout << cmd << " command recognized. Doing something." << std::endl;
        // Commands to be added
    } else if (cmd == "scheduler-test") {
        std::cout << cmd << " command recognized. Doing something." << std::endl; 
        // Commands to be added
    } else if (cmd == "scheduler-stop") {
        std::cout << cmd << " command recognized. Doing something." << std::endl; 
        // Commands to be added
     } else if (cmd == "report-util") {
        std::cout << cmd << " command recognized. Doing something." << std::endl; 
        // Commands to be added   
    } else {
        std::cout << "invalid command" << std::endl;
    }
    return true; 
}
