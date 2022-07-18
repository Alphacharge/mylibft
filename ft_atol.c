/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:27:07 by rbetz             #+#    #+#             */
/*   Updated: 2022/07/18 15:54:56 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_isspace(char c)
{	
	if (c == '\t' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

long	ft_atol(char *str)
{
	long	vz;
	long	c;

	vz = 1;
	c = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		str++;
		vz = -1;
	}
	else if (*str == '+')
		str++;
	if (!strisdigit(str))
		return ((long)(INT32_MIN) - 1);
	while (ft_isdigit(*str))
	{
		c = c * 10 + *(str++) - '0';
		if (c > 2147483648 && vz == -1)
			return ((long)(INT32_MIN) - 1);
		else if (c > 2147483647 && vz == 1)
			return ((long)(INT32_MIN) - 1);
	}
	return ((long)(c * vz));
}
