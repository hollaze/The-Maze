#include <stdio.h>
#include <stdlib.h>
#include "../headers/maze.h"

/**
 * initializeWindow - initialize the window
 * @window: window value
 * Return: window
 */

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

/**
 * initializeRenderer - initialize the renderer
 * @window: window value
 * @renderer: renderer value
 * Return: renderer
 */

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
	if (renderer == NULL)
		exitWithError("renderer is NULL");

	/* Set screen to black */
	if (SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		exitWithError("render, cannot render color");
	if (SDL_RenderClear(renderer) != 0)
		exitWithError("render, cannot clear renderer");

	renderMap(renderer);
	/*renderRays();*/
	renderPlayer(renderer, player);
	/* TODO: Render game objects here */

	SDL_RenderPresent(renderer);
	if (SDL_RenderClear(renderer) != 0)
		exitWithError("render, cannot clear renderer");
}

/**
 * renderMap - render the map on the window
 * @renderer: renderer value
 * Return: void
 */

void renderMap(SDL_Renderer *renderer)
{
	int i, j;
	int tile_x, tile_y, tile_color;
	SDL_Rect map_tile_rect;

	if (renderer == NULL)
		exitWithError("renderMap, renderer is NULL");


	for (i = 0; i < MAP_NUM_ROWS; i++)
	{
		for (j = 0; j < MAP_NUM_COLS; j++)
		{
			tile_y = i * TILE_SIZE;
			tile_x = j * TILE_SIZE;
			tile_color = (map[i][j] != 0) ? 255 : 0;

			if (SDL_SetRenderDrawColor(renderer,
					       tile_color,
					       tile_color,
					       tile_color,
					       255) != 0)
				exitWithError("renderMap,cannot render color");

			map_tile_rect.x = tile_x * MINIMAP_SCALE_FACTOR;
			map_tile_rect.y = tile_y * MINIMAP_SCALE_FACTOR;
			map_tile_rect.w = TILE_SIZE * MINIMAP_SCALE_FACTOR;
			map_tile_rect.h = TILE_SIZE * MINIMAP_SCALE_FACTOR;

			SDL_RenderFillRect(renderer, &map_tile_rect);
		}
	}
}
