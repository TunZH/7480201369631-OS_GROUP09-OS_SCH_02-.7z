#ifndef CSV_READER_H
#define CSV_READER_H

#include <vector>
#include <string>

namespace utils {
    std::vector<std::vector<std::string>> readCSV(const std::string& filename);
}

#endif
