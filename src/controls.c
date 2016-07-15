/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 07:54:39 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/15 22:41:43 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		quitwin(t_glob *g)
{
	t_sphere_list	*tmp;
	
	//VV FREE MALLOCS BELOW VV
	//free lists();
	(tmp = (t_sphere_list *)malloc(sizeof(t_sphere_list))) ? 0 : error(1);
	tmp = g->head_s;
	while (tmp->next != NULL)
	{
		g->current_s = tmp;
		tmp = g->current_s->next;
		free(tmp);
	}


	exit(0);
}

int		key_press(int keycode, t_glob *g)
{
	printf("key: %i \n", keycode);
	if (keycode == KB_ESC || keycode ==  KB_ESC_X11)
	{
		quitwin(g);
	}
	return (0);
}
