#include "../headers/maze.h"
#include <stdlib.h>

/**
 * initializeTextureColor - initialize the texture color of the walls
 *
 * Return: void
 */

void initializeTextureColor(void)
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

/**
 * allocateColorBuffer - allocating memory for the color buffer
 *
 * Return: void
 */

void allocateColorBuffer(void)
{
	/* allocate enough memory to hole the entire screen inside the buffer */
	r.color_buffer = (uint32_t *)malloc(sizeof(uint32_t) *
					    WINDOW_WIDTH *
					    WINDOW_HEIGHT);
	if (r.color_buffer == NULL)
		exitWithError("allocateColorBuffer, color_buffer is NULL");
}

/**
 * clearColorBuffer - store the color of the walls in the buffer
 *
 * @color: the color of the walls
 *
 * Return: color_buffer
 */

void clearColorBuffer(uint32_t color)
{
	int x, y;

	for (x = 0; x < WINDOW_WIDTH; x++)
	{
		for (y = 0; y < WINDOW_HEIGHT; y++)
		{
			r.color_buffer[(WINDOW_WIDTH * y) + x] = color;
		}
	}
}

/* images to load from images directory */
static const char *textureFileNames[NUM_TEXTURES] = {
"./images/bush.png"};

/**
 * loadWallTextures - load every wall texture
 *
 * Return: void
 */

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
				wall_textures[i].texture_buffer = (uint32_t *)upng_get_buffer(upng);
			}
		}
	}
}
