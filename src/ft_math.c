/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 09:06:36 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/15 19:47:22 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO
//Check for divide by zero

#include "rtv1.h"

t_vector normalize(t_vector c)
{
	t_vector v;

	v.x = (c.x / magnitude(c));
	v.y = (c.y / magnitude(c));
	v.z = (c.z / magnitude(c));
	return (v);
}

float dot_prod(t_vector a, t_vector b)
{
	float x;
	
	x = ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
	return (x);
}

t_vector cross_prod(t_vector a, t_vector b)
{
	t_vector c;

	c.x = (a.y * b.z - a.z * b.y);
	c.y = (a.z * b.x - a.x * b.z);
	c.z = (a.x * b.y - a.y * b.x);
	return (c);
}

t_vector add_vec(t_vector a, t_vector b)
{
	t_vector c;

	c.x = (a.x + b.x);
	c.y = (a.y + b.y);
	c.z = (a.z + b.z);
	return (c);
}

t_vector multiply_vec(t_vector a, t_vector b)
{
	t_vector c;

	c.x = (a.x * b.x);
	c.y = (a.y * b.y);
	c.z = (a.z * b.z);
	return (c);
}
