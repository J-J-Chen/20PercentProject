#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>

class Input {
public:
	Input();
	void processInput();
	bool isRunning();
	enum class GameState { PLAY, EXIT };
	GameState gameState = GameState::PLAY;

private:
	SDL_Event evnt;
};
