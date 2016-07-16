/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 12:07:18 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/16 12:37:05 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void		draw(t_glob *g, int x, int y)
{
	g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 100;
	g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 87;
	g->env.data[((int)x * 4) + (y * g->env.size_line)] = 230;
}

static int		calc(t_glob *g, t_obj_list *read)
{
	float a;
	float b;
	float c;
	float discriminant;
	t_vector	dist;

	a = dot_prod(g->cam.dir, g->cam.dir);
	dist = subtract_vec(g->ray.start, read->origin);
	b =  2 * dot_prod(g->cam.dir, dist);
	c = (dot_prod(dist, dist) - (read->radius * read->radius));
	discriminant = (b * b - 4 * a * c);
	if (discriminant < 0)
		return (0);
	else
		return (1);
}

int			render(t_glob *g)
{
	int x;
	int y;
	int ray_hit;
	t_obj_list	*read;

	g->env.img = mlx_new_image(g->env.mlx, WIN_W, WIN_H);
	g->env.data = mlx_get_data_addr(g->env.img, &g->env.bpp, &g->env.size_line, &g->env.endian);

	ray_hit = 0;
	x = 0;
	y = 0;
	g->ray.start.z = 1;
	printf("RENDERING, PLEASE WAIT...\n");

	while (y < WIN_H)
	{	
		g->ray.start.y = y;
		while (x < WIN_W)
		{
		read = g->head;
			while (read->next != NULL)
			{
				ray_hit = 0;
				g->ray.start.x = x;
				ray_hit = calc(g, read);
				if (ray_hit == 1)
				{
					draw(g, x, y);
				}
				read = read->next;
			}
			x++;
		}
		x = 0;
		y++;
	}
	y = 0;
	printf("DONE RENDERING\n");
	mlx_put_image_to_window(g->env.mlx, g->env.win, g->env.img, 0, 0);
	return (0);
}
