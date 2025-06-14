#include <string>
#include <ctime>
#include <iostream>
#include "AConsole.h"
#include <chrono>
#include <thread>
#include <iostream>



AConsole::AConsole(const std::string& name, const int currLine)
    : name(name), currLine(currLine), ongoing(true), status(WAITING), core_id(-1), timestamp(getCurrentTime()) {}

std::string AConsole::getName() const {
    return name;
}


std::string AConsole::getTimestamp() const {
    return timestamp;
}

int AConsole::getCurrLine() const {
    return currLine;
}


int AConsole::getTotalLines() const {
    return totalLines;
}

int AConsole::getCoreNum() {
    return core_id;
}

void AConsole::setTotalLines(int maxLines) {
    totalLines = maxLines;
}

void AConsole::setConsoleID(int consoleID){
    console_id = consoleID;
}

int AConsole::getConsoleID() {
    return console_id;
}


AConsole::Status AConsole::getStatus() {
    return status;
}

void AConsole::setStatus(AConsole::Status newStatus) {
    status = newStatus;
}


std::string AConsole::getCurrentTime() {
    std::time_t now = std::time(0);
    std::tm localTime;
    localtime_s(&localTime, &now);
    char buffer[50];
    std::strftime(buffer, sizeof(buffer), "(%m/%d/%Y %H:%M:%S %p)", &localTime);
    return buffer;
}


void AConsole::runProcess(int coreID, int quantum_cycles, int delayPEX) {
    core_id = coreID;
    status = RUNNING;
    
    int finishedLine = 0;

    while (ongoing && currLine < totalLines){
        if (delayPEX > 0) {
            for (int delay = 0; delay < delayPEX; delay++){
                //busy-waiting
            }
        }

        if (quantum_cycles > 0 && finishedLine >= quantum_cycles) {
            status = WAITING;
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        currLine++;
        finishedLine++;
    }

    if (currLine == totalLines) {
        status = TERMINATED;
    }
}





// #include <string>
// #include <ctime>
// #include <iostream>
// #include "AConsole.h"


// /*
// * This constructor instantiates a new console given its name, current instruction line, and instruction total
// * 
// * @param name - the name of the console
// * @param currLine - the current instruction line number
// * @param totalLines - the total number of instructions
// */
// AConsole::AConsole(const std::string& name, const int currLine, const int totalLines)
//     : name(name), currLine(currLine), totalLines(totalLines), timestamp(getCurrentTime()) {}

// /*
// * This function returns the name of the console
// * 
// * @return name - the name of the console
// */
// std::string AConsole::getName() const {
//     return name;
// }

// /*
// * This function returns the timestamp when the console was created
// * 
// * @return timestamp - the timestamp when the console was created
// */
// std::string AConsole::getTimestamp() const {
//     return timestamp;
// }

// /*
// * This function returns the current instruction line number
// * 
// * @return currLine - the current instruction line number
// */
// int AConsole::getCurrLine() const {
//     return currLine;
// }

// /*
// * This function returns the total number of instructions
// * 
// * @return totalLines - the total number of instructions
// */
// int AConsole::getTotalLines() const {
//     return totalLines;
// }

// /*
// * This function returns the current time in the format (MM/DD/YYYY HH:MM:SS AM/PM)
// * 
// * @return buffer - the current time in the format (MM/DD/YYYY HH:MM:SS AM/PM)
// */
// std::string AConsole::getCurrentTime() {
//     std::time_t now = std::time(0);
//     std::tm localTime;
//     localtime_s(&localTime, &now);
//     char buffer[50];
//     std::strftime(buffer, sizeof(buffer), "(%m/%d/%Y %H:%M:%S %p)", &localTime);
//     return buffer;
// }