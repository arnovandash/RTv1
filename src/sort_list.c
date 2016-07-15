/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 17:52:44 by kchetty           #+#    #+#             */
/*   Updated: 2016/07/15 18:34:45 by arnovan-         ###   ########.fr       */
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
	t_sphere_list	*tmp;
	float			num;

	tmp = org;
	while (tmp->next != NULL)
	{
		if (num_compare(tmp->orig_z, tmp->next->orig_z) == 1)
		{
			num = tmp->orig_z;
			tmp->orig_z = tmp->next->orig_z;
			tmp->next->orig_z = num;
			tmp = org;
		}
		else
			tmp = tmp->next;
	}
	tmp = org;
	return (tmp);
}
