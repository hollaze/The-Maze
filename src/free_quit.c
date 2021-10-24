#include "../headers/maze.h"
#include <stdlib.h>

/**
 * destroyAndQuit - free renderer and window, then quit SDL
 * @window: window value
 * @renderer: renderer value
 * Return: void
 */

void destroyAndQuit()
{
	/* Free the allocation in memory */
	free(color_buffer);
	/* Free texture */
	SDL_DestroyTexture(color_buffer_texture);
	/* Free renderer */
	SDL_DestroyRenderer(renderer);
	/* Free Window */
	SDL_DestroyWindow(window);
	SDL_Quit();
}
