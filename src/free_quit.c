#include "../headers/maze.h"
#include <stdlib.h>

/**
 * destroyAndQuit - free, then quit SDL
 *
 * Return: void
 */

void destroyAndQuit(void)
{
	/* Free the allocation in memory */
	free(r.color_buffer);
	free(r.wall_texture);
	/* Free texture */
	SDL_DestroyTexture(r.color_buffer_texture);
	/* Free renderer */
	SDL_DestroyRenderer(r.renderer);
	/* Free Window */
	SDL_DestroyWindow(r.window);
	SDL_Quit();
}
