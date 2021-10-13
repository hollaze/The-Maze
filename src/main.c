#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

int main(void)
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	initialize_video();
	/* width, height, flags -> window type, window, renderer*/
	if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_MINIMIZED, &window, &renderer) != 0)
		exit_with_error("SDL_CreateWindowAndRenderer");
	SDL_SetWindowTitle(window, "The Maze");

	SDL_RenderPresent(renderer);
	/* Window delay ex: 1000 -> 1 second */
	SDL_Delay(5000);
	/* Free window pointer */
	SDL_DestroyWindow(window);
	/* Free renderer pointer */
	SDL_DestroyRenderer(renderer);

	SDL_Quit();

	return (EXIT_SUCCESS);
}
