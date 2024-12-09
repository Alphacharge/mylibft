/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:39:00 by rbetz             #+#    #+#             */
/*   Updated: 2022/10/31 10:51:02 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_countdigits(long nbr)
{
	long	n;

	n = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		n++;
	}
	return (n);
}

char	*ft_ltoa(long nbr)
{
	char	*str;
	long	i;
	long	sign;

	i = ft_countdigits(nbr);
	sign = 0;
	if (nbr < 0)
		sign = 1;
	str = malloc(i + sign + 1);
	if (str == NULL)
		return (NULL);
	str[i + sign] = '\0';
	if (sign == 1)
		str[0] = '-';
	while (i > 0)
	{
		if (sign == 1)
			str[i + sign - 1] = (nbr % 10) * -1 + '0';
		else
			str[i + sign - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	return (str);
}
