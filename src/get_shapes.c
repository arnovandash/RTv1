/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shapes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 10:50:40 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/14 11:02:43 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		get_sphere(t_glob *g)
{
	int		i;

	g->data_field = 0;
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
			obj_list(g, g->data, g->data_field, 1);
			i = 0;
		}
		g->env.cursor++;
	}
	(g->node_s->next = (t_sphere_list *)malloc(sizeof(t_sphere_list))) ? 0 : error(1);
	g->node_s = g->node_s->next;
	free(g->data);
}
