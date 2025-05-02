#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
#include <string>
#include "compressor.h"

const int THREAD_COUNT = 4;
const size_t CHUNK_SIZE = 1024 * 1024; // 1 MB

std::mutex output_mutex;
std::vector<std::string> compressed_chunks;

void compress_chunk(const std::string& chunk, int index) {
    std::string result = compressRLE(chunk);
    std::lock_guard<std::mutex> lock(output_mutex);
    compressed_chunks[index] = result;
}

int main() {
    std::ifstream in("input.txt", std::ios::binary);
    if (!in) {
        std::cerr << "Cannot open input.txt\n";
        return 1;
    }

    std::vector<std::thread> threads;
    std::vector<std::string> chunks;
    compressed_chunks.clear();

    // Read file into chunks
    while (!in.eof()) {
        std::string buffer(CHUNK_SIZE, '\0');
        in.read(&buffer[0], CHUNK_SIZE);
        buffer.resize(in.gcount());
        chunks.push_back(buffer);
    }

    compressed_chunks.resize(chunks.size());

    // Spawn threads to compress each chunk
    for (size_t i = 0; i < chunks.size(); ++i) {
        threads.emplace_back(compress_chunk, std::ref(chunks[i]), i);
    }

    for (auto& t : threads) t.join();

    // Write to output file
    std::ofstream out("output.rle", std::ios::binary);
    for (const auto& part : compressed_chunks) {
        out.write(part.data(), part.size());
    }

    std::cout << "Compression complete.\n";
    return 0;
}
