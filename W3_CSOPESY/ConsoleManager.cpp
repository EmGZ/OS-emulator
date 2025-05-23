#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "ConsoleManager.h"

/*
* This function adds a new console to the list of consoles
* 
* @param name - the name of the console
*/
void ConsoleManager::addConsole(const std::string& name) {
    // Check if the console already exists in the list of consoles
    // auto - automatically determines the type of the variable
    for (const auto& console : consoles) {
        // Check if the console name already exists
        if (console.getName() == name) {
            std::cout << "Console " << name << " is already in use." << std::endl;
            return;
        }
    }

    // If the console does not exist, create a new one
    // Add the new console to the list of consoles
    consoles.emplace_back(name, 10, 100);
    std::cout << "Console " << name << " created" << std::endl;
}

/*
* This function checks if the specified console exists
* 
* @param name - the name of the console
* @return true if the console exists, false otherwise
*/
bool ConsoleManager::findConsole(const std::string& name) const {
    // Check if the console exists in the list of consoles
    for (const auto& console : consoles) {
        // If the console name matches, return true
        if (console.getName() == name) {
            return true;
        }
    }
    // If the console does not exist, return false
    return false;
}

/*
* This function displays the information of the specified console
* 
* @param name - the name of the console
*/
void ConsoleManager::viewConsole(const std::string& name) const {
    // Check if the console exists in the list of consoles
    // auto - automatically determines the type of the variable
    for (const auto& console : consoles) {
        // Check if the console name matches the specified name
        // If the console name matches, display its information
        if (console.getName() == name) {
            system("cls"); // cleans screen, as if entering new screen

            std::cout << "=====================================================";
            std::cout << "\nProcess Name: " << name << std::endl;
             std::cout << "Instruction Line: " << console.getCurrLine() << "/" << console.getTotalLines() << std::endl;
            std::cout << "Creation Time: " << console.getTimestamp() << std::endl;
            std::cout << "=====================================================" << std::endl;

            return;
        }
    }
    // If console does not exist, display an error message
    std::cout << "Console " << name << " does not exist." << std::endl;
}

/*
* This function waits for user input until "exit" is entered
*/
void ConsoleManager::consoleExit() {
    bool running = true;
    std::string input;

    // Wait for user input until "exit" is entered
    // The program will keep running until the user types "exit"
    while (running) {
        input.clear();
        std::cout << "Enter a command: ";
        std::cin >> input;

        if (input == "exit") {
            running = false;
        }
        else {
            std::cout << "Command not recognized. Type \'exit\' to leave this screen" << std::endl;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("cls");
}