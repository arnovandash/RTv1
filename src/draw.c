/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 12:07:18 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/17 16:00:16 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void		draw(t_glob *g, int x, int y)
{
	g->red = (unsigned char)min(g->red*255.0f, 255.0f);
	g->green = (unsigned char)min(g->green*255.0f, 255.0f);
	g->blue = (unsigned char)min(g->blue*255.0f, 255.0f);
	g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = g->red;
	g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = g->green;
	g->env.data[((int)x * 4) + (y * g->env.size_line)] = g->blue;

}

static int		calc(t_glob *g, t_obj_list *read, int hit)
{
	if (ft_strcmp("sphere node", read->obj_name) == 0)
		hit = calc_sphere(g->cam, read->sphere, g->nearest);

	get_material(g, read->sphere.material);

	g->scaled = scale_vec(g->nearest, g->ray.dir);
	g->new_start = add_vec(g->ray.start, g->scaled);
	g->normal = subtract_vec(g->new_start, read->sphere.origin);
	g->temp = dot_prod(g->normal, g->normal);
	if (g->temp == 0)
		return (0);

	g->temp = 1.0f / sqrtf(g->temp);
	g->normal = scale_vec(g->temp, g->normal);



	calc_light(g);
	
	return (hit);
}

void			render(t_glob *g)
{
	int x;
	int y;
	int ray_hit;

	g->env.img = mlx_new_image(g->env.mlx, WIN_W, WIN_H);
	g->env.data = mlx_get_data_addr(g->env.img, &g->env.bpp, &g->env.size_line, &g->env.endian);

	ray_hit = 0;
	x = 0;
	y = 0;
	g->ray.start.z = 1;
	printf("RENDERING, PLEASE WAIT...\n");
	while (y < WIN_H)
	{	
		g->level = 0;
		g->ray.start.y = y;
		while (x < WIN_W)
		{
			g->current = g->head;
			while (g->current->next != NULL)
			{
				ray_hit = 0;
				g->ray.start.x = x;
				ray_hit = calc(g, g->current, ray_hit);
				if (ray_hit > 0)
				{
					draw(g, x, y);
				}
				g->current = g->current->next;
			}
			x++;
		}
		x = 0;
		y++;
	}
	y = 0;
	printf("DONE RENDERING\n");
	mlx_put_image_to_window(g->env.mlx, g->env.win, g->env.img, 0, 0);
}
