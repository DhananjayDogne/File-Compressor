#include "compressor.h"

std::string compressRLE(const std::string& data) {
    std::string result;
    int n = data.size();
    for (int i = 0; i < n; ) {
        char current = data[i];
        int count = 1;
        while (i + count < n && data[i + count] == current && count < 255) {
            count++;
        }
        result += current;
        result += static_cast<char>(count);
        i += count;
    }
    return result;
}
