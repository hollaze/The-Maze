#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>

/****************************/
/********** MACROS **********/
/****************************/

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
#define MINIMAP_SCALE_FACTOR 1.0

/* Dynamic window */
#define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

/* Field Of View */
/* convert from degrees to radians */
#define FOV_ANGLE (60 * (PI / 180))
/* Number of rays is 1 per pixel of the window width */
/* within the field of view (limited by the field of view) */
#define NUM_RAYS WINDOW_WIDTH

/* Frame Per Second */
#define FPS 60
/* Number of Frame Per Second */
#define FRAME_TIME_LENGTH (1000 / FPS)

/* PI and PI * 2 Values */
#define PI 3.14159265
#define TWO_PI 6.28318530

/****************************/
/***** EXTERN VARIABLES *****/
/****************************/

/* Map of the game */
extern const int map[MAP_NUM_ROWS][MAP_NUM_COLS];
extern int is_game_running;
extern int ticks_last_frame;
extern SDL_Window *window;
extern SDL_Renderer *renderer;

/****************************/
/******** STRUCTURES ********/
/****************************/

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

/**
 * struct ray_struct - raycasting structure, using rays
 * to detect and render what is in front of me
 * depending of its distance from the camera of
 * my player
 *
 * @ray_angle: angle of the ray
 * @distance: maximum distance of the ray
 * @wall_hit_x: if wall is hit in x coordinates
 * @wall_hit_y: if wall is hit in x coordinates
 * @was_hit_vertical: check if there is a vertical collision
 * to a wall, with the ray
 * @ray_facing_up: the ray facing up
 * @ray_facing_down: the ray facing down
 * @ray_facing_right: the ray facing right
 * @ray_facing_left: the ray facing left
 * @wall_hit_content: the content of the wall that was hit
 */

struct ray_struct
{
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
};

typedef struct coll_detect
{
	/* horizontal */
	int found_horizontal_wall_hit;
	float horizontal_wall_hit_x;
	float horizontal_wall_hit_y;
	int horizontal_wall_content;
	float next_horizontal_touch_x;
	float next_horizontal_touch_y;
	float horizontal_hit_distance;
	/* vertical */
	int found_vertical_wall_hit;
	float vertical_wall_hit_x;
	float vertical_wall_hit_y;
	int vertical_wall_content;
	float next_vertical_touch_x;
	float next_vertical_touch_y;
	float vertical_hit_distance;
} coll_detect;

extern struct player_struct player;
extern struct ray_struct rays[NUM_RAYS];
extern struct coll_detect cd;

/***************************/
/*** FUNCTIONS BY FILES ****/
/***************************/

/* rendering */
void initializeWindow(void);
void initializeRenderer(void);
void render(void);
void renderMap(void);
void renderPlayer(void);

/* rendering_2 */
void renderRays(void);

/* player_movements */
void update(void);
void setup_player(void);
void movePlayer(float delta_time);

/* process_inputs */
void processInput(void);

/* collisions_detections */
int mapHasWallAt(float x, float y);
float distanceBetweenPoints(float x1, float x2, float y1, float y2);
float normalizeAngle(float angle);
void castRay(float ray_angle, int strip_id);
void castAllRays(void);

/* intercept */
float horizontalInterceptY(float ray_angle);
float horizontalInterceptX(float ray_angle);
float verticalInterceptX(float ray_angle);
float verticalInterceptY(float ray_angle);

/* step */
float horizontalStepX(float ray_angle);
float horizontalStepY(float ray_angle);
float verticalStepX(float ray_angle);
float verticalStepY(float ray_angle);

/* is_ray_facing */
int isRayFacingDown(float ray_angle);
int isRayFacingUp(float ray_angle);
int isRayFacingRight(float ray_angle);
int isRayFacingLeft(float ray_angle);

/* search_wall */
void setupCollDetect(void);
void searchHorizontalWall(float ray_angle);
void searchVerticalWall(float ray_angle);
void smallestHitDistance(int strip_id, float ray_angle);

/* free_quit */
void destroyAndQuit(void);

/* errors */
void exitWithError(char *message);

#endif /* MAZE_H */
