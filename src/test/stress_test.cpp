#include "test/stress_test.h"
#include <vector>
#include <chrono>
#include <iostream>

#include "cpu/process.h"
#include "cpu/fcfs.h"
#include "cpu/priority.h"
#include "memory/fifo.h"
#include "memory/lru.h"
#include "utils/csv_writer.h"

using namespace std;
using namespace std::chrono;

void runStressTest() {
    vector<vector<string>> result;
    vector<string> header = {
        "Algorithm", "DataSize", "Time_ms", "Extra"
    };

    /* ================= CPU FCFS ================= */
    {
        vector<Process> processes;
        int n = 10000;

        for (int i = 0; i < n; i++) {
            Process p;
            p.pid = "P" + to_string(i);
            p.arrivalTime = i % 50;
            p.burstTime = (i % 10) + 1;
            processes.push_back(p);
        }

        auto start = high_resolution_clock::now();
        fcfsScheduling(processes);
        auto end = high_resolution_clock::now();

        long long timeMs = duration_cast<milliseconds>(end - start).count();

        result.push_back({
            "FCFS", to_string(n), to_string(timeMs), "-"
        });
    }

    /* ================= CPU Priority ================= */
    {
        vector<Process> processes;
        int n = 10000;

        for (int i = 0; i < n; i++) {
            Process p;
            p.pid = "P" + to_string(i);
            p.arrivalTime = i % 50;
            p.burstTime = (i % 10) + 1;
            p.priority = i % 5;
            processes.push_back(p);
        }

        auto start = high_resolution_clock::now();
        priorityScheduling(processes);
        auto end = high_resolution_clock::now();

        long long timeMs = duration_cast<milliseconds>(end - start).count();

        result.push_back({
            "Priority", to_string(n), to_string(timeMs), "-"
        });
    }

    /* ================= Memory FIFO ================= */
    {
        vector<int> pages;
        int n = 100000;
        int frames = 10;

        for (int i = 0; i < n; i++)
            pages.push_back(i % 20);

        auto start = high_resolution_clock::now();
        fifoPageReplacement(pages, frames);
        auto end = high_resolution_clock::now();

        long long timeMs = duration_cast<milliseconds>(end - start).count();

        result.push_back({
            "FIFO", to_string(n), to_string(timeMs), "frames=10"
        });
    }

    /* ================= Memory LRU ================= */
    {
        vector<int> pages;
        int n = 100000;
        int frames = 10;

        for (int i = 0; i < n; i++)
            pages.push_back(i % 20);

        auto start = high_resolution_clock::now();
        lruPageReplacement(pages, frames);
        auto end = high_resolution_clock::now();

        long long timeMs = duration_cast<milliseconds>(end - start).count();

        result.push_back({
            "LRU", to_string(n), to_string(timeMs), "frames=10"
        });
    }

    utils::writeCSV("output/performance_test.csv", header, result);
    cout << "Stress test completed\n";
}
