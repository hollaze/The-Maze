#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

int initializeWindowAndRenderer(SDL_Window *window, SDL_Renderer *renderer)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		exitWithError("Cannot initialize SDL");

	window = SDL_CreateWindow("The Maze",
				  SDL_WINDOWPOS_CENTERED,
				  SDL_WINDOWPOS_CENTERED,
				  WINDOW_WIDTH,
				  WINDOW_HEIGHT,
				  SDL_WINDOW_MINIMIZED);

	if (window == NULL)
		exitWithError("Cannot create SDL winodw");

	renderer = SDL_CreateRenderer(window, -1, 0);

	if (renderer == NULL)
		exitWithError("Cannot create SDL renderer");

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	return TRUE;
}

void render(SDL_Renderer *renderer)
{
	SDL_Rect rect = {player_x, player_y, 20, 20};

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	SDL_RenderFillRect(renderer, &rect);

	SDL_RenderPresent(renderer);
}

void destroyAndQuit(SDL_Window *window, SDL_Renderer *renderer)
{
	/* Free renderer */
	SDL_DestroyRenderer(renderer);
	/* Free Window */
	SDL_DestroyWindow(window);
	SDL_Quit();
}
