#ifndef FIFO_H
#define FIFO_H

#include <vector>

struct FIFOResult {
    int pageFaults;
    std::vector<std::vector<int>> framesHistory;
    std::vector<bool> pageFaultAtStep;
};

FIFOResult fifoPageReplacement(
    const std::vector<int>& pages,
    int frameCount
);

#endif
