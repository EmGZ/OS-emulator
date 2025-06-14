
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
    int console_id;
    int core_id;
    int currLine;
    int totalLines;
    bool ongoing;

public:
    AConsole(const std::string& name, int currLine = 0);

    enum Status { RUNNING, WAITING, TERMINATED };
    Status status;

    std::string getName() const;
    std::string getTimestamp() const;
    int getCurrLine() const;
    int getTotalLines() const;
    int getCoreNum();
    int getConsoleID();
    Status getStatus();
    
    void setTotalLines(int maxLines);
    void setConsoleID(int consoleID);
    void setStatus(AConsole::Status newStatus);
    
    void runProcess(int coreID, int quantum_cycles, int delaysPerExec);
    
    private:
    static std::string getCurrentTime();
};

#endif //ACONSOLE_H
