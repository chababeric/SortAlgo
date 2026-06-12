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
    /**
     * @brief Merges two sorted subvectors into the destination array.
     * @param array Destination vector where merged result is placed.
     * @param left Sorted left subvector.
     * @param right Sorted right subvector.
     *
     * This helper writes the merged, sorted elements into 'array'.
     */
    static void merge(std::vector<int>& array, const std::vector<int>& left, const std::vector<int>& right);

    /**
     * @brief Splits the range [low, high) into two halves and prepares indices.
     * @param low Lower bound (inclusive).
     * @param high Upper bound (exclusive).
     * @return The midpoint index between low and high.
     *
     * Utility used by the divide phase of merge sort.
     */
    static int split(int low, int high);

public:
    /**
     * @brief Sorts the provided vector using merge sort.
     * @param data Reference to the vector to sort.
     * @return A vector<int> containing the sorted elements.
     *
     * This implementation may create temporary vectors during the sort.
     */
    std::vector<int> sortArray(std::vector<int>& data) override;
};


#endif //SORTALGO_MERGESORT_H
