#include <iostream>

#include "Input.h"

Input::Input() {

}

void Input::processInput() {
	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
			break;
		}
	}
}

bool Input::isRunning() {
	if (gameState == GameState::EXIT)
		return true;
	else
		return false;
}
