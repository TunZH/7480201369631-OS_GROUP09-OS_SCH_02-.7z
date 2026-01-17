#include "memory/lru.h"
#include <algorithm>

LRUResult lruPageReplacement(
    const std::vector<int>& pages,
    int frameCount
) {
    LRUResult result;
    result.pageFaults = 0;

    std::vector<int> frames(frameCount, -1);
    std::vector<int> lastUsed(frameCount, -1);

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];
        bool hit = false;

        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == page) {
                hit = true;
                lastUsed[j] = i;
                break;
            }
        }

        if (!hit) {
            result.pageFaults++;

            int idx = -1;
            for (int j = 0; j < frameCount; j++) {
                if (frames[j] == -1) {
                    idx = j;
                    break;
                }
            }

            if (idx == -1) {
                idx = std::min_element(
                    lastUsed.begin(),
                    lastUsed.end()
                ) - lastUsed.begin();
            }

            frames[idx] = page;
            lastUsed[idx] = i;
            result.pageFaultAtStep.push_back(true);
        } else {
            result.pageFaultAtStep.push_back(false);
        }

        result.framesHistory.push_back(frames);
    }

    return result;
}
