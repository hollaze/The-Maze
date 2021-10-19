#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>

#define TRUE 1
#define FALSE 0

/* Size of walls and void on map */
#define TILE_SIZE 64
/* Number of rows and columns for the map */
#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20

/* Scale of the minimap on the screen */
/* going from 0 to 1 */
/* 1 is full screen */
#define MINIMAP_SCALE_FACTOR 0.3

/* Dynamic window */
#define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

/* Field Of View */
#define FOW_ANGLE (60 * (PI / 180))
#define NUM_RAYS WINDOW_WIDTH

/* Frame Per Second */
#define FPS 60
/* Number of Frame Per Second */
#define FRAME_TIME_LENGTH (1000 / FPS)

/* PI and PI * 2 Values */
#define PI 3.14159265
#define TWO_PI 6.28318530

/* Map of the game */
extern const int map[MAP_NUM_ROWS][MAP_NUM_COLS];

/**
 * struct player_struct - player position,
 * how big the player is, player movement
 * @x: player x position
 * @y: player y position
 * @width: width of the player
 * @height: height of the player
 * @turn_direction: direction the player turn to
 * @walk_direction: direction the player walk to
 * @rotation_angle: rotation angle of the player
 * @walk_speed: walk speed of the player
 * @turn_speed: turn speed of the player
 */

typedef struct player_struct
{
	float x;
	float y;
	float width;
	float height;
	int turn_direction; /* -1 for left and +1 for right */
	int walk_direction; /* -1 for back and +1 for front */
	float rotation_angle;
	float walk_speed;
	float turn_speed;
} player_struct;

/* Initialize */
SDL_Window *initializeWindow(SDL_Window *window);
SDL_Renderer *initializeRenderer(SDL_Window *window, SDL_Renderer *renderer);
void render(SDL_Renderer *renderer, player_struct player);
void renderMap(SDL_Renderer *renderer);
void renderPlayer(SDL_Renderer *renderer, player_struct player);

/* Processes inputs */
int processQuitAndEscape(int is_running);

/* Player movements */
player_struct setup(void);
void update(double delta_time, int ticks_last_frame);
double deltaTime(double delta_time, int ticks_last_frame);
int ticksLastFrame(int ticks_last_frame);

/* Free */
void destroyAndQuit(SDL_Window *window, SDL_Renderer *renderer);

/* Errors */
void exitWithError(char *message);

#endif /* MAZE_H */
