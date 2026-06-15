//
// Created by Eric El-Chabab on 2026-06-09.
//

#ifndef SORTALGO_SORT_H
#define SORTALGO_SORT_H
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <atomic>


/*
 * Abstract class that
 */
class Sort {
protected:
    std::string algorithmName;
    int sleepDurationUs = 0;

public:
    std::atomic<bool> stopRequested{false};
    virtual ~Sort() = default;

    virtual std::vector<int> sortArray(std::vector<int>& data) = 0;

    virtual std::string getAlgorithmName();

    void setSleepDuration(int us) { sleepDurationUs = us; }
    void pause() {
        if (sleepDurationUs > 0 && !stopRequested) {
            std::this_thread::sleep_for(std::chrono::microseconds(sleepDurationUs));
        }
    }
};

#endif //SORTALGO_SORT_H
