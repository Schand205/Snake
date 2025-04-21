#include "header.hpp"

int main(int argc, char *argv[])
{
	
	App *app = new App;

	vector<coords> startpos = {{0, }};

	Snake *snake = new Snake(startpos);

/*
	//Feld Initialisieren
	array<array<int, SPALTEN>, ZEILEN> feld;
	//Einträge auf 0 setzen
	for(auto zeile:feld) {
		zeile.fill(0);
	}
*/
	initSDL(app);


	while (1)
	{
	prepareScene(app);

	drawGrid(app);

	drawSnake(app, snake);

	doInput(app);
	//Position Updaten (Auslagern
	if (app->up) {
        	snake->updateCoord(0, -1);
        }
        if (app->down) {
        	snake->updateCoord(0, 1);
        }
        if (app->left) {
        	snake->updateCoord(-1, 0);
        }
        if (app->right) {
        	snake->updateCoord(1, 0);
        }
	if(snake->s_pos[0].x == SPALTEN) snake->updateCoord(-(SPALTEN), 0);
	if(snake->s_pos[0].x == -1) snake->updateCoord(SPALTEN, 0);
	if(snake->s_pos[0].y == ZEILEN) snake->updateCoord(0, -(ZEILEN));
	if(snake->s_pos[0].y == -1) snake->updateCoord(0, ZEILEN);

	presentScene(app);

	SDL_Delay(60);
	}

	cleanup(app);

	return 0;
}
