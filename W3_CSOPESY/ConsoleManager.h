#ifndef CONSOLEMANAGER_H
#define CONSOLEMANAGER_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <mutex>

#include "AConsole.h"

using namespace std;

class ConsoleManager {
private:
    map<string, AConsole*> consoles;
    int last_process_number = 0;
    mutex consoleMutex;


    bool currentConsole = false;

public:
    void addConsole(const std::string& name);
    void createProcesses();
    bool findConsole(const std::string& name) const;
    void viewConsole(const std::string& name) const;
    
    void initScheduler();
    void listConsoles();
    void getHistory(string name);





    void consoleExit(string name);
};

#endif // CONSOLEMANAGER_H
