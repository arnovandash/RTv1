/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 12:07:18 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/17 11:31:09 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void		draw(t_glob *g, int x, int y)
{
	g->env.data[((int)x * 4) + (y * g->env.size_line) + 2] = 100;
	g->env.data[((int)x * 4) + (y * g->env.size_line) + 1] = 87;
	g->env.data[((int)x * 4) + (y * g->env.size_line)] = 230;
}

static int		calc(t_glob *g, t_obj_list *read, int hit)
{
	t_vector	scaled;
	t_vector	new_start;
	t_vector	n;
	float		temp;


	if (ft_strcmp("sphere", read->obj_name) == 0)
		hit = calc_sphere(g, read);
	scaled = scale_vec(g->closest, g->ray.dir);
	new_start = add_vec(g->ray.start, scaled);
	n = subtract_vec(new_start, read->sphere.origin);
	temp = dot_prod(n, n);
	(temp == 0)? return (0) : 0; ////check case

	temp = 1.0f / sqrtf(temp);
	n = scale_vec(temp, n);

	
////////////////////WARNING!!! MESSY CODE AHEAD!!!!!//////////////////////
	
	


/* Find the material to determine the colour */
	material current_mat = materials[spheres[currentSphere].material];

	// iterate through list to hit light!!!!!

	/* Find the value of the light at this point */
	unsigned int j;
	for(j=0; j < 3; j++) // iterate through lights
	{
		t_light current_light = //current light from list lights[j];
		t_vector dist = subtract_vec(g->light.origin, new_start);
		if(dot_prod(n, dist) <= 0.0f) continue; //!!restart loop for next light
		
	////////// WTF ////////////
		float t = sqrtf(dot_prod( dist, dist));
		if(t <= 0.0f) continue; //!!restart loop for next light
		
	////////// WTF ////////////


		t_ray light_ray;
		light_ray.start = new_start;
		light_ray.dir = scale_vec((1/t), dist);

		/* Calculate shadows */
		g->in_shadow = 0;
		unsigned int k;
		for (k = 0; k < 3; ++k) { //iterate through list
			if (calc_sphere(light_ray, t_obj_list sphere)){
				g->in_shadow = 1;
				break;
			}
		}
		if (g->in_shadow == 0)
		{
			/* Lambert diffusion */
			g->lambert = dot_prod(light_ray.dir, n) * g->coef; 
			g->red += g->lambert * current_light.intensity.r * current_mat.diffuse.r;
			g->green += g->lambert * current_light.intensity.g * current_mat.diffuse.g;
			g->blue += g->lambert * current_light.intensity.b * current_mat.diffuse.b;
		}
	}
	/* Iterate over the reflection */
	g->coef *= current_mat.reflection;

	/* The reflected ray start and direction */
	g->ray.start = new_start;
	g->reflect = 2.0f * dot_prod(g->ray.dir, n);
	t_vector tmp = scale_vec(g->reflect, n);
	g->ray.dir = subtract_vec(g->ray.dir, tmp);

	g->level++;



	//////////////////// STRUCTURE THIS SHIT MOTHERFUCKER ///////////////////////

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
