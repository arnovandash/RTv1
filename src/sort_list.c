/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 17:52:44 by kchetty           #+#    #+#             */
/*   Updated: 2016/07/16 09:34:17 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				num_compare(float i, float j)
{
	if (i < j)
		return (1);
	else
		return (0);
}

t_sphere_list	*sort_list(t_sphere_list *org)
{
	t_sphere_list		*tmp;
	float				y;
	float				x;
	float				z;
	int					rad;
	

	tmp = org;
	while (tmp->next != NULL)
	{
		if (num_compare(tmp->origin.z, tmp->next->origin.z) == 1)
		{
			z = tmp->origin.z;
			x = tmp->origin.x;
			y = tmp->origin.y;
			rad = tmp->radius;     
			tmp->origin.x = tmp->next->origin.x;
			tmp->origin.y = tmp->next->origin.y;
			tmp->origin.z = tmp->next->origin.z;
			tmp->radius = tmp->next->radius;
			tmp->next->origin.x = x;
			tmp->next->origin.y = y;
			tmp->next->origin.z = z;
			tmp->next->radius = rad;
			tmp = org;
		}
		else
			tmp = tmp->next;
	}
	tmp = org;
	return (tmp);
}
