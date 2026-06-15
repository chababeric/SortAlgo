//
// Created by Eric El-Chabab on 2026-06-09.
//

#ifndef SORTALGO_MERGESORT_H
#define SORTALGO_MERGESORT_H
#include "Sort.h"


/**
 * @brief Merge sort implementation of Sort.
 *
 * Implements the divide-and-conquer merge sort algorithm.
 */
class MergeSort : public Sort {
private:
    std::string algorithmName = "Merge Sort";

    void merge(std::vector<int>& array, int left, int mid, int right);
    void mergeSort(std::vector<int>& array, int left, int right);

public:
    /**
     * @brief Sorts the provided vector using merge sort.
     * @param data Reference to the vector to sort.
     * @return A vector<int> containing the sorted elements.
     *
     * This implementation may create temporary vectors during the sort.
     */
    std::vector<int> sortArray(std::vector<int>& data) override;

    std::string getAlgorithmName() override;
};


#endif //SORTALGO_MERGESORT_H
