/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 14:26:54 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/10 17:52:02 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	error(int err)
{
	if (err == 1)
	{
		ft_putstr("Encountered a malloc error\n");
	}
	if (err == 2)
	{
		ft_putstr("Invalid scene file\n");
		ft_putstr("Usage ./rtv1 scene.txt\n");
	}
	if (err == 3)
	{
		ft_putstr("Error opening file\n");
	}
	exit(1);
}
