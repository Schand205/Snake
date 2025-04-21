#pragma once

//Libraries
#include <SDL.h>
#include <iostream>

//Namespaces
using namespace std;

//Structs
class App {
public:
	SDL_Renderer *renderer;
	SDL_Window *window;
	int down;
	int up;
	int right;
	int left;

	char returnInput() {
		char input = 0;
		if (up)		input = 'u';
		if (down)	input = 'd';
		if (left) 	input = 'l';
		if (right)	input = 'r';
		return input;
	}
	void resetKeys() {
		down = up = right = left = 0;
	}
};

typedef struct {
	int x;
	int y;
} coords;

class Snake {
public:
	Snake(vector<coords> sp) : s_pos(sp) {}

	vector<coords> s_pos;
	SDL_Texture *texture;

	void updateCoord(int ux, int uy) {
		s_pos[0].x += ux;
		s_pos[0].y += uy;
	}
};

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

void maintainPos(App *app, Snake *snake);
