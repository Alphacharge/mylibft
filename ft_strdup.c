/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humbi <humbi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:02:13 by rbetz             #+#    #+#             */
/*   Updated: 2024/07/11 19:23:47 by humbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1) + 1;
	ptr = malloc(len * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	return ((char *) ft_memcpy(ptr, s1, len));
}
