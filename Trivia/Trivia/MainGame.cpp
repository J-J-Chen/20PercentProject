#include "MainGame.h"
#include "Errors.h"
#include "IOManager.h"
#include "Draw.h"
#include "ButtonManager.h"
#include "Questions.h"

#include <iostream>
#include <string>

MainGame::MainGame() :
	_screenWidth(1024),
	_screenHeight(768),
	_time(0.0f),
	window(nullptr),
	_gameState(GameState::PLAY)
{
	fontA = TTF_OpenFont("asdf.ttf", 24);
	fontB = TTF_OpenFont("asf.ttf", 30);
}

MainGame::~MainGame()
{}

void MainGame::run() {
	initSystems();
	_sprite.init(-1.0f, -1.0f, 2.0f, 2.0f);
	gameLoop();
}

void MainGame::initSystems() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Trivia Fun!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
	if (window == nullptr) {
		fatalError("SDL Window could not be created!");
	}

	if (TTF_Init() == -1) {
		fatalError("TTF_Init failed!");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	if (glContext == nullptr) {
		fatalError("SDL_GL context could not be created!");
	}

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("Could not initialize glew!");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	initShaders();
}

void MainGame::initShaders() {
	_colorProgram.compileShaders("Shaders/colorShading.vert", "Shaders/colorShading.frag");
	_colorProgram.addAttribute("vertexPosition");
	_colorProgram.addAttribute("vertexColor");
	_colorProgram.linkShaders();
}

void MainGame::gameLoop() {
	while (_gameState != GameState::EXIT) {
		processInput();
		_time += 0.01f;
		draw();
	}
}

void MainGame::processInput() {
	SDL_Event evnt;

	SDL_StartTextInput();

	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		default:
			IOManager::processInput(evnt);
		}
	}
}

void MainGame::drawGame() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_colorProgram.use();
	GLuint timeLocation = _colorProgram.getUniformLocation("time");
	glUniform1f(timeLocation, _time);
	_sprite.draw();
	_colorProgram.unuse();
	SDL_GL_SwapWindow(window);
}

void MainGame::draw() {
	answer1.w = 400;
	answer1.h = 100;
	answer2.w = 400;
	answer2.h = 100;
	answer3.w = 400;
	answer3.h = 100;
	answer4.w = 400;
	answer4.h = 100;
	question.w = 849;
	question.h = 300;

	renderer = SDL_CreateRenderer(window, -1, 0);

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1024, 768);

	answer1.x = 75;
	answer1.y = 468;
	answer2.x = 525;
	answer2.y = 468;
	answer3.x = 525;
	answer3.y = 618;
	answer4.x = 75;
	answer4.y = 618;
	question.x = 75;
	question.y = 50;

	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, 118, 32, 201, 1);
	SDL_RenderClear(renderer);
	SDL_RenderDrawRect(renderer, &answer1);
	SDL_SetRenderDrawColor(renderer, 0, 255, 17, 0x00);
	SDL_RenderFillRect(renderer, &answer1);
	SDL_RenderFillRect(renderer, &answer2);
	SDL_RenderFillRect(renderer, &answer3);
	SDL_RenderFillRect(renderer, &answer4);
	SDL_RenderFillRect(renderer, &question);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void MainGame::getQandA() {
	_question = Questions::GetQuestions();
	_answer1 = Questions::getAnswer1();
	_answer2 = Questions::getAnswer2();
	_answer3 = Questions::getAnswer3();
	_answer4 = Questions::getAnswer4();
	_correctAnswer = Questions::getCorrectAnswer();
}