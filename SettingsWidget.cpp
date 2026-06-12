//
// Created by Eric El-Chabab on 2026-06-12.
//

#include "SettingsWidget.h"

#include <QGroupBox>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QSpinBox>
#include <QSlider>
#include <random>

SettingsWidget::SettingsWidget(QWidget *parent) : QWidget(parent) {
    setFixedSize(600, 350);

    auto* settingsLayout = new QVBoxLayout(this);

    // Title
    auto* titleLabel = new QLabel(this);
    titleLabel->setText("SortAlgo");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");
    settingsLayout->addWidget(titleLabel);

    // Settings QGroupBox
    auto* settingsBox = new QGroupBox("Settings", this);
    auto* formLayout = new QFormLayout(settingsBox);

    formLayout->setLabelAlignment(Qt::AlignLeft);
    formLayout->setFormAlignment(Qt::AlignLeft);
    formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);

    sortingAlgorithmComboBox = new QComboBox(settingsBox);
    sortingAlgorithmComboBox->addItems({"Merge Sort", "Quick Sort"});
    sortingAlgorithmComboBox->setFixedWidth(200);
    formLayout->addRow("Algorithm:", sortingAlgorithmComboBox);

    data = new QLineEdit(settingsBox);
    data->setPlaceholderText("e.g. 5, 2, 9, 1, 5, 6");

    auto* randomButton = new QPushButton("Random", settingsBox);

    auto* numbersLayout = new QHBoxLayout();
    numbersLayout->addWidget(data);
    numbersLayout->addWidget(randomButton);
    data->setFixedWidth(300);
    randomButton->setFixedWidth(80);

    formLayout->addRow("Numbers:", numbersLayout);

    // List length
    auto* listLengthSpinBox = new QSpinBox(settingsBox);
    listLengthSpinBox->setRange(3, 100000);
    listLengthSpinBox->setValue(10);
    listLengthSpinBox->setFixedWidth(120);
    formLayout->addRow("List length:", listLengthSpinBox);

    // Simulation speed
    auto* simulationSpeedSlider = new QSlider(Qt::Horizontal, settingsBox);
    simulationSpeedSlider->setRange(1, 100);
    simulationSpeedSlider->setValue(50);
    simulationSpeedSlider->setFixedWidth(300);

    auto* speedLabel = new QLabel("50", settingsBox);

    auto* speedLayout = new QHBoxLayout();
    speedLayout->addWidget(simulationSpeedSlider);
    speedLayout->addWidget(speedLabel);

    formLayout->addRow("Simulation speed:", speedLayout);

    connect(simulationSpeedSlider, &QSlider::valueChanged, speedLabel,
            [speedLabel](int value) {
                speedLabel->setText(QString::number(value));
            });

    settingsLayout->addWidget(settingsBox);

    settingsLayout->addStretch();

    // Buttons
    auto* buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();

    auto* cancelButton = new QPushButton("Cancel", this);
    auto* okButton = new QPushButton("OK", this);

    cancelButton->setStyleSheet("background-color: #D30000; color: white; padding: 5px 15px; border-radius: 5px;");
    okButton->setStyleSheet("background-color: #007BFF; color: white; padding: 5px 15px; border-radius: 5px;");

    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(okButton);

    settingsLayout->addLayout(buttonLayout);

    // Button Actions
    cancelButton->connect(cancelButton, &QPushButton::clicked, this, &QWidget::close);
    randomButton->connect(randomButton, &QPushButton::clicked, this, [this, listLengthSpinBox]() {
        const int listLength = listLengthSpinBox->value();
        const std::vector<int> randomList = generateRandomList(listLength);
        QStringList stringList;
        for (int num : randomList) {
            stringList << QString::number(num);
        }
        data->setText(stringList.join(", "));
    });
}

std::vector<int> SettingsWidget::generateRandomList(int listLength) {
    std::vector<int> randomList(listLength);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    for (int& value : randomList) {
        value = dist(gen);
    }

    return randomList;
}

SettingsWidget::~SettingsWidget() = default;