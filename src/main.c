#include <stdio.h>
#include <stdlib.h>
#include "../headers/maze.h"

int is_game_running = FALSE;
int ticks_last_frame;
Uint32 *color_buffer = NULL;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *color_buffer_texture = NULL;

player_struct player;
struct ray_struct rays[NUM_RAYS];
coll_detect cd;

/**
 * main - The Maze game
 * Return: 0
 */

int main(void)
{
	initializeWindow();
	initializeRenderer();

	if (window == NULL || renderer == NULL)
		exitWithError("main.c : window or renderer are NULL");
	is_game_running = TRUE;

	setup_player();
	setupColorBuffer();

	while (is_game_running)
	{
		processInput();
		update();
		render();
	}

	destroyAndQuit();

	return (0);
}
