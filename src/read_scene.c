/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 12:50:58 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/14 14:56:20 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

//TODO
//REMOVE PRINTF STATEMENTS
//
	/////// HOOK UP FILE ERROR!!!!!!!!!!!!!!!!!!!!!!




/*
void	env_list(t_glob *g, char *data, int col, int type)
{

	Type 2 = ?????
	Type 3 = Lights
	Type 1 = Camera

}
*/
void	obj_list(t_glob *g, char *data, int col, int type)
{
/*
	Type 2 = Cylinder
	Type 3 = Cone
	Type 1 = Sphere
*/
	if (type == 1)
	{
		(col == 1)?g->node_s->orig_x = ft_atoi(data):0;
		(col == 2)?g->node_s->orig_y = ft_atoi(data):0;
		(col == 3)?g->node_s->orig_z = ft_atoi(data):0;
		(col == 4)?g->node_s->radius = ft_atoi(data):0;
	}
}

void	read_scene(t_glob *g, char *file)
{

		printf("sdfdsfsdfdsffsd");
	/////// HOOK UP FILE ERROR!!!!!!!!!!!!!!!!!!!!!!
	(g->env.fd = open(file, O_RDONLY)) ? 0 : error(3);
	while (get_next_line(g->env.fd, &g->env.cursor))
	{
		while (*g->env.cursor != '\0')
		{
			/*		READ SPHERE		*/
			if ((*(g->env.cursor++) == 's') && *g->env.cursor == 'p')
			{
				if (g->head_s == NULL)
				{
					(g->head_s = (t_sphere_list *)malloc
					 (sizeof(t_sphere_list))) ? 0 : error(1);
					g->node_s = g->head_s;
				}
				get_sphere(g);
			}
			/*		READ CAM		*/
			if ((*(g->env.cursor++) == 'c') && *g->env.cursor == 'a' && 
					(g->cam_read == 0))
				get_cam(g);

		}
	}
	g->node_s->next = NULL;
	close(g->env.fd);
}
