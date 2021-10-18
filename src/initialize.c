#include <stdio.h>
#include <stdlib.h>
#include "../headers/maze.h"

SDL_Window *initializeWindow(SDL_Window *window)
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
		exitWithError("Cannot create SDL window");

	return (window);
}

SDL_Renderer *initializeRenderer(SDL_Window *window, SDL_Renderer *renderer)
{
	renderer = SDL_CreateRenderer(window, -1, 0);

	if (renderer == NULL)
		exitWithError("Cannot create SDL renderer");

	if (SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND) != 0)
		exitWithError("Cannot set render draw blend mode");

	return (renderer);
}

void render(SDL_Renderer *renderer, player_struct player)
{
	SDL_Rect rect;

	rect.w = 20;
	rect.h = 20;
	rect.x = player.x;
	rect.y = player.y;

	if (renderer == NULL)
		exitWithError("renderer is NULL");

	if (SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		exitWithError("Cannot render color");
	if (SDL_RenderClear(renderer) != 0)
		exitWithError("Cannot clear renderer");

	SDL_RenderDrawRect(renderer, &rect);

	if (SDL_SetRenderDrawColor(renderer, 255, 255, 0,
				   SDL_ALPHA_OPAQUE) != 0)
		exitWithError("Cannot render color");
	if (SDL_RenderFillRect(renderer, &rect) != 0)
		exitWithError("Cannot fill rectangle with color");

	SDL_RenderPresent(renderer);
}
