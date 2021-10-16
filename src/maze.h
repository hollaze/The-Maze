#ifndef MAZE_H
#define MAZE_H

#include <SDL.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

typedef struct initialize_wr
{

	SDL_Window *window;
	SDL_Renderer *renderer;

} initialize_wr;

void initialize_video(void);
void create_window_renderer(SDL_Window *window, SDL_Renderer *renderer);
void init_wr(initialize_wr *get, SDL_Window *window, SDL_Renderer *renderer);
void destroy(SDL_Window *window, SDL_Renderer *renderer);

/* Errors */
void exit_with_error(const char *message);

#endif /* MAZE_H*/