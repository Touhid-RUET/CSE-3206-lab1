# CSE-3206-lab1
# OOP project updated
 
# Multithreaded File Searcher in C++

This project demonstrates a complex C++ application that recursively searches for a keyword in all files under a specified directory using multithreading and modern C++ features.

## Features
- Uses C++17 (`std::filesystem`, `std::thread`, `std::mutex`, `std::atomic`)
- Efficiently searches files in parallel
- Prints matches with file and line number
- Thread-safe output

## How to Run
1. Compile with a C++17 compatible compiler (e.g., g++ -std=c++17)
2. Run the executable and provide the directory and keyword when prompted

## Example Usage
```
Enter directory to search: ./source_code
Enter keyword to search for: main
Found in ./source_code/main.cpp at line 10: int main() {
Searched 25 files.
```

## Author
Touhid-RUET
