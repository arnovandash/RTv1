/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 12:50:58 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/15 22:39:18 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

//TODO
//REMOVE PRINTF STATEMENTS

static void	load_data(t_glob *g, char *data, int field)
{
/*
	Type 2 = Camera info
	Type 3 = Cone
	Type 1 = Sphere
*/
	if (g->type == 1)
	{
		(field == 1) ? g->node_s->origin.x = ft_atoi(data) : 0;
		(field == 2) ? g->node_s->origin.y = ft_atoi(data) : 0;
		(field == 3) ? g->node_s->origin.z = ft_atoi(data) : 0;
		(field == 4) ? g->node_s->radius = ft_atoi(data) : 0;
	}
	if (g->type == 2)
	{
		(field == 1) ? g->cam.origin.x = ft_atoi(data) : 0;
		(field == 2) ? g->cam.origin.y = ft_atoi(data) : 0;
		(field == 3) ? g->cam.origin.z = ft_atoi(data) : 0;
		(field == 4) ? g->cam.dir.x = ft_atoi(data) : 0;
		(field == 5) ? g->cam.dir.y = ft_atoi(data) : 0;
		(field == 6) ? g->cam.dir.z = ft_atoi(data) : 0;
		(field == 7) ? g->cam.fov = ft_atoi(data) : 0;
	}
}

void		get_data(t_glob *g)
{
	char	*data;
	int		i;

	g->data_field = 0;
	i = 0;
	(data = (char *)malloc(sizeof(char) * 11)) ? 0 : error(1);
	while (*g->env.cursor != '\0')
	{
		if ((*g->env.cursor >= '0') && (*g->env.cursor <= '9'))
			data[i++] = *(g->env.cursor);
		if ((*g->env.cursor == ',') || (*g->env.cursor == ')'))
		{
			g->data_field++;
			data[i++] = '\0';
			load_data(g, data, g->data_field);
			i = 0;
		}
		g->env.cursor++;
	}
	if(g->type == 1)
	{
		g->node_s->next = (t_sphere_list *)malloc(sizeof(t_sphere_list));
		g->node_s = g->node_s->next;
	}
	free(data);
}

void	get_scene(t_glob *g, char *file)
{
	g->head_s = NULL;
	((g->env.fd = open(file, O_RDONLY)) == -1) ? error(3) : 0;
	while (get_next_line(g->env.fd, &g->env.cursor))
	{
		while (*g->env.cursor != '\0')
		{
			if ((*(g->env.cursor++) == 'c') && (*g->env.cursor == 'a') && (g->cam_read == 0))
			{
				printf("Im Here\n");
				printf("CURSOR: %s\n", g->env.cursor);
				g->type = 2;
				g->cam_read = 1;
				get_data(g);
			}
			else if ((*(g->env.cursor++) == 's') && *g->env.cursor == 'p')
			{
				printf("HI\n");
				printf("CURSOR1: %s\n", g->env.cursor);
				if (g->head_s == NULL)
				{
					g->head_s = (t_sphere_list *)malloc(sizeof(t_sphere_list));
					g->node_s = g->head_s;
				}
				g->type = 1;
				get_data(g);
			}
		//	else if (*g->env.cursor == '\0')
		//		g->env.cursor++;
		//	printf("CURSTFGD: %c\n", *g->env.cursor);
		}
	}
	g->node_s->next = NULL;
//	(g->head_s != NULL)= g->head_s = g->node_s:0;
	close(g->env.fd);
}
