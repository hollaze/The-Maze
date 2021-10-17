#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

int isGameRunning;
int player_x, player_y;

int main(void)
{
	get_wrt wrt;
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	player_x = 0, player_y = 0;
	isGameRunning = FALSE;

	isGameRunning = initializeWindowAndRenderer(window, renderer);
	get_W(&wrt, window);
	get_R(&wrt, renderer);

	while (isGameRunning)
	{
		processQuitAndEscape();
		update();
		render(wrt.renderer);
		get_R(&wrt, renderer);
	}

	destroyAndQuit(wrt.window, wrt.renderer);

	return (0);
}
