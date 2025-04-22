#include "header.hpp"
#include <random>

int randomNumber(int min, int max) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(min, max);

	return distr(gen);
}

void drawGrid(App *app) {		
	SDL_SetRenderDrawColor(app->renderer, 255, 255, 255, 255); // Weiß
	//Vertikale Linien
	for(int spalte = 0; spalte <= SPALTEN; spalte++) {
		int x = spalte*FELDGROESSE;
		SDL_RenderDrawLine(app->renderer, x, 0, x, SCREEN_HEIGHT);
	}
	//Horizontale Linien
	for(int zeile = 0; zeile <= ZEILEN; zeile++) {
		int y = zeile * FELDGROESSE;
		SDL_RenderDrawLine(app->renderer, 0, y, SCREEN_WIDTH, y);
	}
}

void drawSnake(App *app, Snake *snake) {
	SDL_SetRenderDrawColor(app->renderer, 0, 255, 0 , 255);
	SDL_Rect pos = {snake->s_pos[0].x * FELDGROESSE, snake->s_pos[0].y * FELDGROESSE, FELDGROESSE, FELDGROESSE};
	SDL_RenderFillRect(app->renderer, &pos);
}

void randomApple(App *app, Apple &apple) {
	if(randomNumber(0, 50) == 1 && apple.visible == false) { 
			apple.set_new_Coords(randomNumber(0, SPALTEN-1), randomNumber(0, ZEILEN-1));
			apple.visible = true;
	}

	if(apple.visible == true) {
		SDL_SetRenderDrawColor(app->renderer, 255, 0, 0, 255);
		SDL_Rect pos = {apple.x*FELDGROESSE, apple.y*FELDGROESSE, FELDGROESSE, FELDGROESSE};
		SDL_RenderFillRect(app->renderer, &pos);
	}
}
	

void prepareScene(App *app)
{
	SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);
	SDL_RenderClear(app->renderer);
}

void presentScene(App *app)
{
	SDL_RenderPresent(app->renderer);
}
