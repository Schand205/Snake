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

	maintainPos(app, snake);

	presentScene(app);

	SDL_Delay(60);
	}

	cleanup(app);

	return 0;
}
