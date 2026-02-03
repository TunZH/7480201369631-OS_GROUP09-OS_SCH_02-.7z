#include <iostream>
#include <vector>
#include <string>

#include "utils/csv_reader.h"
#include "utils/csv_writer.h"

#include "cpu/process.h"
#include "cpu/fcfs.h"
#include "cpu/priority.h"

#include "memory/fifo.h"
#include "memory/lru.h"

#include "gantt/gantt.h"
#include "test/stress_test.h"

using namespace std;

void printLine() {
    cout << "--------------------------------------------------\n";
}

int main() {

    cout << "\nCPU SCHEDULING & MEMORY MANAGEMENT SIMULATOR\n";
    printLine();

    /* ================= CPU INPUT ================= */
    auto cpuCSV = utils::readCSV("input/cpu_processes.csv");

    vector<Process> processes;
    for (size_t i = 1; i < cpuCSV.size(); i++) {
        Process p;
        p.pid = cpuCSV[i][0];
        p.arrivalTime = stoi(cpuCSV[i][1]);
        p.burstTime = stoi(cpuCSV[i][2]);
        p.priority = stoi(cpuCSV[i][3]);
        processes.push_back(p);
    }

    cout << "\nCPU INPUT PROCESSES:\n";
    cout << "PID  AT  BT  PR\n";
    for (auto &p : processes) {
        cout << p.pid << "   "
             << p.arrivalTime << "   "
             << p.burstTime << "   "
             << p.priority << "\n";
    }

    /* ================= FCFS ================= */
    printLine();
    cout << "FCFS SCHEDULING RESULT\n";

    auto fcfsResult = fcfsScheduling(processes);

    cout << "PID  ST  CT  WT  TAT\n";
    for (auto& p : fcfsResult) {
        cout << p.pid << "   "
             << p.startTime << "   "
             << p.completionTime << "   "
             << p.waitingTime << "   "
             << p.turnaroundTime << "\n";
    }

    /* ================= PRIORITY ================= */
    printLine();
    cout << "PRIORITY SCHEDULING RESULT\n";

    auto prResult = priorityScheduling(processes);

    cout << "PID  PR  ST  CT  WT  TAT\n";
    for (auto& p : prResult) {
        cout << p.pid << "   "
             << p.priority << "   "
             << p.startTime << "   "
             << p.completionTime << "   "
             << p.waitingTime << "   "
             << p.turnaroundTime << "\n";
    }

    /* ================= MEMORY INPUT ================= */
    printLine();
    cout << "MEMORY PAGE INPUT\n";

    auto memCSV = utils::readCSV("input/memory_pages.csv");
    vector<int> pages;
    for (size_t i = 1; i < memCSV.size(); i++) {
        pages.push_back(stoi(memCSV[i][0]));
        cout << memCSV[i][0] << " ";
    }
    cout << "\n";

    int frames = 3;

    /* ================= FIFO ================= */
    printLine();
    cout << "FIFO PAGE REPLACEMENT\n";

    FIFOResult fifoRes = fifoPageReplacement(pages, frames);

    for (size_t i = 0; i < fifoRes.framesHistory.size(); i++) {
        cout << "Step " << i + 1 << " | Page " << pages[i] << " | ";
        for (int f : fifoRes.framesHistory[i])
            cout << (f == -1 ? "-" : to_string(f)) << " ";
        cout << "| Fault: " << (fifoRes.pageFaultAtStep[i] ? "Yes" : "No") << "\n";
    }

    /* ================= LRU ================= */
    printLine();
    cout << "LRU PAGE REPLACEMENT\n";

    LRUResult lruRes = lruPageReplacement(pages, frames);

    for (size_t i = 0; i < lruRes.framesHistory.size(); i++) {
        cout << "Step " << i + 1 << " | Page " << pages[i] << " | ";
        for (int f : lruRes.framesHistory[i])
            cout << (f == -1 ? "-" : to_string(f)) << " ";
        cout << "| Fault: " << (lruRes.pageFaultAtStep[i] ? "Yes" : "No") << "\n";
    }

    /* ================= GANTT ================= */
    printLine();
    cout << "GANTT CHART (FCFS)\n";

    vector<GanttBlock> gantt;
    for (auto& p : fcfsResult) {
        gantt.push_back({p.pid, p.startTime, p.completionTime});
    }
    drawGanttChart(gantt);

    /* ================= STRESS TEST ================= */
    printLine();
    cout << "RUNNING STRESS TEST...\n";
    runStressTest();

    printLine();
    cout << "ALL MODULES RUN SUCCESSFULLY\n";
    return 0;
}
