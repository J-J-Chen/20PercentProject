#include "MainWindow.h"

MainWindow::MainWindow() {
	window = nullptr;
	SCREEN_HEIGHT = 200;
	SCREEN_WIDTH = 200;
}

MainWindow::~MainWindow()
{
}

void MainWindow::run() {
	initSystems();
}

void MainWindow::initSystems() {
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Trivia Fun", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_VIDEO_OPENGL);
}