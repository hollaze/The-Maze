#include <stdio.h>
#include <stdlib.h>
#include "../headers/maze.h"

/**
 * initializeWindow - initialize the window
 * @window: window value
 * Return: window
 */

void initializeWindow(void)
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
}

/**
 * initializeRenderer - initialize the renderer
 * @window: window value
 * @renderer: renderer value
 * Return: renderer
 */

void initializeRenderer(void)
{
	renderer = SDL_CreateRenderer(window, -1, 0);

	if (renderer == NULL)
		exitWithError("Cannot create SDL renderer");

	if (SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND) != 0)
		exitWithError("Cannot set render draw blend mode");
}

void render(void)
{
	if (renderer == NULL)
		exitWithError("renderer is NULL");

	/* Set screen to black */
	if (SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) != 0)
		exitWithError("render, cannot render color");
	if (SDL_RenderClear(renderer) != 0)
		exitWithError("render, cannot clear renderer");

	renderMap();
	renderRays();
	renderPlayer();

	SDL_RenderPresent(renderer);
	if (SDL_RenderClear(renderer) != 0)
		exitWithError("render, cannot clear renderer");
}

/**
 * renderMap - render the map on the window
 * @renderer: renderer value to render map
 * Return: void
 */

void renderMap(void)
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

			if (SDL_RenderFillRect(renderer, &map_tile_rect) != 0)
                                exitWithError("renderMap, cannot fill rect");
		}
	}
}

/**
 * renderPlayer - render player on the window
 * @renderer: renderer value to render player
 * @player: player struct values
 * Return: void
 */

void renderPlayer(void)
{
	SDL_Rect player_rect;

	if (SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255) != 0)
		exitWithError("renderPlayer, cannot set render draw color");

	player_rect.x = player.x * MINIMAP_SCALE_FACTOR;
	player_rect.y = player.y * MINIMAP_SCALE_FACTOR;
	player_rect.w = player.width * MINIMAP_SCALE_FACTOR;
	player_rect.h = player.height * MINIMAP_SCALE_FACTOR;

	if (SDL_RenderFillRect(renderer, &player_rect) != 0)
		exitWithError("renderPlayer, cannot fill rectangle");

	if (SDL_RenderDrawLine(renderer,
			       player.x * MINIMAP_SCALE_FACTOR,
			       player.y * MINIMAP_SCALE_FACTOR,
			       (player.x + cos(player.rotation_angle) * 40) * MINIMAP_SCALE_FACTOR,
			       (player.y + sin(player.rotation_angle) * 40) * MINIMAP_SCALE_FACTOR) != 0)
		exitWithError("renderPlayer, cannot render draw line");
}
