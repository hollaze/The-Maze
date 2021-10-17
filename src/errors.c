#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

void exitWithError(char *message)
{
	SDL_Log("Error: %s > %s", message, SDL_GetError());
	SDL_ClearError();
	SDL_Quit();
	exit(EXIT_FAILURE);
}
