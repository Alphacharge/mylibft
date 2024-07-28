/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humbi <humbi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:05:07 by rbetz             #+#    #+#             */
/*   Updated: 2024/07/11 20:08:22 by humbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_ns(char *s1, char *s2)
{
	char	*p1;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	p1 = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (p1 == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(p1, s1, len_s1);
	ft_memcpy(&p1[len_s1], s2, len_s2 + 1);
	free(s1);
	return (p1);
}
