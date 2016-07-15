/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 13:35:35 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/15 19:58:58 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//TODO
//hook up malloc NULL errors
//free all mallocs
//cone
//cylinder
//sphere




#include "rtv1.h"


int		main(int argc, char **argv)
{

	t_glob		g;

//	g.spheres = 0;
	g.type = 0;
	g.cam_read = 0;
	if (argc == 2)
	{
		get_scene(&g, argv[1]);

		t_sphere_list *ptr = g.head_s;
		printf("T-spe: %p\n", ptr);
		printf("g.head_s %p\n", g.head_s);
		ptr = sort_list(g.head_s);

/*
		printf("PRINTLIST:\n");
	while (ptr->next != NULL)
	{
		printf("origx %i, origy %i origz: %i radius: %i\n",ptr->orig_x, ptr->orig_y, ptr->orig_z, ptr->radius);
		ptr = ptr->next;
	}
		printf("CAMERA VALUES:\n");
		printf("Origin - \n x: %d\n y: %d\n z: %d\n", g.cam.orig_x, 
				g.cam.orig_y, g.cam.orig_z);
		printf("Direction - \n x: %d\n y: %d\n z: %d\n", g.cam.dir_x, 
				g.cam.dir_y, g.cam.dir_z);
		printf("FOV: %f\n", g.cam.fov);
*/
		g.env.mlx = mlx_init();
		g.env.win = mlx_new_window(g.env.mlx, WIN_W, WIN_H, "RTv1");
	
		render(&g);
		mlx_hook(g.env.win, 2, (1L << 0), &key_press, &g);
		mlx_hook(g.env.win, 17, 0L, &quitwin, &g.env);
		mlx_loop(g.env.mlx);
	}
	else
		error(2);
	return (0);
}
