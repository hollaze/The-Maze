#include <SDL.h>
#include "maze.h"
#include <stdio.h>
#include <stdlib.h>

void initialize_video(void)
{
	/* Cannot Initialize SDL video */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		exit_with_error("Cannot initialize video");
}

void create_window_renderer(SDL_Window *window, SDL_Renderer *renderer)
{
	window = SDL_CreateWindow("The Maze", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				  WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

	if (window == NULL)
		exit_with_error("Cannot create window");

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	if (renderer == NULL)
		exit_with_error("Cannot create renderer");
}

void init_wr(initialize_wr *get, SDL_Window *window, SDL_Renderer *renderer)
{
	if (get != NULL)
	{
		get->window = window;
		get->renderer = renderer;
	}
}
