# 🚀 Multithreaded File Compressor (C++)

A simple multithreaded file compressor using Run-Length Encoding (RLE), written in modern C++ (C++11). This tool compresses large files by dividing them into chunks and processing each chunk in parallel using threads.

---

## ✨ Features

- 📦 Compresses large files using **Run-Length Encoding (RLE)**
- 🚀 Uses **multiple threads** for faster processing
- 🧵 Thread-safe buffer access via `std::mutex`
- 🔄 Includes decompression support via `--decompress` flag
- 💡 Clean, modular codebase using modern C++11
- 🔗 No external libraries required

---

## 🔧 Usage

### 🛠 Compile

Using `make`:

```bash
make


```
### Or compile manually:
  
  ```bash
  g++ -std=c++11 -pthread main.cpp compressor.cpp decompressor.cpp -o compressor
```
### 📥 Run Compression
```bash
./compressor
```
Input: input.txt (place this file in the same directory)

Output: output.rle (compressed result)

### 📤 Run Decompression
```bash

./compressor --decompress
```
Input: output.rle

Output: decompressed.txt

## ⚙️ How It Works
The input file is read and split into equal-sized chunks

Each chunk is passed to a thread for compression using Run-Length Encoding

Threads store results in a shared vector, protected with a mutex

The compressed data is written sequentially to a single output file

The decompression process reverses the RLE encoding and writes the full file back

## 📁 File Structure
``` bash
file_compressor/
├── main.cpp
├── compressor.cpp
├── compressor.h
├── decompressor.cpp
├── decompressor.h
├── Makefile (optional)
├── input.txt (your input file)
├── output.rle (generated after compression)
├── decompressed.txt (generated after decompression)
└── README.md
```

## 🧪 Example
Given an input.txt file containing:
``` bash
aaaaabbbccddddd
```

After compression and decompression, the content of decompressed.txt will be identical.





