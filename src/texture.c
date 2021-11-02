#include "../headers/maze.h"
#include <stdlib.h>

/**
 * initializeTexture - initialize the texture of the walls
 *
 * Return: void
 */

void initializeTexture(void)
{
	/* display color buffer texture */
	r.color_buffer_texture = SDL_CreateTexture(r.renderer,
						   SDL_PIXELFORMAT_RGBA32,
						   SDL_TEXTUREACCESS_STREAMING,
						   WINDOW_WIDTH,
						   WINDOW_HEIGHT);

	if (r.color_buffer_texture == NULL)
		exitWithError("setupColorBuffer, color_buffer_texture is NULL");
}

/* images to load from images directory */
static const char *textureFileNames[NUM_TEXTURES] = {
    "./images/bush.png"};

void loadWallTextures(void)
{
	int i;
	upng_t *upng;

	for (i = 0; i < NUM_TEXTURES; i++)
	{
		/* get png file into variable */
		upng = upng_new_from_file(textureFileNames[i]);
		if (upng != NULL)
		{
			/* Read png */
			upng_decode(upng);
			if (upng_get_error(upng) == UPNG_EOK)
			{
				wall_textures[i].upng_texture = upng;
				wall_textures[i].width = upng_get_width(upng);
				wall_textures[i].height = upng_get_height(upng);
				wall_textures[i].texture_buffer = (uint32_t*)upng_get_buffer(upng);
			}
		}
	}
}

void freeWallTexture(void)
{
	int i;
	for (i = 0; i < NUM_TEXTURES; i++)
	{
		upng_free(wall_textures[i].upng_texture);
	}
}

/* Create new texture with width and height to the TEXTURE_WIDTH and TEXTURE_HEIGHT */
