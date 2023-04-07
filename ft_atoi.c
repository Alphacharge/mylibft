/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:27:07 by rbetz             #+#    #+#             */
/*   Updated: 2023/04/07 13:44:52 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				vz;
	unsigned int	c;

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
	if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
	{
		c = c * 10 + *(str++) - '0';
		if (c > INT32_MAX && vz == -1)
			return (0);
		else if (c > (INT32_MAX - 1) && vz == 1)
			return (-1);
	}
	return ((int)(c * vz));
}
