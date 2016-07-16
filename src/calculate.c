/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 20:39:46 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/16 23:41:54 by arnovan-         ###   ########.fr       */
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
	t_vector	dist;

	a = dot_prod(g->cam.dir, g->cam.dir);
	dist = subtract_vec(g->ray.start, read->sphere.origin);
	b =  2 * dot_prod(g->cam.dir, dist);
	c = (dot_prod(dist, dist) - (read->sphere.radius * read->sphere.radius));
	discriminant = (b * b - 4 * a * c);
	if (discriminant < 0)
		return (0);
	else
		return (find_roots(g, discriminant, b));
}
