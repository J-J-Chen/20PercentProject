#include "IOManager.h"
#include "ButtonManager.h"	

#include <iostream>
#include <fstream>

/**bool IOManager::readFileToBuffer(std::string filePath, std::vector<char>& buffer) {
	std::fstream file(filePath, std::ios::binary);
	if (file.fail()) {
		perror(filePath.c_str());
		return false;
	}

	file.seekg(0, std::ios::end);

	int fileSize = file.tellg();
	file.seekg(0, std::ios::beg);
	fileSize -= file.tellg();

	buffer.resize(fileSize);
	file.read(&(buffer[0]), fileSize);
	file.close();

	return true;
}*/

void IOManager::processInput(SDL_Event evnt) {
	switch (evnt.type) {
	case SDL_MOUSEBUTTONDOWN: {
		int xPixel = evnt.button.x;
		int yPixel = evnt.button.y;
		std::cout << xPixel << ", " << yPixel << std::endl;
		//if (ButtonManager::Clicked(xPixel, yPixel)) {

		//}
		break;
	}
	case SDL_TEXTEDITING:
		break;
	default:
		break;
	}
}

void IOManager::InterpretText(char* text) {
}