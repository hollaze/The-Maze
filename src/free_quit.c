#include "../headers/maze.h"
#include <stdio.h>

/**
 * destroyAndQuit - free renderer and window, then quit SDL
 * @window: window value
 * @renderer: renderer value
 * Return: void
 */

void destroyAndQuit(SDL_Window *window, SDL_Renderer *renderer)
{
	/* Free renderer */
	SDL_DestroyRenderer(renderer);
	/* Free Window */
	SDL_DestroyWindow(window);
	SDL_Quit();
}
