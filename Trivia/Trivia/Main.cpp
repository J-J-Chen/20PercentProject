#include "MainWindow.h"
#include <iostream>

int main(int argc, char** argv) {
	MainWindow mainWindow;
	mainWindow.run();

	std::cout << "Enter any key to quit...";
	int a; 
	std::cin >> a;
	return 0;
}