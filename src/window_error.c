#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

/**
 * exit_with_error - print the error and quit
 * @message: error message
 * Return: void
 */

void exit_with_error(char *error_message)
{
	SDL_Log("ERROR : %s > %s\n", error_message, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}
