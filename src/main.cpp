#include "header.hpp"

int main(int argc, char *argv[])
{
	//Initialisieren
	App *app = new App;

	vector<coords> startpos = {{0, 0}};
	Snake *snake = new Snake(startpos);

	Player player(getenv("USER"), 0);

	Apple apple(0, 0, false);

	initSDL(app);

	//Game-Loop
	while (!app->quit)
	{
		prepareScene(app);

		drawGrid(app);

		drawSnake(app, snake);

		randomApple(app, apple);

		doInput(app);

		maintainPos(app, snake);

		presentScene(app);

		updateScore(player, snake, apple);

		SDL_Delay(60);
	}
	manageHighscore(player);

	cleanup(app);

	return 0;
}
