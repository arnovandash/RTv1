/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 12:50:58 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/16 12:30:44 by arnovan-         ###   ########.fr       */
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
		(field == 1) ? g->node->origin.x = ft_atoi(data) : 0;
		(field == 2) ? g->node->origin.y = ft_atoi(data) : 0;
		(field == 3) ? g->node->origin.z = ft_atoi(data) : 0;
		(field == 4) ? g->node->radius = ft_atoi(data) : 0;
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
		g->node->next = (t_obj_list *)malloc(sizeof(t_obj_list));
		g->node = g->node->next;
	}
	free(data);
}

void	get_scene(t_glob *g, char *file)
{
	g->head = NULL;
	((g->env.fd = open(file, O_RDONLY)) == -1) ? error(3) : 0;
	while (get_next_line(g->env.fd, &g->env.cursor))
	{
		while (*g->env.cursor != '\0')
		{
			if ((*(g->env.cursor++) == 'c') && (*g->env.cursor == 'a') && (g->cam_read == 0))
			{
				g->type = 2;
				g->cam_read = 1;
				get_data(g);
			}
			else if ((*(g->env.cursor++) == 's') && *g->env.cursor == 'p')
			{
				if (g->head == NULL)
				{
					g->head = (t_obj_list *)malloc(sizeof(t_obj_list));
					g->node = g->head;
				}
				g->type = 1;
				get_data(g);
			}
		}
	}
	g->node->next = NULL;
	close(g->env.fd);
}
