/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 12:50:58 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/16 23:01:11 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	load_data2(t_glob *g, char *data, int field);
static void	get_scene2(t_glob *g);


//TODO
//REMOVE PRINTF STATEMENTS
//ORGANIZE TYPES NUMERICALLY
//
//

static void	load_data(t_glob *g, char *data, int field)
{
	//ADD obj name
	if (g->type == 1)
	{
		g->node->obj_name = "sphere";
		(field == 1) ? g->node->sphere.origin.x = ft_atoi(data) : 0;
		(field == 2) ? g->node->sphere.origin.y = ft_atoi(data) : 0;
		(field == 3) ? g->node->sphere.origin.z = ft_atoi(data) : 0;
		(field == 4) ? g->node->sphere.radius = ft_atoi(data) : 0;
		(field == 5) ? g->node->sphere.material = ft_atoi(data) : 0;
	}
	if (g->type == 0)
	{
		g->cam_read = 1;
//		(field == 1) ? g->cam.origin.x = ft_atoi(data) : 0;
//		(field == 2) ? g->cam.origin.y = ft_atoi(data) : 0;
//		(field == 3) ? g->cam.origin.z = ft_atoi(data) : 0;
		(field == 4) ? g->cam.dir.x = ft_atoi(data) : 0;
		(field == 5) ? g->cam.dir.y = ft_atoi(data) : 0;
		(field == 6) ? g->cam.dir.z = ft_atoi(data) : 0;
//		(field == 7) ? g->cam.fov = ft_atoi(data) : 0;
	}
	load_data2(g, data, g->data_field);
}


static void	load_data2(t_glob *g, char *data, int field)
{
	if (g->type == 2)
	{
		g->node->obj_name = "light";
		(field == 1) ? g->node->light.origin.x = ft_atoi(data) : 0;
		(field == 2) ? g->node->light.origin.y = ft_atoi(data) : 0;
		(field == 3) ? g->node->light.origin.z = ft_atoi(data) : 0;
		(field == 4) ? g->node->light.intensity.r = ft_atoi(data) : 0;
		(field == 5) ? g->node->light.intensity.g = ft_atoi(data) : 0;
		(field == 6) ? g->node->light.intensity.b = ft_atoi(data) : 0;
	}
	if (g->type == 3)
	{
		g->node->obj_name = "material";
		(field == 1) ? g->node->material.diffuse.r = ft_atoi(data) : 0;
		(field == 2) ? g->node->material.diffuse.g = ft_atoi(data) : 0;
		(field == 3) ? g->node->material.diffuse.b = ft_atoi(data) : 0;
		(field == 4) ? g->node->material.reflection = ft_atof(data) : 0;
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
		if (((*g->env.cursor >= '0') && (*g->env.cursor <= '9')) || (*g->env.cursor == '.'))
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
	if(g->type > 0)
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
			if ((strncmp("Camera", g->env.cursor, 6)) == 0)
			{
				g->type = 0;
				get_data(g);
			}
			else if ((strncmp("Sphere", g->env.cursor, 5)) == 0)
			{
				if (g->head == NULL)
				{
					g->head = (t_obj_list *)malloc(sizeof(t_obj_list));
					g->node = g->head;
				}
				g->type = 1;
				get_data(g);
			}
			get_scene2(g);		
			g->env.cursor++;
		}	
	}
	close(g->env.fd);
}

static void	get_scene2(t_glob *g)
{
	if ((strncmp("Light", g->env.cursor, 5)) == 0)
	{
		g->type = 2;
		get_data(g);
	}
	else if ((strncmp("Material", g->env.cursor, 8)) == 0)
	{
		g->type = 3;
		get_data(g);
	}
}
