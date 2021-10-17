#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>

#define TRUE 1
#define FALSE 0

/* Window */
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/* Player spawn */
#define PLAYER_X 0
#define PLAYER_Y 0

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
 * is_game_running - check if game is running
 * @running: int that is either TRUE or FALSE
 */

typedef struct is_game_running {
	int running;
} is_game_running;

/**
 * struct get_player - get player position and movements
 * @x: player x position
 * @y: player y position
 */

typedef struct player_struct
{
	int x;
	int y;
} player_struct;

/* Initialize */
int initializeWindowAndRenderer(SDL_Window *window, SDL_Renderer *renderer);
void render(SDL_Renderer *renderer, player_struct player);

/* Processes inputs */
int processQuitAndEscape(is_game_running game_running, int running);

/* Player movements */
void update(player_struct player);

/* Destroy and quit */
void destroyAndQuit(SDL_Window *window, SDL_Renderer *renderer);

/* Errors */
void exitWithError(char *message);

#endif /* MAZE_H */
