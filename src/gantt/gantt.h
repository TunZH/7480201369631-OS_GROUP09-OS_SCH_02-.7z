#ifndef GANTT_H
#define GANTT_H

#include <string>
#include <vector>

struct GanttBlock {
    std::string pid;
    int startTime;
    int endTime;
};

void drawGanttChart(const std::vector<GanttBlock>& gantt);

#endif
