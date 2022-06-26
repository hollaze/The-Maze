#include <stdio.h>
#include <stdlib.h>
#include "../headers/maze.h"

/**
 * exitWithError - used if there is an error, print:
 * format: function, error message, sdl error message
 * @message: function, error message, sdl error message
 * Return: void
 */

void exitWithError(char *message)
{
	SDL_Log("Error: %s > %s", message, SDL_GetError());
	SDL_ClearError();
	SDL_Quit();
	exit(EXIT_FAILURE);
}
