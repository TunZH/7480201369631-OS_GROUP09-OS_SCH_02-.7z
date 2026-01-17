#include "memory/fifo.h"
#include <queue>
#include <algorithm>

FIFOResult fifoPageReplacement(
    const std::vector<int>& pages,
    int frameCount
) {
    FIFOResult result;
    result.pageFaults = 0;

    std::vector<int> frames(frameCount, -1);
    std::queue<int> q;

    for (int page : pages) {
        bool hit = false;

        for (int f : frames) {
            if (f == page) {
                hit = true;
                break;
            }
        }

        if (!hit) {
            result.pageFaults++;

            if (q.size() == frameCount) {
                int victim = q.front();
                q.pop();
                for (int& f : frames) {
                    if (f == victim) {
                        f = page;
                        break;
                    }
                }
            } else {
                for (int& f : frames) {
                    if (f == -1) {
                        f = page;
                        break;
                    }
                }
            }
            q.push(page);
            result.pageFaultAtStep.push_back(true);
        } else {
            result.pageFaultAtStep.push_back(false);
        }

        result.framesHistory.push_back(frames);
    }

    return result;
}
