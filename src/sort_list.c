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
	t_sphere_list		*tmp1;

	tmp = org;
	while (tmp->next != NULL)
	{
		if (num_compare(tmp->origin.z, tmp->next->origin.z) == 1)
		{
			tmp1 = tmp->next->next;
			tmp->next->next = tmp->next;
			if (tmp2 == NULL)
				tmp->next = NULL;
			else		
				tmp->next  = tmp2;
			tmp = org;
		}
		else
			tmp = tmp->next;
	}
	tmp = org;
	return (tmp);
}
