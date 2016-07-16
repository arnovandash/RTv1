/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 07:54:39 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/16 21:17:51 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		quitwin(t_glob *g)
{
	t_obj_list	*tmp;
	
	//VV FREE MALLOCS BELOW VV
	//free lists();
	tmp = g->head;
	while (tmp != NULL)
	{
		g->current = tmp;
		tmp = g->current->next;
		free(g->current);
	}
//	mlx_destroy_image(g->env.mlx, g->env.img);
//	mlx_destroy_window(g->env.mlx, g->env.win);
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
