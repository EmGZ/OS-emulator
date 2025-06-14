// Scheduler.cpp
#include "Sched.h"
#include <iostream>
#include <mutex>
#include <algorithm>


Sched* Sched::instance = nullptr;


Sched::Sched() {
    
    // initialize values at creation
    available_cpu = vector<bool>(4, true); // create n vectors of cpu
    available_core_count = 4;   
    delayPerExec = 1;          
    scheduler = "fcfs";      
}

Sched& Sched::getInstance() {
    if (instance == nullptr) {
        instance = new Sched();
    }
    return *instance;
}


void Sched::start_scheduler(){
    if (scheduler == "fcfs"){
        thread FCFS_SCHED(&Sched::fcfs_algo, this);
        FCFS_SCHED.detach();
    }
}

void Sched::enqueue_process(AConsole* process){
    waitingQueue.push(process);
}

void Sched::fcfs_algo(){
    while (true){
        this_thread::sleep_for(chrono::milliseconds(1));

        for (int i = 0; i < available_cpu.size(); ++i) {
            std::lock_guard<std::mutex> lock(processMutex);

            if (available_cpu[i] && !waitingQueue.empty()){
                AConsole* nextConsole = waitingQueue.front();
                waitingQueue.pop();

                available_cpu[i] = false;
                available_core_count--;

                runningProcesses[nextConsole->getName()] = std::thread([this, nextConsole, i]() {
                    nextConsole->runProcess(i, 0, delayPerExec);
                    
                    std::lock_guard<std::mutex> lock(processMutex);
                    available_cpu[i] = true;
                    available_core_count++;
                });
            }
        }
    }
}

int Sched::get_available_cores(){
    int availableCount = std::count(available_cpu.begin(), available_cpu.end(), true);
    return availableCount;
}


