#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

int processQuitAndEscape(is_game_running game_running, int running)
{
	SDL_Event event;
	running = game_running.running;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		running = FALSE;
		break;

	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE)
			running = FALSE;
		break;
	}
	return (running);
}
