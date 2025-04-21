#include "header.hpp"

void doKeyDown(App *app, SDL_KeyboardEvent *event) {
	char input;
	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP) {
		    app->up = 1;
		}
		if (event->keysym.scancode == SDL_SCANCODE_DOWN) {
		    app->down = 1;
		}
		if (event->keysym.scancode == SDL_SCANCODE_LEFT) {
		    app->left = 1;
		}
		if (event->keysym.scancode == SDL_SCANCODE_RIGHT) {
		    app->right = 1;
		}
	}
}

void doKeyUp(App *app, SDL_KeyboardEvent *event) {
	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP) {
		    app->up = 0;
		}
		if (event->keysym.scancode == SDL_SCANCODE_DOWN) {
		    app->down = 0;
		}
		if (event->keysym.scancode == SDL_SCANCODE_LEFT) {
		    app->left = 0;
		}
		if (event->keysym.scancode == SDL_SCANCODE_RIGHT) {
		    app->right = 0;
        	}
	}
}

void maintainPos(App *app, Snake *snake) {
	char input = app->returnInput();
	switch (input) {
		case 'u': snake->updateCoord(0, -1); break;
        	case 'd': snake->updateCoord(0, 1); break;
        	case 'l': snake->updateCoord(-1, 0); break;
        	case 'r': snake->updateCoord(1, 0); break;
        }
	if(snake->s_pos[0].x == SPALTEN) snake->updateCoord(-(SPALTEN), 0);
	if(snake->s_pos[0].x == -1) snake->updateCoord(SPALTEN, 0);
	if(snake->s_pos[0].y == ZEILEN) snake->updateCoord(0, -(ZEILEN));
	if(snake->s_pos[0].y == -1) snake->updateCoord(0, ZEILEN);
}

void doInput(App *app)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
		case SDL_QUIT:
			exit(0);
			break;

		case SDL_KEYDOWN:
			app->resetKeys();
			doKeyDown(app, &event.key);
			break;

		case SDL_KEYUP:
			//doKeyUp(app, &event.key);
			break;

		default:
			break;
        }
    }
}


