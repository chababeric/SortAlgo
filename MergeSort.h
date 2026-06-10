//
// Created by Eric El-Chabab on 2026-06-09.
//

#ifndef SORTALGO_MERGESORT_H
#define SORTALGO_MERGESORT_H
#include "Sort.h"


class MergeSort : public Sort{
private:
    static void merge(std::vector<int>& array, const std::vector<int>& left, const std::vector<int>& right);

    static int split(int low, int high);

public:
    std::vector<int> sortArray(std::vector<int>& data) override;
};


#endif //SORTALGO_MERGESORT_H
