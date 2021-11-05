#include "../headers/maze.h"

/**
 * generate3DProjection - generate a 3D projection from strips and raycasting
 *
 * Return: void
 */

void generate3DProjection(void)
{
	int i, y;
	int wall_strip_height, wall_top_pixel, wall_bottom_pixel;
	int texture_offset_x, texture_offset_y;
	int distance_from_top;
	/* texture number from the map content */
	int texture_number;
	float perpendicular_distance;
	/* player distance from projections */
	float distance_from_projection;
	float projected_wall_height;

	uint32_t texel_color;

	/* draw wall for each ray */
	for (i = 0; i < NUM_RAYS; i++)
	{
		/* calculate distance of perpendicular ray, */
		/* would give the fisheye effect euclidean distance */
		perpendicular_distance = rays[i].distance *
					 cos(rays[i].ray_angle - player.rotation_angle);

		distance_from_projection = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		projected_wall_height = (TILE_SIZE / perpendicular_distance) *
					distance_from_projection;

		wall_strip_height = (int)projected_wall_height;

		wall_top_pixel = (WINDOW_HEIGHT / 2) - (wall_strip_height / 2);
		wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;

		wall_bottom_pixel = (WINDOW_HEIGHT / 2) + (wall_strip_height / 2);
		wall_bottom_pixel = wall_bottom_pixel > WINDOW_HEIGHT
					? WINDOW_HEIGHT
					: wall_bottom_pixel;
		/* render ceiling color */
		for (y = 0; y < wall_top_pixel; y++)
			r.color_buffer[(WINDOW_WIDTH * y) + i] = 0xFF990000;

		/* horizontal offset of the tile */
		if (rays[i].was_hit_vertical)
			texture_offset_x = (int)rays[i].wall_hit_y % TILE_SIZE;
		else
			texture_offset_x = (int)rays[i].wall_hit_x % TILE_SIZE;

		texture_number = rays[i].wall_hit_content - 1;

		/* render the walls from top to bottom */
		for (y = wall_top_pixel; y < wall_bottom_pixel; y++)
		{
			distance_from_top = y + (wall_strip_height / 2) - (WINDOW_HEIGHT / 2);
			texture_offset_y = distance_from_top *
					   ((float)TEXTURE_HEIGHT / wall_strip_height);
			texel_color = wall_textures[texture_number].texture_buffer[(TEXTURE_WIDTH * texture_offset_y) + texture_offset_x];

			/* set the color of the wall based on the color from the texture */
			r.color_buffer[(WINDOW_WIDTH * y) + i] = texel_color;
		}

		/* render floor color */
		for (y = wall_bottom_pixel; y < WINDOW_HEIGHT; y++)
			r.color_buffer[(WINDOW_WIDTH * y) + i] = 0xFF003355;
	}
}
