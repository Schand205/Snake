#include "header.hpp"

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
	SDL_Rect pos = {snake->x * FELDGROESSE, snake->y * FELDGROESSE, FELDGROESSE, FELDGROESSE};
	SDL_RenderFillRect(app->renderer, &pos);
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
