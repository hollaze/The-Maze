#include <stdio.h>
#include <stdlib.h>
#include "../headers/maze.h"

/**
 * processQuitAndEscape - close window on escape or on click on the X
 * @is_running: TRUE or FALSE, if FALSE, close window
 * and while loop in main.c
 * Return: is_running
 */

int processQuitAndEscape(int is_running)
{
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		is_running = FALSE;
		break;

	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE)
			is_running = FALSE;
		break;
	}
	return (is_running);
}
