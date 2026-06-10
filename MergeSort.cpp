//
// Created by Eric El-Chabab on 2026-06-09.
//

#include "MergeSort.h"

int MergeSort::split(const int low, const int high) {
    return (low + high) / 2;
}

void MergeSort::merge(std::vector<int> &array, const std::vector<int>& left, const std::vector<int>& right) {
    int i = 0, j = 0, k = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];
    }

    while (i < left.size()) {
        array[k++] = left[i++];
    }

    while (j < right.size()) {
        array[k++] = right[j++];
    }
}

std::vector<int> MergeSort::sortArray(std::vector<int> &data) {
    if (data.size() <= 1) return data;

    const int mid = split(0, data.size() - 1);

    std::vector left(data.begin(), data.begin() + mid + 1);
    std::vector right(data.begin() + mid + 1, data.end());

    sortArray(left);
    sortArray(right);

    merge(data, left, right);

    return data;
}
