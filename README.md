# CPU Scheduling & Memory Management Simulator

## 1. Introduction
This project is a console-based application developed for the Operating System course.
The main purpose of this project is to simulate fundamental CPU scheduling algorithms
and memory management techniques, helping students better understand how operating
systems allocate CPU time and manage memory resources.

The application is implemented in C++ and is designed to run on Windows without any
runtime errors or exceptions. All input data is provided via CSV files, and the program
exports detailed results to CSV files for analysis and reporting.

---

## 2. Features

### 2.1 CPU Scheduling Algorithms
The following CPU scheduling algorithms are implemented:
- First Come First Serve (FCFS)
- Non-preemptive Priority Scheduling

For each algorithm, the program calculates:
- Start Time (ST)
- Completion Time (CT)
- Waiting Time (WT)
- Turnaround Time (TAT)

The results are displayed on the console and exported to CSV files.

---

### 2.2 Memory Management Algorithms
The following page replacement algorithms are implemented:
- FIFO (First In First Out)
- LRU (Least Recently Used)

For each algorithm, the program:
- Simulates page replacement step by step
- Counts the number of page faults
- Records the frame status at each step

Detailed results are exported to CSV files for further inspection.

---

### 2.3 Gantt Chart Visualization
The program generates a Gantt Chart to visualize the CPU execution timeline.
The Gantt Chart shows:
- Process ID
- Start Time
- End Time

This helps verify the correctness of CPU scheduling algorithms by comparing the
execution order with textbook examples.

---

### 2.4 Stress Test and Performance Test
To evaluate performance, the project includes:
- Stress tests with large input sizes
- Execution time measurement for each algorithm

The execution time is measured in milliseconds and exported to a CSV file for
comparison and chart visualization.

---

## 3. Project Structure

src/
├── cpu/
│ ├── fcfs.h
│ ├── fcfs.cpp
│ ├── priority.h
│ └── priority.cpp
│
├── memory/
│ ├── fifo.h
│ ├── fifo.cpp
│ ├── lru.h
│ └── lru.cpp
│
├── gantt/
│ ├── gantt.h
│ └── gantt.cpp
│
├── utils/
│ ├── csv_reader.h
│ ├── csv_reader.cpp
│ ├── csv_writer.h
│ └── csv_writer.cpp
│
├── test/
│ ├── stress_test.h
│ └── stress_test.cpp
│
└── main.cpp

yaml
Copy code

---

## 4. Input Files
All input data is provided in CSV format.

- input/cpu_processes.csv  
  Contains process information for CPU scheduling.

- input/memory_pages.csv  
  Contains page reference strings for memory management simulation.

---

## 5. Output Files
The program exports detailed results to the output folder:

- output/fcfs_result.csv
- output/priority_result.csv
- output/memory_fifo_result.csv
- output/memory_lru_result.csv
- output/gantt_chart.csv
- output/performance_test.csv

These files can be opened using Excel to verify correctness and generate charts.

---

## 6. How to Build and Run (Windows)
### Compile
```bash
g++ src/main.cpp src/cpu/fcfs.cpp src/cpu/priority.cpp src/memory/fifo.cpp src/memory/lru.cpp src/gantt/gantt.cpp src/test/stress_test.cpp src/utils/csv_reader.cpp src/utils/csv_writer.cpp -I./src -o build/app.exe
Run
Copy code
./build/app.exe
7. Stress Test and Performance Evaluation
Stress tests are performed using large datasets to evaluate the execution time
of each algorithm. The results demonstrate the performance differences between
CPU scheduling and memory management techniques.

All performance data is exported to performance_test.csv and visualized using charts
in the final report.

8. Conclusion
This project successfully demonstrates the implementation of CPU scheduling and
memory management algorithms. Through simulation, CSV-based input/output, Gantt
Chart visualization, and performance testing, the project provides a clear and
practical understanding of Operating System concepts.

9. Authors
Group 09 – Operating System Course
All members contributed to different modules including CPU scheduling, memory
management, visualization, and testing.