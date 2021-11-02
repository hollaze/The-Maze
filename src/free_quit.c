#include "../headers/maze.h"
#include <stdlib.h>

/**
 * freeWallTexture - free the wall textures
 *
 * Return: void
 */

void freeWallTexture(void)
{
	int i;

	for (i = 0; i < NUM_TEXTURES; i++)
	{
		upng_free(wall_textures[i].upng_texture);
	}
}

/**
 * destroyAndQuit - free, then quit SDL
 *
 * Return: void
 */

void destroyAndQuit(void)
{
	/* free all textures from walls */
	freeWallTexture();
	/* Free the allocation in memory */
	free(r.color_buffer);
	/* Free texture */
	SDL_DestroyTexture(r.color_buffer_texture);
	/* Free renderer */
	SDL_DestroyRenderer(r.renderer);
	/* Free Window */
	SDL_DestroyWindow(r.window);
	SDL_Quit();
}
