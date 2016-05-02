#pragma once
#include "MainGame.h"

class Draw {
public:
	Draw();
private:
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	SDL_Event event;
	SDL_Rect r;
	SDL_Window *window;
};
