/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:05:07 by rbetz             #+#    #+#             */
/*   Updated: 2022/05/23 15:31:28 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	p1 = malloc(ft_strlen(s1)+ft_strlen(s2)+1 * sizeof(char));
	if (p1 == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(p1, s1, (size_t)ft_strlen(s1));
	ft_memcpy(&p1[ft_strlen(s1)], s2, (size_t)ft_strlen(s2)+1);
	free(s1);
	return (p1);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (n > 0 && (dst != NULL || src != NULL))
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = malloc((ft_strlen(s1)+1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	return ((char *) ft_memcpy(ptr, s1, (size_t)ft_strlen(s1)+1));
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	size = (size_t)ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, &s[start], len);
	ptr[len] = '\0';
	return (ptr);
}
