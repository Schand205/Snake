#pragma once

//Libraries
#include <SDL.h>
#include <iostream>

//Namespaces
using namespace std;

//Structs
typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
	int down;
	int up;
	int right;
	int left;
}App;

typedef struct {
	int x;
	int y;
	SDL_Texture *texture;
} Snake;

//Const Variables
constexpr int SPALTEN = 32;
constexpr int ZEILEN = 18;
constexpr int FELDGROESSE = 40;
constexpr int SCREEN_WIDTH = 1280;
constexpr int SCREEN_HEIGHT = 720;



//Funktionen
void prepareScene(App *app);

void presentScene(App *app);

void initSDL(App *app);

void doInput(App *app);

void cleanup(App *app);

void drawGrid(App *app);

void drawSnake(App *app, Snake *snake);
