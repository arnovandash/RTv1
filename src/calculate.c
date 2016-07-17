/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 20:39:46 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/17 12:13:44 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
static int		find_roots(t_glob *g, float discriminant, float b)
{
	float	x1;
	float	x2;

	x1 = (b * -1) - (sqrtf(discriminant) / 2);
	x2 = (b * -1) + (sqrtf(discriminant) / 2);

	if (x1 > x2)
		x1 = x2;

	if ((x1 > 0.001f) && (x1 < g->closest))
	{
		g->closest = x1;
		return (1);
	}
	else
		return (0);
}

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

/*

	g->scaled = scale_vec(g->closest, g->ray.dir);
	g->new_start = add_vec(g->ray.start, g->scaled);
	g->normal = subtract_vec(g->new_start, read->sphere.origin);
	g->temp = dot_prod(n, n);

	(g->temp == 0)? return (0) : 0; ////check case

	g->temp = 1.0f / sqrtf(g->temp);
	n = scale_vec(g->temp, n);

	
////////////////////WARNING!!! MESSY CODE AHEAD!!!!!//////////////////////
	
	


// Find the material to determine the colour 

	t_material current_mat = materials[spheres[currentSphere].material];

	// iterate through list to hit light!!!!!

	// Find the value of the light at this point
	unsigned int j;
	for(j=0; j < 3; j++) // iterate through lights
	{
		t_light current_light = //current light from list lights[j];
		g->dist = subtract_vec(g->light.origin, g->new_start);
		if(dot_prod(n, g->dist) <= 0.0f) continue; //!!restart loop for next light
		
	////////// WTF ////////////
		float t = sqrtf(dot_prod( g->dist, g->dist));
		if(t <= 0.0f) continue; //!!restart loop for next light
		
	////////// WTF ////////////


		g->light_ray.start = g->new_start;
		g->light_ray.dir = scale_vec((1/t), g->dist);

		// Calculate shadows
		g->in_shadow = 0;
		unsigned int k;
		for (k = 0; k < 3; ++k) { //iterate through list
			if (calc_sphere(g->light_ray, t_obj_list sphere)){
				g->in_shadow = 1;
				break;
			}
		}
		if (g->in_shadow == 0)
		{
			//Lambert diffusion
			g->lambert = dot_prod(g->light_ray.dir, n) * g->coef; 
			g->red += g->lambert * current_light.intensity.r * current_mat.diffuse.r;
			g->green += g->lambert * current_light.intensity.g * current_mat.diffuse.g;
			g->blue += g->lambert * current_light.intensity.b * current_mat.diffuse.b;
		}
	}
	//Iterate over the reflection 
	g->coef *= current_mat.reflection;

	//The reflected ray start and direction
	g->ray.start = g->new_start;
	g->reflect = 2.0f * dot_prod(g->ray.dir, n);
	t_vector tmp = scale_vec(g->reflect, n);
	g->ray.dir = subtract_vec(g->ray.dir, tmp);

	g->level++;



	//////////////////// STRUCTURE THIS SHIT MOTHERFUCKER ///////////////////////

*/
