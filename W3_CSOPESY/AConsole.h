
#ifndef ACONSOLE_H
#define ACONSOLE_H

#include <string>
#include <ctime>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>

struct Details {
    int core_id;
    std::string timestamp;
    int curr_line;
};

using namespace std;


class AConsole {
private:
    std::string name;
    std::string timestamp;
    int console_id;
    int core_id;
    int currLine;
    int totalLines;
    bool ongoing;
    std::map<std::string, std::vector<Details>> history;



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
    void saveProcess(string name, int line, int core_id);
    void print() const;

    const map<std::string, std::vector<Details>>& getHistory() const;

    
    private:
    static std::string getCurrentTime();
    
};

#endif //ACONSOLE_H
