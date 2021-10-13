#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

/**
 * initialize - initialize the principal content of the game
 * Return: void
 */

void initialize_video()
{
	/* Cannot Initialize SDL video */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		exit_with_error("Video initialisation");
}
