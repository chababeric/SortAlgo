//
// Created by Eric El-Chabab on 2026-06-09.
//

#include "MergeSort.h"

void MergeSort::merge(std::vector<int> &array, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid) {
        temp[k++] = array[i++];
    }

    while (j <= right) {
        temp[k++] = array[j++];
    }

    for (int p = 0; p < k; p++) {
        if (stopRequested) break;
        array[left + p] = temp[p];
        pause();
    }
}

void MergeSort::mergeSort(std::vector<int> &array, int left, int right) {
    if (left < right && !stopRequested) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

std::vector<int> MergeSort::sortArray(std::vector<int> &data) {
    if (data.size() <= 1) return data;

    mergeSort(data, 0, data.size() - 1);

    return data;
}

std::string MergeSort::getAlgorithmName() {
    return algorithmName;
}
