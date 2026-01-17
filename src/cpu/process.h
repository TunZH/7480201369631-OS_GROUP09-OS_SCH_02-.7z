#ifndef PROCESS_H
#define PROCESS_H

#include <string>

struct Process {
    std::string pid;

    int arrivalTime;
    int burstTime;
    int priority;        
    int startTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

#endif

