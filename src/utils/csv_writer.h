#ifndef CSV_WRITER_H
#define CSV_WRITER_H

#include <vector>
#include <string>

namespace utils {
    void writeCSV(
        const std::string& filename,
        const std::vector<std::string>& header,
        const std::vector<std::vector<std::string>>& data
    );
}

#endif
