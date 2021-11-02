#include "../headers/maze.h"
#include <stdlib.h>

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
 * @color_buffer: the buffer of colors
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
