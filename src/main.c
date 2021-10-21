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

	int ticks_last_frame = 0;
	float delta_time = 0.0f;

	window = initializeWindow(window);
	renderer = initializeRenderer(window, renderer);
	player.is_game_running = FALSE;

	if (window == NULL && renderer == NULL)
		exitWithError("main.c : window or renderer are NULL");
	player.is_game_running = TRUE;

	player = setup_player();

	while (player.is_game_running)
	{
		player = processInput(player);
		delta_time = deltaTime(delta_time, ticks_last_frame);
		player = update(delta_time, ticks_last_frame, player);
		ticks_last_frame = ticksLastFrame(ticks_last_frame);
		render(renderer, player);
	}

	destroyAndQuit(window, renderer);

	return (0);
}
