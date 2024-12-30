/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:41:08 by rbetz             #+#    #+#             */
/*   Updated: 2022/03/25 18:31:35 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlower(char *str)
{
	char	*tmp;

	tmp = str;
	if (str == NULL)
		return (NULL);
	while (*tmp != '\0') {
		*tmp = ft_tolower(*tmp);
		tmp++;
	}
	return (str);
}
