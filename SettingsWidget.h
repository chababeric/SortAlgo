//
// Created by Eric El-Chabab on 2026-06-12.
//

#ifndef SORTALGO_SETTINGSWIDGET_H
#define SORTALGO_SETTINGSWIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QSlider>

class QComboBox;
class QLineEdit;

class SettingsWidget : public QWidget {
public:
    explicit SettingsWidget(QWidget *parent = nullptr);
    ~SettingsWidget() override;

private:
    QComboBox* sortingAlgorithmComboBox{};
    QLineEdit* data{};
    QSpinBox* listLengthSpinBox;
    QSlider* simulationSpeedSlider;
    std::vector<int> generateRandomList(int listLength);
};


#endif //SORTALGO_SETTINGSWIDGET_H
