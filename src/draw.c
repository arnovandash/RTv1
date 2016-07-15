/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 12:07:18 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/15 18:47:36 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void		draw(t_glob *g, int x, int y)
{
	g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 100;
	g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 87;
	g->env.data[((int)x * 4) + (y * g->env.size_line)] = 230;
}

static int		calc(t_glob *g)
{
	t_sphere_list	*read;
	float a;
	float b;
	float c;
	float quadshit
	t_vector	dist;
	


	//float a = dot product raydir * raydir
	//vector dist = subtract vect (ray_start - sphere_pos)
	//float b = 2 * (dot_product (ray direction *	vect dist)
	//float c = dot_product (dist * dist) - (radius * radius)
	//float disc = b * b - 4 * a *c  // Quadratic disc
	// if < 0 == missed else hit!!!!!!!!!!!!!!


		//read object info
/*
	t_vector	vec_x;
	t_vector	vec_y;
	t_vector	vec_z;

	vec_x.x = 1;
	vec_x.y = 0;
	vec_x.z = 0;
	vec_y.x = 0;
	vec_y.y = 1;
	vec_y.z = 0;
	vec_z.x = 0;
	vec_z.y = 0;
	vec_z.z = 1;

	g->ray.start.x = 1
	g->ray.start.y = 1
	g->ray.start.z = 1

	g->ray.dir.x = 0
	g->ray.dir.y = 0
	g->ray.dir.z = 1
*/	
	}	

	return (0);
	}

int			render(t_glob *g)
{
	int x;
	int y;
	int ray_hit;
	t_sphere_list	*read;

	read = g->head_s;


	g->env.img = mlx_new_image(g->env.mlx, WIN_W, WIN_H);
	g->env.data = mlx_get_data_addr(g->env.img, &g->env.bpp, &g->env.size_line, &g->env.endian);

	ray_hit = 0;
	x = 0;
	y = 0;

	printf("RENDERING, PLEASE WAIT...\n");

	while (read->next != NULL)
	{
		while (y < WIN_H)
		{	
			while (x < WIN_W)
			{
				//////////////////// CALC
				//CAST RAY!
				if (ray_hit == 1)
					draw(g, x, y);
				x++;
			}
			x = 0;
			y++;
		}
		read = read->next;
	}
	printf("DONE RENDERING\n");
	mlx_put_image_to_window(g->env.mlx, g->env.win, g->env.img, 0, 0);
	return (0);
}
