/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 07:54:39 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/09 15:41:47 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		quitwin()
{
	//VV FREE MALLOCS BELOW VV
	exit(0);
}

int		key_press(int keycode)
{
	if (keycode == KB_ESC)
	{
		quitwin();
	}
	//	g->env.img = mlx_new_image(g->env.mlx, WIN_W, WIN_H);
	//	g->env.data = mlx_get_data_addr(g->env.img, &g->env.bpp, &g->env.size_line,
	//			&g->env.endian);
	//	loops_hook(g);
	//	mlx_put_image_to_window(g->env.mlx, g->env.win, g->env.img, 0, 0);
	return (0);
}
