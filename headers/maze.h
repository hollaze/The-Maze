#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>
#include "../headers/upng.h"

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
#define MINIMAP_SCALE_FACTOR 0.3

/* Dynamic window */
#define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

/* Texture size and also walls size */
#define TEXTURE_WIDTH 64
#define TEXTURE_HEIGHT 64

/* Number of textures */
#define NUM_TEXTURES 1

/* Field Of View */
/* convert from degrees to radians */
/* first value is the degree of the field of view angle */
#define FOV_ANGLE (60 * (PI / 180))
/* Number of rays is 1 per pixel of the window width */
/* within the field of view (limited by the field of view) */
#define NUM_RAYS WINDOW_WIDTH

/* Frame Per Second */
#define FPS 100
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

/****************************/
/******** STRUCTURES ********/
/****************************/

/**
 * struct rendering - used to render things
 *
 * @window: window
 * @renderer: renderer
 * @color_buffer_texture: texture
 * @color_buffer: color buffer
 */

struct rendering
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *color_buffer_texture;
	uint32_t *color_buffer;
} r;

/**
 * struct player_struct - player position,
 * how big the player is, player movement
 *
 * @x: player x position
 * @y: player y position
 * @width: width of the player
 * @height: height of the player
 * @turn_direction: direction the player turn to
 * @walk_direction: direction the player walk to
 * @rotation_angle: the angle the player is looking at, at spawn
 * @walk_speed: walk speed of the player
 * @turn_speed: turn speed of the player
 * @is_game_running: game is running: TRUE else: FALSE
 */

struct player_struct
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
} player;

/**
 * struct ray_struct - raycasting structure, using rays
 * to detect and render what is in front of me
 * depending of its distance from the camera of
 * my player
 *
 * @ray_angle: angle of the ray
 * @distance: ray distance from player to wall
 * @wall_hit_x: wall is hit in x coordinates
 * @wall_hit_y: wall is hit in x coordinates
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
} rays[NUM_RAYS];

/**
 * struct coll_detect_struct - detect the ray collision
 *
 *** HORIZONTAL ***
 * @found_horizontal_wall_hit: TRUE for wall hit, FALSE otherwise
 * @horizontal_wall_hit_x: x coordinates of the ray hit on wall
 * @horizontal_wall_hit_y: y coordinates of the ray hit on wall
 * @horizontal_wall_content: content of the wall at ray hit
 * @next_horizontal_touch_x: check at next tile hit if ray
 * in x coordinates is a wall
 * @next_horizontal_touch_y: check at next tile hit if ray
 * in y coordinates is a wall
 * @horizontal_hit_distance: necessary to chose the smallest hit distance
 *** VERTICAL ***
 * @found_vertical_wall_hit: TRUE for wall hit, FALSE otherwise
 * @vertical_wall_hit_x: x coordinates of the ray hit on wall
 * @vertical_wall_hit_y: y coordinates of the ray hit on wall
 * @vertical_wall_content: content of the wall at ray hit
 * @next_vertical_touch_x: check at next tile hit if ray
 * in x coordinates is a wall
 * @next_vertical_touch_y: check at next tile hit if ray
 * in y coordinates is a wall
 * @vertical_hit_distance: necessary to chose the smallest hit distance
 */

struct coll_detect_struct
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
} cd;

/**
 * struct wall_texture_struct - the wall textures
 *
 * @upng_texture: png texture to render
 * @width: texture width
 * @height: texture height
 * @texture_buffer: texture buffer
 */

struct wall_texture_struct
{
	upng_t *upng_texture;
	int width;
	int height;
	uint32_t *texture_buffer;
} wall_textures[NUM_TEXTURES];

/**
 * struct generation_3D_struct - variables for the generate3DProjection funct
 *
 * @wall_strip_height: wall height
 * @wall_top_pixel: top pixel of the wall
 * @wall_bottom_pixel: bottom pixel of the wall
 * @texture_offset_x: texture offset in x of the walls
 * @texture_offset_y: texture offset in y of the walls
 * @distance_from_top: distance from wall top
 * @texture_number: the texture number
 * @perpendicular_distance: perpendicular distance from the wall
 * @distance_from_projection: distance from the walls
 * @projected_wall_height: the projected height of the wall
 * @texel_color: the texture color
 */

struct generation_3D_struct
{
	int wall_strip_height;
	int wall_top_pixel;
	int wall_bottom_pixel;
	int texture_offset_x;
	int texture_offset_y;
	int distance_from_top;
	int texture_number;
	float perpendicular_distance;
	float distance_from_projection;
	float projected_wall_height;
	uint32_t texel_color;
} gen;

/***************************/
/*** FUNCTIONS BY FILES ****/
/***************************/

/* setup_struct */
void setupRendering(void);
void setupPlayer(void);
void setupCollDetect(void);

/* rendering */
void initializeWindow(void);
void initializeRenderer(void);
void render(void);
void renderMap(void);
void renderPlayer(void);

/* rendering_2 */
void renderRays(void);
void renderColorBufferTexture(void);

/* color_buffer */
void allocateColorBuffer(void);
void clearColorBuffer(uint32_t color);

/* texture */
void initializeTextureColor(void);
void loadWallTextures(void);
void freeWallTexture(void);

/* player_movements */
float deltaTime(float delta_time, int ticks_last_frame);
int ticksLastFrame(int ticks_last_frame);
void update(float delta_time, int ticks_last_frame);
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
void searchHorizontalWall(float ray_angle);
void searchVerticalWall(float ray_angle);
void smallestHitDistance(int strip_id, float ray_angle);

/* 3D_generation */
void wallTopPixel(void);
void wallBottomPixel(void);
void textureOffsetX(int i);
void renderWallTexture(int y, int i);
void generate3DProjection(void);

/* free_quit */
void destroyAndQuit(void);

/* errors */
void exitWithError(char *message);

#endif /* MAZE_H */
