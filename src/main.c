/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 13:35:35 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/09 16:04:34 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"





/* SCRATCHPIXEL PSEUDO CODE
 * for (each pixel in the image) {
 * // step 1
 * build a camera ray: trace line from current pixel location to camera's aperture;
 * // step 2
 * cast ray into the scene;
 * // step 3
 * if (ray intersects an object) {
 * set current pixel's color with object's color at the intersection point;
 * }
 * else {
 * set current pixel's color to black;
 * }
 * }
 */







/////////////////// GLOBAL VARIABLES ////////////////////

// has the ray hit the object
//int hit = 0;


///////////////////////////////////////////////////////












//////////////////// SET CAMERA /////////////////////////

//void	camera(t_glob *g)
//{
	// origin
	//	x = WIN_W/2
	//	y = WIN_H/2
	//	Z = 0;
	//
	// direction
	//

//}

///////////////////////////////////////////////////////





//////////////////// RAY CALCULATIONS /////////////////
//void	ray(t_glob *g)
//{
//	float normalized_x;
//	float normalized_y;
	//ray origin set to camera position which is to be determined
//	g->ray.start.x = 0 // = g->ray.camera.x
//		g->ray.start.y = 0 // = g->ray.camera.y
//		g->ray.start.z = 0 // = g->ray.camera.z

		//ray direction
//		g->ray.dir.x = 0;
//	g->ray.dir.y = 0;
//	g->ray.dir.z = 1;

	// find (x,y) pixel coordinates of the object at (x,y,z)
	// subtract camera position from object (x,y,z)

	//normalize x and y pixel positions
	//x and y will be the provided by the counters
	//try this normalization with Wolf3D
//	normalized_x = (x / WIN_W) - 0.5;
//	normalized_y = (y / WIN_H) - 0.5;



	////////////////////////

	/* https://stackoverflow.com/questions/13078243/ray-tracing-camera
	 *
	 Ray ComputeCameraRay(int i, int j) {
	 const float width = 512.0;  // pixels across
	 const float height = 512.0;  // pixels high
	 double normalized_i = (i / width) - 0.5;
	 double normalized_j = (j / height) - 0.5;
	 Vector3 image_point = normalized_i * camera_right +
	 normalized_j * camera_up +
	 camera_position + camera_direction;
	 Vector3 ray_direction = image_point - camera_position;
	 return Ray(camera_position, ray_direction);
	 }

*/
	////////////////



	//}



	///////////////////////////////////////////////////



int		main(int argc, char **argv)
{

	t_glob		g;

	if (argc == 2)
	{
		get_scene(&g, argv[1]);
		g.env.mlx = mlx_init();
		g.env.win = mlx_new_window(g.env.mlx, WIN_W, WIN_H, "RTv1");
		mlx_hook(g.env.win, 2, (1L << 0), &key_press, &g);
		mlx_hook(g.env.win, 17, 0L, &quitwin, &g.env);
		mlx_loop(g.env.mlx);
	}
	else
		ft_error(2);
	return (0);
}
