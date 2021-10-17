#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

void processQuitAndEscape()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isGameRunning = FALSE;
		break;

	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE)
			isGameRunning = FALSE;
		break;
	}
}
