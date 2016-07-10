/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 12:50:58 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/10 22:06:54 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

//TODO
//REMOVE PRINTF STATEMENTS



static void	load_list(t_glob *g, char *data, int field, int type)
{
/*
	Type 2 = Cylinder
	Type 3 = Cone
	Type 1 = Sphere
*/
	if (type == 1)
	{
	
		
		
		(field == 1)?g->node_s->orig_x = ft_atoi(data):0;
	printf("origx: %i\n", g->node_s->orig_x);
		(field == 2)?g->node_s->orig_y = ft_atoi(data):0;
	printf("origy: %i\n", g->node_s->orig_y);
		(field == 3)?g->node_s->orig_z = ft_atoi(data):0;
	printf("origz: %i\n", g->node_s->orig_z);
		(field == 4)?g->node_s->radius = ft_atoi(data):0;
	printf("rad: %i\n", g->node_s->radius);
	}

}

void		get_sphere(t_glob *g)
{
	char	*data;
	int	field;
	int	i;

	field = 0;
	i = 0;
	(data = (char *)malloc(sizeof(char) * 11))?0:error(1);
	while (*g->env.cursor != '\0')
	{
		if ((*g->env.cursor >= '0') && (*g->env.cursor <= '9'))
			data[i++] = *(g->env.cursor);
		if ((*g->env.cursor == ',') || (*g->env.cursor == ')'))
		{	
			field++;
			data[i++] = '\0';
			load_list(g, data, field, 1);
			i = 0;
		}
		g->env.cursor++;
	}
	g->spheres++;
		free(data);
}

void	get_scene(t_glob *g, char *file)
{
	g->head_s = NULL;
	(g->env.fd = open(file, O_RDONLY))?0:error(3);
	while (get_next_line(g->env.fd, &g->env.cursor))
	{
		while (*g->env.cursor != '\0')
		{
			if ((*(g->env.cursor++) == 's')&& *g->env.cursor == 'p')
			{
				(g->head_s == NULL)?(g->head_s = g->node_s):\
					    (g->node_s = g->node_s->next);
				//	:(g->node_s = g->head_s);
				(g->node_s = (t_sphere_list *)malloc\
				 (sizeof(t_sphere_list)))?0:error(1);
				get_sphere(g);
			}
		}
		g->env.cursor++;
	}
	(g->head_s != NULL)?g->node_s->next = NULL:0;
	close(g->env.fd);
}
