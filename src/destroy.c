#include <SDL.h>
#include "maze.h"

void destroy(SDL_Window *window, SDL_Renderer *renderer)
{
        /*Free renderer */
        SDL_DestroyRenderer(renderer);
        /* Free window */
        SDL_DestroyWindow(window);

        SDL_Quit();
}