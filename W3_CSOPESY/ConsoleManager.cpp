#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "ConsoleManager.h"
#include "Sched.h"


Sched* scheduler = nullptr;  //sched

/*
* This function adds a new console to the list of consoles
* 
* @param name - the name of the console
*/
void ConsoleManager::addConsole(const std::string& name) {

     // check if name exists
     if (consoles.count(name) > 0) {
        cout << "console: " << name << " is already in use" << std::endl;
        return;
    }
    
    AConsole* newConsole = new AConsole(name);
    newConsole->setTotalLines(100);

    // add to list of consoles
    consoles[name] =  newConsole;

    // push to waiting queue
    scheduler->enqueue_process(newConsole); 
   

}


void ConsoleManager::createProcesses() {
    int i = 0;
    for (i; i < 10; i++){

        std::string name = "P" + std::to_string(i);
        AConsole* newConsole = new AConsole(name);
        newConsole->setTotalLines(100);

        static int nextId = 1;
        int console_id = nextId++; 
        newConsole->setConsoleID(console_id);

        // add to list of consoles
        consoles[name] =  newConsole;

        // push to waiting queue
        scheduler->enqueue_process(newConsole); 
    }   

    std::cout << " 10 Processes created" << endl;

}


void ConsoleManager::listConsoles(){
    std::lock_guard<std::mutex> lock(consoleMutex);
    int cores = 4;
    int cores_used = cores - scheduler->get_available_cores();
    int cores_available = scheduler->get_available_cores();

    float cpuUsage = 0.0;
	if (4 > 0) {
		cpuUsage = (cores_used / (float) cores) * 100;
	}

    cout << "\n\n\n+-----+-------------------------------------------------------------------------------------+"<< endl;
    cout << "CPU Utilization: " <<  cpuUsage <<  "%" << endl;
    cout << "Cores Used: " << cores_used << endl;
    cout << "Cores Available: " << cores_available << endl;
    cout << "---------------------------------------------------------------------------------------------"<< endl;
    
    
    if (consoles.empty()) {
        cout << "No processes to list" << endl;
    } else {
        
        cout << "Running Processes: "<< endl;
        for (const auto& console : consoles) {
            if (console.second->status == AConsole::RUNNING){
                std::cout << console.second->getName() << "\t" << console.second->getTimestamp() << "\tCore: " <<
                console.second->getCoreNum() << "\t" << console.second->getCurrLine() << "/" << console.second->getTotalLines() << std::endl;
            }
        } 
        cout << "\n\nFinished Processes: "<< endl;
        for (const auto& console : consoles) {
            if (console.second->status == AConsole::TERMINATED){
                std::cout << console.second->getName() << "\t" << console.second->getTimestamp() << "\tFINISHED " 
                << "\t" << console.second->getCurrLine() << "/" << console.second->getTotalLines() << std::endl;
            }
        }
    }
    cout << "+-----+-------------------------------------------------------------------------------------+\n\n\n"<< endl;


}



/*
* This function checks if the specified console exists
* 
* @param name - the name of the console
* @return true if the console exists, false otherwise
*/
bool ConsoleManager::findConsole(const std::string& name) const {
    if (consoles.count(name) > 0) {
        return true;
    }
    // console not yet created
    return false;
}

/*
* This function displays the information of the specified console
* 
* @param name - the name of the console
*/
void ConsoleManager::viewConsole(const std::string& name) const {
    auto it = consoles.find(name);
    if (it != consoles.end()) {
        AConsole* console = it->second;

        system("cls"); // cleans screen, as if entering new screen

        std::cout << "=====================================================";
        std::cout << "\nProcess Name: " << name << std::endl;
        std::cout << "Console ID: " << console->getConsoleID() << std::endl;
        std::cout << "Instruction Line: " << console->getCurrLine() << "/" << console->getTotalLines() << std::endl;
        std::cout << "creation time: " << console->getTimestamp() << std::endl;
        std::cout << "=====================================================" << std::endl;

        return;
    }
    // does not exist
    std::cout << "console: " << name << " does not exist." << std::endl;
}

/*
* This function waits for user input until "exit" is entered
*/
void ConsoleManager::consoleExit(string name) {
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
        } else if (input == "print"){
            getHistory(name);
        }
        else {
            std::cout << "Command not recognized. Type \'exit\' to leave this screen" << std::endl;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system("cls");
}

void ConsoleManager::initScheduler(){
    scheduler = &Sched::getInstance();
    scheduler->start_scheduler();
}

void ConsoleManager::getHistory(std::string name) {
    auto it = consoles.find(name);
    if (it != consoles.end()) {
        AConsole* console = it->second;
        console->print(); 
    } else {
        std::cout << "No history found for process: " << name << "\n";
    }
}