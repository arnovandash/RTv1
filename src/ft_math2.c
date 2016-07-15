/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 15:52:46 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/15 17:34:03 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////////////REVIEW WHICH FUNCTIONS ARE NOT BING USED/////////


#include "rtv1.h"

float magnitude(t_vector a)
{
	float x;
	
	x = sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
	return (x);
}

t_vector negative(t_vector c)
{
	t_vector v;

	v.x = (c.x * -1);
	v.y = (c.y * -1);
	v.z = (c.z * -1);
	return (v);
}

t_vector subtract_vec(t_vector a, t_vector b)
{
	t_vector c;

	c.x = (a.x - b.x);
	c.y = (a.y - b.y);
	c.z = (a.z - b.z);
	return (c);
}
