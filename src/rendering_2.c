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

void renderColorBuffer(void)
{
	if (SDL_UpdateTexture(color_buffer_texture,
			      NULL,
			      color_buffer,
			      (int)((Uint32)WINDOW_WIDTH * sizeof(Uint32))) != 0)
		exitWithError("clearColorBuffer, cannot update texture");
	
	if (SDL_RenderCopy(renderer, color_buffer_texture, NULL, NULL) != 0)
		exitWithError("renderColorBuffer, cannot render copy");
}
