#include "Draw.h"

Draw::Draw() {
	window = SDL_CreateWindow("Trivia Fun!",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1024, 768,
		SDL_WINDOW_RESIZABLE);

	r.w = 100;
	r.h = 50;

	renderer = SDL_CreateRenderer(window, -1, 0);

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1024, 768);

		r.x = rand() % 500;
		r.y = rand() % 500;

		SDL_SetRenderTarget(renderer, texture);
		SDL_SetRenderDrawColor(renderer, 118, 32, 201, 1);
		SDL_RenderClear(renderer);
		SDL_RenderDrawRect(renderer, &r);
		SDL_SetRenderDrawColor(renderer, 0, 255, 17, 0x00);
		SDL_RenderFillRect(renderer, &r);
		SDL_SetRenderTarget(renderer, NULL);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
}