#include "IOManager.h"

#include <fstream>

bool IOManager::readFileToBuffer(std::string filePath, std::vector<char>& buffer) {
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
}

void IOManager::processInput(SDL_Event evnt) {
	switch (evnt.type) {
	case SDL_TEXTINPUT:
		strcat(text, evnt.text.text);
		break;
	}
}

void IOManager::InterpretText(char* text) {
}