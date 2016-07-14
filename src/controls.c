/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 07:54:39 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/14 23:40:28 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		quitwin()
{
	//VV FREE MALLOCS BELOW VV
	//free lists();
	exit(0);
}

int		key_press(int keycode)
{
	printf("key: %i \n", keycode);
	if (keycode == KB_ESC || keycode ==  KB_ESC_X11)
	{
		quitwin();
	}
	return (0);
}
