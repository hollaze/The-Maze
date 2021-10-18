#include "../headers/maze.h"
#include <stdio.h>

void destroyAndQuit(SDL_Window *window, SDL_Renderer *renderer)
{
	/* Free renderer */
	SDL_DestroyRenderer(renderer);
	/* Free Window */
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void free_struct(player_struct player)
{
        free(player.x);
        free(player.y);
}
