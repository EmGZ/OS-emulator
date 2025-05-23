#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "ConsoleManager.h"
#include "AConsole.h"

ConsoleManager consoles;
/*
* This function prints the ASCII text header
*/
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

/*
* This function processes the screen command
* User may opt to start a new console or reopen an existing console
* 
* @param commandString - a vector of strings containing the command and its arguments
*/
void screenCMD(const std::vector<std::string>& commandString) {
    // Incorrect input string size
    if (commandString.size() == 2) {
        if (commandString[1] == "s" || commandString[1] == "r") {
            std::cout << "Use Format: screen (-r or -s) <console name>\n";
        }
        else {
            std::cout << "Screen command not recognized. Try again \n";
        }
    }
    // Correct input string size
    else if (commandString.size() == 3) {
        std::string input = commandString[1];
        std::string name = commandString[2];

        // Start/Create console
        if (input == "-s") {
            if (consoles.findConsole(name)) {
                std::cout << "Console " << name << " is already in use.\n";
            }
            else {
                std::cout << "Creating console " << name << "...\n";
                consoles.addConsole(name); // Create the console
                consoles.viewConsole(name); // View console
                consoles.consoleExit();  // Wait to exit
                displayHeader();
            }
        }

        // Reopen console
        else if (input == "-r") {
            // If console does not exist
            if (!consoles.findConsole(name)) {
                std::cout << "Console " << name << " does not exist.\n";
            }
            else {
                consoles.viewConsole(name); // View console
                consoles.consoleExit(); // Wait to exit
                displayHeader();
            }
        }
        // Invalid command
        else {
            std::cout << "Screen command not recognized. Try again \n";
        }
    }
    // Unknown command
    else {
        std::cout << "Screen command not recognized. Try again \n";
    }

}

/*
* This function checks if the input command is valid (accepted) or not
* including specific actions fo clear, exit, and screen commands
* 
* @param commandString - a vector of strings containing the command and its arguments
*/
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

        // This loop reads the entire line of input
        std::getline(std::cin, inputLine);
        // Split the input line into words
        if (std::getline(std::cin, inputLine)) {
            std::istringstream iss(inputLine);
            std::string command;
            while (iss >> command) {
                commandString.push_back(command);
            }
        }

        // Check if the command is empty
        if (!commandString.empty()) {
            checkCommand(commandString);
        }
    }


    return 0;
}
