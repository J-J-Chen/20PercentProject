#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/glew.h>

#include "GLSLProgram.h"

#include "Sprite.h"

enum class GameState { PLAY, EXIT };

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

private:
	void initSystems();
	void initShaders();
	void gameLoop();
	void processInput();
	void drawGame();
	void draw();
	void getQandA();

	SDL_Window* window;
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;

	Sprite _sprite;

	GLSLProgram _colorProgram;

	float _time;

	SDL_Renderer *renderer;
	SDL_Texture *texture;
	SDL_Rect answer1;
	SDL_Rect answer2;
	SDL_Rect answer3;
	SDL_Rect answer4;
	SDL_Rect question;

	TTF_Font *fontA = NULL;
	TTF_Font *fontB = NULL;
	SDL_Color textColor = { 0,0,0 };
	SDL_Surface *background = NULL;
	SDL_Surface *message = NULL;
	SDL_Surface *screen = NULL;

	std::string _question;
	std::string _answer1;
	std::string _answer2;
	std::string _answer3;
	std::string _answer4;
	int _correctAnswer;
};

