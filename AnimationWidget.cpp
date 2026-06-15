//
// Created by Eric El-Chabab on 2026-06-12.
//

#include "AnimationWidget.h"

#include <QHBoxLayout>
#include <QPainter>
#include <algorithm>
#include <vector>
#include <thread>

class VisualizerWidget : public QWidget {
public:
    explicit VisualizerWidget(QWidget *parent = nullptr) : QWidget(parent) {}
    void setData(const std::vector<int>& data) {
        currentData = data;
        update();
    }
protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        if (currentData.empty()) return;

        int n = currentData.size();
        float barWidth = static_cast<float>(width()) / n;
        int maxVal = *std::max_element(currentData.begin(), currentData.end());
        if (maxVal == 0) maxVal = 1;

        for (int i = 0; i < n; ++i) {
            float barHeight = (static_cast<float>(currentData[i]) / maxVal) * height();
            painter.fillRect(QRectF(i * barWidth, height() - barHeight, barWidth > 1 ? barWidth - 1 : barWidth, barHeight), Qt::blue);
        }
    }
private:
    std::vector<int> currentData;
};

AnimationWidget::AnimationWidget(const std::vector<int>& numbers, Sort *sortAlgorithm, int speed, QWidget *parent)
    : QWidget(parent), data(numbers), sortAlgorithm(sortAlgorithm), speed(speed) {
    setFixedSize(800, 450);

    auto* mainLayout = new QVBoxLayout(this);

    // Top info bar
    auto* topLayout = new QHBoxLayout();

    auto* appNameLabel = new QLabel("SortAlgo", this);
    appNameLabel->setStyleSheet("font-weight: bold; font-size: 16px;");

    QString algoName = sortAlgorithm ? QString::fromStdString(sortAlgorithm->getAlgorithmName()) : "Unknown";
    auto* algoLabel = new QLabel("Algorithm: " + algoName, this);

    timeLabel = new QLabel("Time: 0.0s", this);

    topLayout->addWidget(appNameLabel);
    topLayout->addStretch();
    topLayout->addWidget(algoLabel);
    topLayout->addStretch();
    topLayout->addWidget(timeLabel);

    mainLayout->addLayout(topLayout);

    // Visualizer
    visualizer = new VisualizerWidget(this);
    mainLayout->addWidget(visualizer, 1); // stretch factor 1

    visualizer->setData(data);

    animationTimer = new QTimer(this);
    elapsedTimeTimer = new QTimer(this);

    connect(animationTimer, &QTimer::timeout, this, &AnimationWidget::onFrameAdvance);
    connect(elapsedTimeTimer, &QTimer::timeout, this, &AnimationWidget::onTimeUpdate);

    // Start processing delayed so UI can show
    QTimer::singleShot(500, this, &AnimationWidget::startAnimation);
}

void AnimationWidget::startAnimation() {
    if (!sortAlgorithm) return;

    int delayUs = 0;
    if (speed < 100) {
        delayUs = (100 - speed) * 100; // max 9900 us ~ 10ms per operation
    }
    sortAlgorithm->setSleepDuration(delayUs);

    elapsedTimeMs = 0;
    isSorting = true;

    sortingThread = std::thread([this]() {
        sortAlgorithm->sortArray(this->data);
        isSorting = false;
    });

    animationTimer->start(16); // 60 FPS update
    elapsedTimeTimer->start(100); // Update time every 100ms
}

void AnimationWidget::onFrameAdvance() {
    visualizer->setData(data);
    if (!isSorting) {
        animationTimer->stop();
        elapsedTimeTimer->stop();
        visualizer->setData(data); // final frame
    }
}

void AnimationWidget::onTimeUpdate() {
    elapsedTimeMs += 100;
    timeLabel->setText(QString("Time: %1s").arg(elapsedTimeMs / 1000.0, 0, 'f', 1));
}

AnimationWidget::~AnimationWidget() {
    if (sortingThread.joinable()) {
        sortAlgorithm->stopRequested = true;
        sortingThread.join();
    }
    delete sortAlgorithm;
}
