/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 12:07:18 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/15 09:31:47 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void		draw(t_glob *g, int x, int y)
{
	g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 100;
	g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 87;
	g->env.data[((int)x * 4) + (y * g->env.size_line)] = 230;
}

/*
void		calc(t_glob *g)
{
	g->ray.start.x = 1
	g->ray.start.y = 1
	g->ray.start.z = 1

	g->ray.dir.x = 0
	g->ray.dir.y = 0
	g->ray.dir.z = 1

	double magnitude //returns a scalar
	{
		return (sqrt((x * x) + (y * y) + (z * z)));
	}

	Vect normalize // returns a vector
	{
		return (Vect (x/magnitude, y/magnitude, z/magnitudei));
	}

	Vect negative ()
	{
		return Vect (-x, -y, -z)
	}

	double dot_product (Vect v)
	{		return ( Vector1_X * Vector2_X, Vector1_Y * Vector2_Y, Vector1_z * Vector2_Z)
}

	Vect cross_product (Vect v)
	{		return ( Vector1_X * Vector2_X, Vector1y * Vector2_y, Vector1z * Vector2z)
}
}
*/


int			render(t_glob *g)
{
	int x;
	int y;
	int ray_hit;

	g->env.img = mlx_new_image(g->env.mlx, WIN_W, WIN_H);
	g->env.data = mlx_get_data_addr(g->env.img, &g->env.bpp, &g->env.size_line, &g->env.endian);



	ray_hit = 1;
	x = 0;
	y = 0;

	printf("RENDERING, PLEASE WAIT...\n");
	while (y < WIN_H)
	{	
		while (x < WIN_W)
		{
			//CAST RAY!
			if (ray_hit == 1)
				draw(g, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	printf("DONE RENDERING\n");
	mlx_put_image_to_window(g->env.mlx, g->env.win, g->env.img, 0, 0);
	return (0);
}
