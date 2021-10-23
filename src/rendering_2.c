#include "../headers/maze.h"

void renderRays(void)
{
	int i;

	if (SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255) != 0)
		exitWithError("renderRays, cannot render draw color");

	for (i = 0; i < NUM_RAYS; i++)
	{
		if (SDL_RenderDrawLine(renderer,
				       MINIMAP_SCALE_FACTOR * player.x,
				       MINIMAP_SCALE_FACTOR * player.y,
				       MINIMAP_SCALE_FACTOR * rays[i].wall_hit_x,
				       MINIMAP_SCALE_FACTOR * rays[i].wall_hit_y) != 0)
			exitWithError("renderRays, cannot render draw line");
	}
}
