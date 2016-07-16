/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 20:39:46 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/16 21:06:46 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		calc_sphere(t_glob *g, t_obj_list *read, int hit)
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
		hit = 0;
	else
		hit = 1;
	return (hit);
}
