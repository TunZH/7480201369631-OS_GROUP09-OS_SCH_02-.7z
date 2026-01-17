#include <iostream>

// CPU scheduling
#include "cpu/fcfs.h"
#include "cpu/priority.h"

// Memory
#include "memory/fifo.h"
#include "memory/lru.h"

// Stress test
#include "test/stress_test.h"

using namespace std;

int main() {
    cout << "===== CPU SCHEDULING SIMULATOR =====\n\n";

    /* ================= FCFS ================= */
    cout << "[1] Running FCFS Scheduling...\n";
    runFCFS(
        "input/cpu_processes.csv",
        "output/fcfs_result.csv",
        "output/gantt_fcfs.csv"
    );
    cout << "-> FCFS completed\n\n";

    /* =============== PRIORITY =============== */
    cout << "[2] Running Priority Scheduling...\n";
    runPriority(
        "input/priority_processes.csv",
        "output/priority_result.csv",
        "output/gantt_priority.csv"
    );
    cout << "-> Priority completed\n\n";

    /* ================ FIFO ================== */
    cout << "[3] Running Memory FIFO...\n";
    runFIFO(
        "input/memory_pages.csv",
        "output/memory_fifo.csv"
    );
    cout << "-> FIFO completed\n\n";

    /* ================= LRU ================== */
    cout << "[4] Running Memory LRU...\n";
    runLRU(
        "input/memory_pages.csv",
        "output/memory_lru.csv"
    );
    cout << "-> LRU completed\n\n";

    /* ========= STRESS & PERFORMANCE ========= */
    cout << "[5] Running Stress & Performance Test...\n";
    runStressTest(
        "output/performance_test.csv"
    );
    cout << "-> Stress test completed\n\n";

    cout << "===== FINISHED SUCCESSFULLY =====\n";
    return 0;
}
