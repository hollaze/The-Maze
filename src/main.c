#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

/**
 */

int main(void)
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	initialize_wr wr;

	initialize_video();
	create_window_renderer(window, renderer);
	/* get window and renderer values */
	init_wr(&wr, window, renderer);
	/* Load renderer */
	SDL_RenderPresent(wr.renderer);
	/* Window delay */
	SDL_Delay(5000);
	destroy(wr.window, wr.renderer);

	return (EXIT_SUCCESS);
}
