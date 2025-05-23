#include <string>
#include <ctime>
#include <iostream>
#include "AConsole.h"


/*
* This constructor instantiates a new console given its name, current instruction line, and instruction total
* 
* @param name - the name of the console
* @param currLine - the current instruction line number
* @param totalLines - the total number of instructions
*/
AConsole::AConsole(const std::string& name, const int currLine, const int totalLines)
    : name(name), currLine(currLine), totalLines(totalLines), timestamp(getCurrentTime()) {}

/*
* This function returns the name of the console
* 
* @return name - the name of the console
*/
std::string AConsole::getName() const {
    return name;
}

/*
* This function returns the timestamp when the console was created
* 
* @return timestamp - the timestamp when the console was created
*/
std::string AConsole::getTimestamp() const {
    return timestamp;
}

/*
* This function returns the current instruction line number
* 
* @return currLine - the current instruction line number
*/
int AConsole::getCurrLine() const {
    return currLine;
}

/*
* This function returns the total number of instructions
* 
* @return totalLines - the total number of instructions
*/
int AConsole::getTotalLines() const {
    return totalLines;
}

/*
* This function returns the current time in the format (MM/DD/YYYY HH:MM:SS AM/PM)
* 
* @return buffer - the current time in the format (MM/DD/YYYY HH:MM:SS AM/PM)
*/
std::string AConsole::getCurrentTime() {
    std::time_t now = std::time(0);
    std::tm localTime;
    localtime_s(&localTime, &now);
    char buffer[50];
    std::strftime(buffer, sizeof(buffer), "(%m/%d/%Y %H:%M:%S %p)", &localTime);
    return buffer;
}