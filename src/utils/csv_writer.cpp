#include "csv_writer.h"
#include <fstream>

namespace utils {

void writeCSV(
    const std::string& filename,
    const std::vector<std::string>& header,
    const std::vector<std::vector<std::string>>& data
) {
    std::ofstream file(filename);

    for (size_t i = 0; i < header.size(); i++) {
        file << header[i];
        if (i != header.size() - 1) file << ",";
    }
    file << "\n";

    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); i++) {
            file << row[i];
            if (i != row.size() - 1) file << ",";
        }
        file << "\n";
    }
}

}

