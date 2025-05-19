//
// Created by Erika on 19/05/2025.
//
#include <iostream>
#include <string>
#include <vector>
#include <limits>


#include "ConsoleManager.h"

void ConsoleManager::addConsole(const std::string& name) {
    for (const auto& console : consoles) {
        if (console.getName() == name) {
            std::cout << "console: " << name << " is already in use" << std::endl;
            return;
        }
    }

    consoles.emplace_back(name, 10, 100);
    std::cout << "console: " << name << " created" << std::endl;
}

bool ConsoleManager::findConsole(const std::string& name) const {
    for (const auto& console : consoles) {
        if (console.getName() == name) {
            return true;
        }
    }
    // console not yet created
    return false;
}

void ConsoleManager::viewConsole(const std::string& name) const {
    for (const auto& console : consoles) {
        if (console.getName() == name) {
            system("cls"); // cleans screen, as if entering new screen

            std::cout << "=====================================================";
            std::cout << "\nProcess Name: " << name << std::endl;
             std::cout << "Instruction Line: " << console.getCurrLine() << "/" << console.getTotalLines() << std::endl;
            std::cout << "creation time: " << console.getTimestamp() << std::endl;
            std::cout << "=====================================================" << std::endl;

            return;
        }
    }
    // does not exist
    std::cout << "console: " << name << " does not exist." << std::endl;
}

void ConsoleManager::consoleExit() {
    bool running = true;
    std::string input;

    while (running) {
        input.clear();
        std::cout << "Enter a command: ";
        std::cin >> input;

        if (input == "exit") {
            running = false;
        }
        else {
            std::cout << "command not recognized. Type \'exit\' to leave this view" << std::endl;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("cls");
}