#include "decompressor.h"

std::string decompressRLE(const std::string& data) {
    std::string result;
    for (size_t i = 0; i + 1 < data.size(); i += 2) {
        char ch = data[i];
        unsigned char count = static_cast<unsigned char>(data[i + 1]);
        result.append(count, ch);
    }
    return result;
}
