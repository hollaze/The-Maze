#include "../headers/maze.h"
#include <stdlib.h>

void setupColorBuffer(void)
{
        color_buffer = (Uint32 *)malloc(sizeof(Uint32) *
                                        (Uint32)WINDOW_WIDTH *
                                        (Uint32)WINDOW_HEIGHT);

        color_buffer_texture = SDL_CreateTexture(renderer,
                                                 SDL_PIXELFORMAT_ARGB8888,
                                                 SDL_TEXTUREACCESS_STREAMING,
                                                 WINDOW_WIDTH,
                                                 WINDOW_HEIGHT);
}

void clearColorBuffer(Uint32 color)
{
        int x, y;

        for (x = 0; x < WINDOW_WIDTH; x++)
        {
                for (y = 0; y < WINDOW_HEIGHT; y++)
                {
                        color_buffer[(WINDOW_WIDTH * y) + x] = color;
                }
        }
}