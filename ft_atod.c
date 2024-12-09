/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:53:25 by rbetz             #+#    #+#             */
/*   Updated: 2023/04/07 13:41:45 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negativ(char *nbr)
{
	while (nbr && *nbr && ft_isspace(*nbr))
		nbr++;
	if (*nbr == '-')
		return (1);
	return (0);
}

/*converts a string to a double*/
double	ft_atod(char *nbr)
{
	double	res;
	int		i;
	int		j;
	int		sign;

	j = 1;
	sign = 1;
	if (!nbr)
		return (0);
	res = ft_atol(nbr);
	if (is_negativ(nbr))
		sign = -1;
	while (*nbr && *nbr != '.')
		nbr++;
	if (*nbr == '.')
		nbr++;
	i = ft_strlen(nbr);
	while (i-- > 0)
		j *= 10;
	res += (double)ft_atol(nbr) * sign / j;
	return (res);
}
