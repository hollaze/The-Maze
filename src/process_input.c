#include <stdio.h>
#include <stdlib.h>
#include "../headers/maze.h"

/**
 * processInput - take the keyboard input and
 * return values depending of the input
 *
 * Return: void
 */

void processInput(void)
{
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		player.is_game_running = FALSE; /* quit on click on the X on the window */
		break;

	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE) /* quit on escape button */
			player.is_game_running = FALSE;
		/* keys for player movements */
		if (event.key.keysym.sym == SDLK_UP)
			player.walk_direction = 1;
		if (event.key.keysym.sym == SDLK_DOWN)
			player.walk_direction = -1;
		if (event.key.keysym.sym == SDLK_RIGHT)
			player.turn_direction = 1;
		if (event.key.keysym.sym == SDLK_LEFT)
			player.turn_direction = -1;
		break;
	case SDL_KEYUP:
		/* do nothing is nothing is pressed */
		if (event.key.keysym.sym == SDLK_UP)
			player.walk_direction = 0;
		if (event.key.keysym.sym == SDLK_DOWN)
			player.walk_direction = 0;
		if (event.key.keysym.sym == SDLK_RIGHT)
			player.turn_direction = 0;
		if (event.key.keysym.sym == SDLK_LEFT)
			player.turn_direction = 0;
		break;
	}
}
