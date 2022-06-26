#include <stdio.h>
#include <stdlib.h>
#include "../headers/maze.h"

/**
 * main - The Maze game
 * Return: 0
 */

int main(void)
{
	int ticks_last_frame = 0;
	float delta_time;

	setupPlayer();
	setupRendering();
	initializeWindow();
	initializeRenderer();
	initializeTextureColor();
	loadWallTextures();

	if (r.window == NULL || r.renderer == NULL)
		exitWithError("main, window or renderer is NULL");
	player.is_game_running = TRUE;

	allocateColorBuffer();

	while (player.is_game_running)
	{
		processInput();
		delta_time = deltaTime(delta_time, ticks_last_frame);
		update(delta_time, ticks_last_frame);
		ticks_last_frame = ticksLastFrame(ticks_last_frame);
		render();
	}

	destroyAndQuit();

	return (0);
}
