#pragma once

#include <SDL/SDL_events.h>
#include <vector>
#include <SDL\SDL_keyboard.h>

class IOManager
{
public:
	//static bool readFileToBuffer(std::string filePath, std::vector<char>& buffer);
	static void processInput(SDL_Event evnt);
	void InterpretText(char* text);
private:
};

