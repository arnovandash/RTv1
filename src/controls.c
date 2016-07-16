/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 07:54:39 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/16 12:34:42 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		quitwin(t_glob *g)
{
	t_obj_list	*tmp;
	
	//VV FREE MALLOCS BELOW VV
	//free lists();
	(tmp = (t_obj_list *)malloc(sizeof(t_obj_list))) ? 0 : error(1);
	tmp = g->head;
	while (tmp->next != NULL)
	{
		g->current = tmp;
		tmp = g->current->next;
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
