/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 10:51:06 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/14 14:55:02 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	load_cam(t_glob *g, char *data, int col)
{
	(col == 1)?g->cam->orig_x = ft_atoi(data):0;
	(col == 2)?g->cam->orig_y = ft_atoi(data):0;
	(col == 3)?g->cam->orig_z = ft_atoi(data):0;
	(col == 4)?g->cam->dir_x = ft_atoi(data):0;
	(col == 5)?g->cam->dir_y = ft_atoi(data):0;
	(col == 6)?g->cam->dir_z = ft_atoi(data):0;
	(col == 7)?g->cam->fov = ft_atoi(data):0;
}

void		get_cam(t_glob *g)
{
	int		i;

	i = 0;
	(g->data = (char *)malloc(sizeof(char) * 11)) ? 0 : error(1);
	while (*g->env.cursor != '\0')
	{
		if ((*g->env.cursor >= '0') && (*g->env.cursor <= '9'))
			g->data[i++] = *(g->env.cursor);
		if ((*g->env.cursor == ',') || (*g->env.cursor == ')'))
		{
			g->data_field++;
			g->data[i++] = '\0';
			load_cam(g, g->data, g->data_field);
			i = 0;
		}
		g->env.cursor++;
	}
	g->cam_read = 1;
	free(g->data);
}
