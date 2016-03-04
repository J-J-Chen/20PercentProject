#pragma once
#include "Sprite.h"
#include "GLSLProgram.h"

#include <SDL/SDL.h>
#include <GL/glew.h>

enum class GameState {PLAY, EXIT};

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

    SDL_Window* _window;
    int _screenWidth;
    int _screenHeight;
    GameState _gameState;

	Sprite _sprite;

	GLSLProgram _colorProgram;
};

