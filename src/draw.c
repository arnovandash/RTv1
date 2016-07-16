/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 12:07:18 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/17 00:34:04 by arnovan-         ###   ########.fr       */
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
//	(temp == 0)?0:0;

	temp = 1.0f / sqrtf(temp);
	n = scale_vec(temp, n);

////////////////////WARNING!!! MESSY CODE AHEAD!!!!!//////////////////////

/* Find the material to determine the colour */
material currentMat = materials[spheres[currentSphere].material];

/* Find the value of the light at this point */
unsigned int j;
for(j=0; j < 3; j++)
{
	t_light currentLight = //current light from list lights[j];
	t_vector dist = subtract_vec(g->light.origin, newStart);
	if(dot_prod(n, dist) <= 0.0f) continue; //WTF?
	float t = sqrtf(dot_prod( dist, dist));
	if(t <= 0.0f) continue;

	t_ray lightRay;
	lightRay.start = newStart;
	lightRay.dir = scale_vec((1/t), dist);

	/* Calculate shadows */
	bool inShadow = false;
	unsigned int k;
	for (k = 0; k < 3; ++k) {
		if (calc_sphere(lightRay, t_obj_list sphere)){
			inShadow = true;
			break;
		}
	}
	if (!inShadow){
		/* Lambert diffusion */
		float lambert = dot_prod(lightRay.dir, n) * coef; 
		red += lambert * currentLight.intensity.red * currentMat.diffuse.red;
		green += lambert * currentLight.intensity.green * currentMat.diffuse.green;
		blue += lambert * currentLight.intensity.blue * currentMat.diffuse.blue;
	}
}
/* Iterate over the reflection */
coef *= currentMat.reflection;

/* The reflected ray start and direction */
g->ray.start = newStart;
float reflect = 2.0f * dot_prod(&r.dir, &n);
t_vector tmp = scale_vec(reflect, n);
g->ray.dir = subtract_vec(g->ray.dir, tmp);

level++;



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
