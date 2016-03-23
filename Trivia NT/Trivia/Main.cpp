#include <iostream>
#include <stdlib.h> 

#include <SDL\SDL.h>
#include <GL/glew.h>

#include "Input.h"

int main(int argc, char** argv) {
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 800, SDL_WINDOW_OPENGL);

	SDL_GLContext glContext = SDL_GL_CreateContext(window);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	
	bool asdf = Input::isRunning();
	
	while (asdf) {
		asdf = Input::isRunning;
	}

	return 0;
}