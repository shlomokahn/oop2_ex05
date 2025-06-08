#include "Controller.h"
#include "SrartWindow.h"

int main() {
    StartWindow startWindow;
    startWindow.run();

    Controller controller;
    controller.run();

    return 0;
} 