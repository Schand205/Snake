#include "header.hpp"

int main(int argc, char *argv[])
{
	
	App *app = new App;

	Snake *snake = new Snake;	

	memset(app, 0, sizeof(App));
   	memset(snake, 0, sizeof(Snake));

	initSDL(app);


	while (1)
	{
	prepareScene(app);

	doInput(app);

	presentScene(app);

	SDL_Delay(16);
	}

	cleanup(app);

	return 0;
}
