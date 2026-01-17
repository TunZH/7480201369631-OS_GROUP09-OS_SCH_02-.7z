#include "gantt/gantt.h"
#include <iostream>

void drawGanttChart(const std::vector<GanttBlock>& gantt) {
    std::cout << "\n===== GANTT CHART =====\n";
    for (auto& g : gantt) {
        std::cout << "| " << g.pid << " ";
    }
    std::cout << "|\n";

    for (auto& g : gantt) {
        std::cout << g.startTime << "    ";
    }
    std::cout << gantt.back().endTime << "\n";
}
