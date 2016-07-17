/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 20:39:46 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/17 15:43:20 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
static int		find_roots(float nearest, float discriminant, float b)
{
	float	x1;
	float	x2;
	t_glob	g;

	x1 = (b * -1) - (sqrtf(discriminant) / 2);
	x2 = (b * -1) + (sqrtf(discriminant) / 2);

	if (x1 > x2)
		x1 = x2;

	if ((x1 > 0.001f) && (x1 < nearest))
	{
		g.nearest = x1;
		return (1);
	}
	else
		return (0);
}

int		calc_sphere(t_ray ray, t_sphere sphere, float near)
{
	float a;
	float b;
	float c;
	float discriminant;
	t_vector dist;

	a = dot_prod(ray.dir, ray.dir);
	dist = subtract_vec(ray.start, sphere.origin);
	b =  2 * dot_prod(ray.dir, dist);
	c = (dot_prod(dist, dist) - (sphere.radius * sphere.radius));
	discriminant = (b * b - 4 * a * c);
	if (discriminant < 0)
		return (0);
	else
		return (find_roots(near, discriminant, b));
}

static void		calc_shadow(t_glob *g)
{
	t_obj_list	*ptr;
	float		red_effect;
	float		green_effect;
	float		blue_effect;

	red_effect = g->current_light.intensity.r * g->current_mat.diffuse.r;
	green_effect = g->current_light.intensity.g * g->current_mat.diffuse.g;
	blue_effect = g->current_light.intensity.b * g->current_mat.diffuse.b;
	ptr = g->head;
	while (ptr->next != NULL)
	{
		if (calc_sphere(g->light_ray, ptr->sphere, g->nearest))
		{
			g->in_shadow = 1;
		}
		if (g->in_shadow == 0)
		{
			g->lambert = dot_prod(g->light_ray.dir, g->normal) * g->coef; 
			g->red += g->lambert * red_effect;
			g->green += g->lambert * green_effect;
			g->blue += g->lambert * blue_effect;
		}
		ptr = ptr->next;
	}
}


////////////////SPHERE INTERSECT BACKUP///////////
/*
int		calc_sphere(t_glob *g, t_obj_list *read)
{
	float a;
	float b;
	float c;
	float discriminant;

	a = dot_prod(g->cam.dir, g->cam.dir);
	g->dist = subtract_vec(g->ray.start, read->sphere.origin);
	b =  2 * dot_prod(g->cam.dir, g->dist);
	c = (dot_prod(g->dist, g->dist) - (read->sphere.radius * read->sphere.radius));
	discriminant = (b * b - 4 * a * c);
	if (discriminant < 0)
		return (0);
	else
		return (find_roots(g, discriminant, b));
}
*/


void		calc_light(t_glob *g)
{
	t_obj_list	*ptr;

	ptr = g->head;

	while (ptr->next != NULL)
	{
		if (ft_strcmp("light node", ptr->obj_name) == 0)
		{
			g->current_light = ptr->light;
			g->dist = subtract_vec(g->current_light.origin, g->new_start);

			if(dot_prod(g->normal, g->dist) <= 0.0f)
			{
				ptr = ptr->next;
				continue;
			}
			g->nearest = sqrtf(dot_prod( g->dist, g->dist));
			if(g->nearest <= 0.0f)
			{
				ptr = ptr->next;
				continue;
			}
			g->light_ray.start = g->new_start;
			g->light_ray.dir = scale_vec((1/g->nearest), g->dist);
			g->in_shadow = 0;
			calc_shadow(g);

			//Iterate over the reflection 
			g->coef *= g->current_mat.reflection;

			//The reflected ray start and direction
			g->ray.start = g->new_start;
			g->reflect = 2.0f * dot_prod(g->ray.dir, g->normal);
			t_vector tmp = scale_vec(g->reflect, g->normal);
			g->ray.dir = subtract_vec(g->ray.dir, tmp);

			g->level++;

			ptr = ptr->next;	
		}
	}
}




void		get_material(t_glob *g, int num)
{
	t_obj_list	*ptr;

	ptr = g->head;
	while (ptr->next != NULL)
	{
		if (ft_strcmp("material node", ptr->obj_name) == 0)
			if (ptr->material.num == num)
				g->current_mat = ptr->material;
	}
}


