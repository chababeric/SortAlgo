//
// Created by Eric El-Chabab on 2026-06-10.
//

#include "QuickSort.h"
#include <utility>

int QuickSort::partition(std::vector<int> &array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (array[j] <= pivot) {
            i++;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[high]);

    return (i + 1);
}

void QuickSort::quickSort(std::vector<int> &array, int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);

        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}

std::vector<int> QuickSort::sortArray(std::vector<int> &data) {
    if (data.size() <= 1) return data;

    int low = 0, high = data.size() - 1;
    quickSort(data, low, high);

    return data;
}
