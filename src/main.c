#include <stdio.h>
#include <stdlib.h>
#include "../headers/maze.h"

/**
 * main - The Maze game
 * Return: 0
 */

int main(void)
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	player_struct player;

	int is_running = FALSE;
	int ticks_last_frame = 0;
	double delta_time = 0.0f;

	window = initializeWindow(window);
	renderer = initializeRenderer(window, renderer);

	if (window == NULL && renderer == NULL)
		exitWithError("main.c : window or renderer are NULL");
	is_running = TRUE;

	player = setup();

	while (is_running)
	{
		is_running = processQuitAndEscape(is_running);
		delta_time = deltaTime(delta_time, ticks_last_frame);
		update(delta_time, ticks_last_frame);
		ticks_last_frame = ticksLastFrame(ticks_last_frame);
		render(renderer, player);
	}

	destroyAndQuit(window, renderer);

	return (0);
}
