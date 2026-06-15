//
// Created by Eric El-Chabab on 2026-06-10.
//

#ifndef SORTALGO_QUICKSORT_H
#define SORTALGO_QUICKSORT_H
#include "Sort.h"


class QuickSort : public Sort {
private:
    std::string algorithmName = "Quick Sort";
    int partition(std::vector<int>& array, int low, int high);
    void quickSort(std::vector<int>& array, int low, int high);

public:
    std::vector<int> sortArray(std::vector<int>& data) override;
    std::string getAlgorithmName() override;
};


#endif //SORTALGO_QUICKSORT_H
