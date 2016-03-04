#include "Errors.h"
#include <string>
#include <iostream>
#include <SDL\sdl.h>

void fatalError(std::string errorString) {
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to quit...";
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
}