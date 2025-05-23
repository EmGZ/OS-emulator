#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "ConsoleManager.h"
#include "AConsole.h"

ConsoleManager consoles;
void displayHeader() {
    std::cout << R"(
 ________  ________  ________  ________  _______   ________       ___    ___ 
|\   ____\|\   ____\|\   __  \|\   __  \|\  ___ \ |\   ____\     |\  \  /  /|
\ \  \___|\ \  \___|\ \  \|\  \ \  \|\  \ \   __/|\ \  \___|_    \ \  \/  / /
 \ \  \    \ \_____  \ \  \\\  \ \   ____\ \  \_|/_\ \_____  \    \ \    / / 
  \ \  \____\|____|\  \ \  \\\  \ \  \___|\ \  \_|\ \|____|\  \    \/  /  /  
   \ \_______\____\_\  \ \_______\ \__\    \ \_______\____\_\  \ __/  / /    
    \|_______|\_________\|_______|\|__|     \|_______|\_________\\___/ /     
             \|_________|                            \|_________\|___|/              
    )" << std::endl;

    std::cout << "\033[32m" << "Hello, Welcome to CSOPESY command-line interface!" << "\033[0m" << std::endl;
    std::cout << "\033[33m" << "Type 'exit' to quit, 'clear' to clear the screen.\n" << "\033[0m" << std::endl;
}

void screenCMD(const std::vector<std::string>& commandString) {
    // incorrect input
    if (commandString.size() == 2) {
        if (commandString[1] == "s" || commandString[1] == "r") {
            std::cout << "Use format: screen (-r or -s) <console name>\n";
        }
        else {
            std::cout << "screen command not recognized. Try again \n";
        }
    }
    // correct input
    else if (commandString.size() == 3) {
        std::string input = commandString[1];
        std::string name = commandString[2];

        // create console
        if (input == "-s") {
            if (consoles.findConsole(name)) {
                std::cout << "console " << name << " is already in use.\n";
            }
            else {
                consoles.addConsole(name); // create the console
                consoles.viewConsole(name); // view console
                consoles.consoleExit();  // wait to exit
                displayHeader();
            }
        }

        // check created console
        else if (input == "-r") {
            if (!consoles.findConsole(name)) {
                std::cout << "console " << name << " does not exist.\n";
            }
            else {
                consoles.viewConsole(name);
                consoles.consoleExit();
                displayHeader();
            }
        }
    }
    // unknown command
    else {
        std::cout << "screen command not recognized. Try again \n";
    }

}

void checkCommand(const std::vector<std::string>& commandString) {

    std::string cmd = commandString[0];
    if (cmd == "initialize") {
        std::cout << cmd << " command recognized. Doing something.\n";
        // Commands to be added
    }
    else if (cmd == "screen") {
        screenCMD(commandString);
    }
    else if (cmd == "scheduler-test") {
        std::cout << cmd << " command recognized. Doing something.\n";
        // Commands to be added
    }
    else if (cmd == "scheduler-stop") {
        std::cout << cmd << " command recognized. Doing something.\n";
        // Commands to be added
    }
    else if (cmd == "report-util") {
        std::cout << cmd << " command recognized. Doing something.\n";
        // Commands to be added
    }
    else if (cmd == "clear") {
        system("cls"); // Clear screen
        displayHeader(); // Redisplay header
    }
    else if (cmd == "exit") {
        std::cout << cmd << " command recognized. Thank you! Exiting program.\n";
        exit(0);
    }
    else {
        std::cout << "Command \"" << cmd << "\" not recognized. Try again.\n";
    }
}

int main()
{
    std::vector<std::string> commandString;
    std::string inputLine;
    displayHeader();

    while (true) {
        commandString.clear();
        std::cout << "Enter a command: ";

        if (std::getline(std::cin, inputLine)) {
            std::istringstream iss(inputLine);
            std::string command;
            while (iss >> command) {
                commandString.push_back(command);
            }
        }

        if (!commandString.empty()) {
            checkCommand(commandString);
        }
    }


    return 0;
}
