#include <QApplication>
#include <iostream>
#include <chrono>
#include <random>

#include "MergeSort.h"
#include "QuickSort.h"
#include "SettingsWidget.h"


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    SettingsWidget settingsWidget;
    settingsWidget.show();
    return QApplication::exec();
}
