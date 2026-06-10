#include <iostream>
#include <chrono>
#include <random>

#include "MergeSort.h"


int main() {
    constexpr int SEED = 46;
    constexpr int SIZE = 5;
    constexpr int MAX_VALUE = 10;
    constexpr int MIN_VALUE = 1;
    MergeSort sorter;

    std::vector<int> data(SIZE);

    // Random numbers every time
    // std::random_device rd;
    // std::mt19937 gen(rd());

    std::mt19937 gen(SEED);
    std::uniform_int_distribution<> dist(MIN_VALUE, MAX_VALUE);

    for (int& value : data) {
        value = dist(gen);
    }

    std::cout << "Original array: { ";
    for (const auto& x : data)
        std::cout << x << " ";
    std::cout << "}" << std::endl;

    const auto start = std::chrono::high_resolution_clock::now();
    const std::vector<int> sortedData = sorter.sortArray(data);
    const auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Sorted array: { ";
    for (const auto& x : sortedData)
        std::cout << x << " ";
    std::cout << "}" << std::endl;

    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Duration: " << duration.count() << " microseconds" << std::endl;

    return 0;
}