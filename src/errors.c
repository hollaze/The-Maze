#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * exit_with_error - exit the SDL and the program with
 * the printed error
 * @message: what was the error
 * Return: void
 */

void exit_with_error(const char *message)
{
	SDL_Log("Error: %s > %s", message, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}
