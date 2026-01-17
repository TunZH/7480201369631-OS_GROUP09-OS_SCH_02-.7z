#include "cpu/fcfs.h"
#include <algorithm>

std::vector<Process> fcfsScheduling(std::vector<Process> processes) {
    std::sort(processes.begin(), processes.end(),
        [](Process a, Process b) {
            return a.arrivalTime < b.arrivalTime;
        });

    int currentTime = 0;

    for (auto& p : processes) {
        if (currentTime < p.arrivalTime)
            currentTime = p.arrivalTime;

        p.startTime = currentTime;
        p.completionTime = p.startTime + p.burstTime;
        p.turnaroundTime = p.completionTime - p.arrivalTime;
        p.waitingTime = p.turnaroundTime - p.burstTime;

        currentTime = p.completionTime;
    }

    return processes;
}
