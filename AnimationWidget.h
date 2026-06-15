//
// Created by Eric El-Chabab on 2026-06-12.
//

#ifndef SORTALGO_ANIMATIONWIDGET_H
#define SORTALGO_ANIMATIONWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <vector>

#include "Sort.h"

class VisualizerWidget;

class AnimationWidget : public QWidget {
    Q_OBJECT
public:
    explicit AnimationWidget(const std::vector<int>& numbers, Sort* sortAlgorithm, int speed, QWidget* parent = nullptr);
    ~AnimationWidget() override;

private:
    std::vector<int> data;
    Sort *sortAlgorithm;
    int speed;

    QLabel* timeLabel;
    VisualizerWidget* visualizer;
    QTimer* animationTimer;
    QTimer* elapsedTimeTimer;

    int elapsedTimeMs = 0;
    std::thread sortingThread;
    std::atomic<bool> isSorting{false};

    void startAnimation();

private slots:
    void onFrameAdvance();
    void onTimeUpdate();
};

#endif //SORTALGO_ANIMATIONWIDGET_H
