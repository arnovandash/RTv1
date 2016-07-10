/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 13:35:35 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/10 22:06:56 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//TODO
//hook up malloc NULL errors
//free all mallocs
//cone
//cylinder
//sphere








#include "rtv1.h"



//////////////////// RAY CALCULATIONS /////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////
















int		main(int argc, char **argv)
{

	t_glob		g;

	g.spheres = 0;

	if (argc == 2)
	{
		get_scene(&g, argv[1]);

		t_sphere_list *ptr = g.head_s;

printf("PRINTLIST:\n");
		while (ptr != NULL)
		{
		printf("origx %i, origy %i\n",ptr->orig_x, ptr->orig_y);
//		ptr = ptr->next;
		}


		g.env.mlx = mlx_init();
		g.env.win = mlx_new_window(g.env.mlx, WIN_W, WIN_H, "RTv1");
		mlx_hook(g.env.win, 2, (1L << 0), &key_press, &g);
		mlx_hook(g.env.win, 17, 0L, &quitwin, &g.env);
		mlx_loop(g.env.mlx);
	}
	else
		error(2);
	return (0);
}
