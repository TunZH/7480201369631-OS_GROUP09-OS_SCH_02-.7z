#ifndef LRU_H
#define LRU_H

#include <vector>

struct LRUResult {
    int pageFaults;
    std::vector<std::vector<int>> framesHistory;
    std::vector<bool> pageFaultAtStep;
};

LRUResult lruPageReplacement(
    const std::vector<int>& pages,
    int frameCount
);

#endif
