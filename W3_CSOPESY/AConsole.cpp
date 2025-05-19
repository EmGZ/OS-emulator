#include <string>
#include <ctime>
#include <iostream>
#include "AConsole.h"


AConsole::AConsole(const std::string& name, const int currLine, const int totalLines)
    : name(name), currLine(currLine), totalLines(totalLines), timestamp(getCurrentTime()) {}

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

std::string AConsole::getCurrentTime() {
    std::time_t now = std::time(0);
    std::tm localTime;
    localtime_s(&localTime, &now);
    char buffer[50];
    std::strftime(buffer, sizeof(buffer), "(%m/%d/%Y %H:%M:%S %p)", &localTime);
    return buffer;
}