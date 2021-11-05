#include "../headers/maze.h"

/**
 * wallTopPixel - get the top pixel of the wall
 * 
 * Return: void
 */

void wallTopPixel(void)
{
	gen.wall_top_pixel = (WINDOW_HEIGHT / 2) - (gen.wall_strip_height / 2);
	gen.wall_top_pixel = gen.wall_top_pixel < 0 ? 0 : gen.wall_top_pixel;
}

/**
 * wallBottomPixel - get the bottom pixel of the wall
 * 
 * Return: void
 */

void wallBottomPixel(void)
{
	gen.wall_bottom_pixel = (WINDOW_HEIGHT / 2) + (gen.wall_strip_height / 2);
	gen.wall_bottom_pixel = gen.wall_bottom_pixel > WINDOW_HEIGHT
				? WINDOW_HEIGHT
				: gen.wall_bottom_pixel;
}

/**
 * texureOffsetX - get the horizontal offset of the tile
 * 
 * Return: void
 */

void textureOffsetX(int i)
{
	/* horizontal offset of the tile */
	if (rays[i].was_hit_vertical)
		gen.texture_offset_x = (int)rays[i].wall_hit_y % TILE_SIZE;
	else
		gen.texture_offset_x = (int)rays[i].wall_hit_x % TILE_SIZE;
}

/**
 * renderWallTexture - put texture on the wall
 * 
 * Return: void
 */

void renderWallTexture(int y, int i)
{
	gen.distance_from_top = y + (gen.wall_strip_height / 2) - (WINDOW_HEIGHT / 2);
	gen.texture_offset_y = gen.distance_from_top *
			   ((float)TEXTURE_HEIGHT / gen.wall_strip_height);
	gen.texel_color = wall_textures[gen.texture_number].texture_buffer[
		(TEXTURE_WIDTH * gen.texture_offset_y) + gen.texture_offset_x];

	/* set the color of the wall based on the color from the texture */
	r.color_buffer[(WINDOW_WIDTH * y) + i] = gen.texel_color;
}

/**
 * generate3DProjection - generate a 3D projection from strips and raycasting
 *
 * Return: void
 */

void generate3DProjection(void)
{
	int i, y;

	/* draw wall for each ray */
	for (i = 0; i < NUM_RAYS; i++)
	{
		/* calculate distance of perpendicular ray, */
		/* would give the fisheye effect euclidean distance */
		gen.perpendicular_distance = rays[i].distance *
					 cos(rays[i].ray_angle - player.rotation_angle);

		gen.distance_from_projection = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		gen.projected_wall_height = (TILE_SIZE / gen.perpendicular_distance) *
					gen.distance_from_projection;

		gen.wall_strip_height = (int)gen.projected_wall_height;

		wallTopPixel();
		wallBottomPixel();

		/* render ceiling color */
		for (y = 0; y < gen.wall_top_pixel; y++)
			r.color_buffer[(WINDOW_WIDTH * y) + i] = 0xFF990000;

		textureOffsetX(i);
		gen.texture_number = rays[i].wall_hit_content - 1;

		/* render the walls from top to bottom */
		for (y = gen.wall_top_pixel; y < gen.wall_bottom_pixel; y++)
		{
			renderWallTexture(y, i);
		}

		/* render floor color */
		for (y = gen.wall_bottom_pixel; y < WINDOW_HEIGHT; y++)
			r.color_buffer[(WINDOW_WIDTH * y) + i] = 0xFF003355;
	}
}
