/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:27:07 by rbetz             #+#    #+#             */
/*   Updated: 2023/04/07 13:45:05 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *str)
{
	long			sign;
	unsigned long	nbr;

	sign = 1;
	nbr = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	else if (*str == '+')
		str++;
	if (!ft_strisdigit(str))
		return (0);
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + *(str++) - '0';
		if (nbr > INT64_MAX && sign == -1)
			return (0);
		else if (nbr > (INT64_MAX - 1) && sign == 1)
			return (-1);
	}
	return ((long)(nbr * sign));
}
