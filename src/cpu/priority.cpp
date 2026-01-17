#include "cpu/priority.h"
#include <limits>

std::vector<Process> priorityScheduling(std::vector<Process> processes) {
    int n = processes.size();
    int currentTime = 0;
    int completed = 0;
    std::vector<bool> done(n, false);

    while (completed < n) {
        int idx = -1;
        int bestPriority = std::numeric_limits<int>::max();

        for (int i = 0; i < n; i++) {
            if (!done[i] && processes[i].arrivalTime <= currentTime) {
                if (processes[i].priority < bestPriority) {
                    bestPriority = processes[i].priority;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            currentTime++;
            continue;
        }

        processes[idx].startTime = currentTime;
        processes[idx].completionTime =
            currentTime + processes[idx].burstTime;
        processes[idx].turnaroundTime =
            processes[idx].completionTime - processes[idx].arrivalTime;
        processes[idx].waitingTime =
            processes[idx].turnaroundTime - processes[idx].burstTime;

        currentTime = processes[idx].completionTime;
        done[idx] = true;
        completed++;
    }

    return processes;
}
