#ifndef CONSOLEMANAGER_H
#define CONSOLEMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include "AConsole.h"

class ConsoleManager {
private:
    std::vector<AConsole> consoles;
    bool currentConsole = false;

public:
    void addConsole(const std::string& name);
    bool findConsole(const std::string& name) const;
    void viewConsole(const std::string& name) const;
    
    static void consoleExit();
};

#endif // CONSOLEMANAGER_H
