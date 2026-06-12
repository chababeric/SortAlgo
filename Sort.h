//
// Created by Eric El-Chabab on 2026-06-09.
//

#ifndef SORTALGO_SORT_H
#define SORTALGO_SORT_H
#include <vector>


/*
 * Abstract class that
 */
class Sort {
protected:
    std::string algorithmName;
    
public:
    virtual ~Sort() = default;

    virtual std::vector<int> sortArray(std::vector<int>& data) = 0;
};


#endif //SORTALGO_SORT_H
