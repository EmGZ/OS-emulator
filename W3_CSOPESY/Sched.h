#ifndef SCHED_H
#define SCHED_H


#include <thread>
#include <vector>
#include <map>
#include <queue>
#include <mutex>
#include "AConsole.h"

using namespace std;

class Sched {
private:
    static Sched* instance;
    vector<bool> available_cpu;
    queue<AConsole*> waitingQueue;         
    map<string, thread> runningProcesses;
    string scheduler;
    int available_core_count;
    int delayPerExec;

    std::mutex processMutex;                

    Sched(); // constructor


public:
    static Sched& getInstance(); // singleton
    void enqueue_process(AConsole* console);
    void start_scheduler();
    void fcfs_algo();
    int get_available_cores();
};

#endif