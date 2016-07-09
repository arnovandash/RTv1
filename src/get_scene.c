/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 12:50:58 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/09 18:17:42 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
void	load_objects(t_glob *g, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(3);
	g->map.y = 0;
	while (get_next_line(fd, &g->map.buf))
	{
		g->map.x = 0;
		while (*(g->map.buf) != '\0')
		{
			if ((*(g->map.buf) >= '0') && (*(g->map.buf) <= '9'))
				g->map.x++;
			g->map.buf++;
		}
		g->map.y++;
	}
	g->env.ex = g->map.x;
	g->env.ey = g->map.y;
	g->env.map = (int **)malloc(sizeof(int *) * g->map.y);
				whilft_isdigit(g->env.cursor)!= 1)
	while (++g->map.i <= g->map.x)
		g->env.map[g->map.i] = (int *)malloc(sizeof(int) * g->map.x);
	if (g->env.map == NULL)
		ft_error(1);
	close(fd);
}
*/


void		get_sphere(t_glob *g)
{
	t_sphere_list *node;
	
	node = (t_sphere_list *)malloc(sizeof(t_sphere_list));

	while (ft_isdigit((int)g->env.cursor) != 1)
	{
	// interate until digit
		printf("char: %c\n", *(g->env.cursor));
			g->env.cursor++;
	
	}
}


void	get_scene(t_glob *g, char *file)
{
	g->env.fd = open(file, O_RDONLY);
	g->head = NULL;
	g->current = NULL;
	// READ FILE line
	g->env.cursor++;
	while (get_next_line(g->env.fd, &g->env.cursor))
	{
		while (*(g->env.cursor) != '\0')
		{
			//detect a sphere
			printf("Cursor char: %c\n", *g->env.cursor);
			if (*(g->env.cursor++) == 's')
				if (*g->env.cursor == 'p')
					get_sphere(g); 
			//	printf("!!!!!!!!!!!Cursor char: %c\n", *g->env.cursor);
			//		}




			/*	OLD WOLF MAP CODE
				if ((*(g->map.buf) >= '0') && (*(g->map.buf) <= '9'))
				{
				str[0] = *(g->map.buf);
				g->env.map[g->map.y][g->map.x] = ft_atoi(str);
				g->map.x += 1;
				}
				*/


//			g->env.cursor++;
	}
}
close(g->env.fd);
}
