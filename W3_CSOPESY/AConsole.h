#ifndef ACONSOLE_H
#define ACONSOLE_H

#include <string>
#include <ctime>
#include <vector>
#include <iostream>

class AConsole {
private:
    std::string name;
    std::string timestamp;
    int currLine;
    int totalLines;

public:
    AConsole(const std::string& name, int currLine, int totalLines);

    std::string getName() const;
    std::string getTimestamp() const;
    int getCurrLine() const;
    int getTotalLines() const;

private:
    static std::string getCurrentTime();
};

#endif // ACONSOLE_H
