#include "../headers/maze.h"

void generate3DProjection(void)
{
	int i, y;
	int wall_strip_height;
	int wall_top_pixel, wall_bottom_pixel;
	float perpendicular_distance;
	/* player distance from projections */
	float distance_from_projection;
	float projected_wall_height;

	for (i = 0; i < NUM_RAYS; i++)
	{
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
			color_buffer[(WINDOW_WIDTH * y) + i] = 0xFF333333;

		/* render the walls from top to bottom */
		for (y = wall_top_pixel; y < wall_bottom_pixel; y++)
			color_buffer[(WINDOW_WIDTH * y) + i] =
			    rays[i].was_hit_vertical ? 0xFFFFFFFF : 0xFFCCCCCC;

		/* render floor color */
		for (y = wall_bottom_pixel; y < WINDOW_HEIGHT; y++)
			color_buffer[(WINDOW_WIDTH * y) + i] = 0xFF777777;
	}
}
