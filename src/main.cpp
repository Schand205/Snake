#include "header.hpp"

int main(int argc, char *argv[])
{
	
	App *app = new App;

	Snake *snake = new Snake;

	memset(app, 0, sizeof(App));
   	memset(snake, 0, sizeof(Snake));

	//Snake nach oben links setzen
	snake->x = 0;
	snake->y = 0;
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
        	snake->y -= 1;
        }
        if (app->down) {
        	snake->y += 1;
        }
        if (app->left) {
        	snake->x -= 1;
        }
        if (app->right) {
        	snake->x += 1;
        }
	if(snake->x == SPALTEN+1) snake->x = 0;
	if(snake->x == -1) snake->x = SPALTEN;
	if(snake->y == ZEILEN+1) snake->y = 0;
	if(snake->y == -1) snake->y = ZEILEN;

	presentScene(app);

	SDL_Delay(60);
	}

	cleanup(app);

	return 0;
}
