#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>

#define TRUE 1
#define FALSE 0

/* Window */
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/* Check if game is running - TRUE or FALSE */
extern int isGameRunning;
/* Set player x and y position */
extern int player_x, player_y;

/**
 * struct get_wrt - get window, renderer and texture
 * @window: window member
 * @renderer: renderer member
 * @texture: texture member
 */

typedef struct get_wrt
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture;

} get_wrt;

/* Get window, renderer, texture */
void get_W(get_wrt *get, SDL_Window *window);
void get_R(get_wrt *get, SDL_Renderer *renderer);
void get_T(get_wrt *get, SDL_Texture *texture);

/**
 * struct get_player - get player position and movements
 * @x: player x position
 * @y: player y position
 */

/*typedef struct get_player
{
	int x;
	int y;
} get_player;*/


/* Initialize */
int initializeWindowAndRenderer(SDL_Window *window, SDL_Renderer *renderer);
void render(SDL_Renderer *renderer);

/* Processes inputs */
void processQuitAndEscape(void);

/* Player movements */
void update();

/* Destroy and quit */
void destroyAndQuit(SDL_Window *window, SDL_Renderer *renderer);

/* Errors */
void exitWithError(char *message);

#endif /* MAZE_H */
