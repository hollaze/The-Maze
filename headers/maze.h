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
#define FOV_ANGLE (60 * (PI / 180))
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
 * @is_game_running: TRUE if game is running, FALSE otherwise
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
	int is_game_running;
} player_struct;

struct ray_struct {
	float ray_angle;
	float distance;
	float wall_hit_x;
	float wall_hit_y;
	int was_hit_vertical;
	int ray_facing_up;
	int ray_facing_down;
	int ray_facing_right;
	int ray_facing_left;
	int wall_hit_content;
} rays[NUM_RAYS];

/* Initialize */
SDL_Window *initializeWindow(SDL_Window *window);
SDL_Renderer *initializeRenderer(SDL_Window *window, SDL_Renderer *renderer);
void render(SDL_Renderer *renderer, player_struct player);
void renderMap(SDL_Renderer *renderer);
void renderPlayer(SDL_Renderer *renderer, player_struct player);
int mapHasWallAt(float player_x, float player_y);
void castAllRays(player_struct player);

/* Processes inputs */
player_struct processInput(player_struct player);

/* Player movements */
player_struct setup_player(void);
player_struct update(float delta_time, int ticks_last_frame, player_struct player);
float deltaTime(float delta_time, int ticks_last_frame);
int ticksLastFrame(int ticks_last_frame);
player_struct movePlayer(float delta_time, player_struct player);

/* Free */
void destroyAndQuit(SDL_Window *window, SDL_Renderer *renderer);

/* Errors */
void exitWithError(char *message);

#endif /* MAZE_H */
