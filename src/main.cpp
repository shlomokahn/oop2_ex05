#include "Controller.h"
#include "SrartWindow.h"

int main() {
    StartWindow startWindow;
	if (!startWindow.run())
		return 0; 
    Controller controller;
    controller.run();

    return 0;
} 