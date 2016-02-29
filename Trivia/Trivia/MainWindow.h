#pragma once
#include <SDL\SDL.h>
class MainWindow
{
public:
	MainWindow();
	~MainWindow();

	void run();

	void initSystems();

private:
	SDL_Window* window;
	int SCREEN_HEIGHT;
	int SCREEN_WIDTH;
};

