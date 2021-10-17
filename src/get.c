#include <stdlib.h>
#include "../headers/maze.h"

void get_W(get_wrt *get, SDL_Window *window)
{
	if (get != NULL)
		get->window = window;
}

void get_R(get_wrt *get, SDL_Renderer *renderer)
{
	if (get != NULL)
		get->renderer = renderer;
}

void get_T(get_wrt *get, SDL_Texture *texture)
{
	if (get != NULL)
		get->texture = texture;
}
