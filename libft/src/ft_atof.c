/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 22:18:16 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/17 08:56:55 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float ft_atof(const char* str)
{
	float num = 0;
	float fraction = 0;
	int divisor = 1;
	int sign = 1;
	int in_fraction = 0;

	if (!str || !*str)
		return (0); 
	if (*str == '-')
	{	
		++str;
		sign = -1;
	}
	else if (*str == '+')
		++str;
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
		{
			if (in_fraction)
			{
				fraction = fraction*10 + (*str - '0');
				divisor *= 10;
			}
			else
				num = num*10 + (*str - '0');
		}
		else if (*str == '.')
		{
			if (in_fraction)
				return sign * (num + fraction/divisor);
			else
				in_fraction = 1;
		}
		else
			return sign * (num + fraction/divisor);
		++str;
	}
	return sign * (num + fraction/divisor);
}
