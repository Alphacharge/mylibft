/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multijoin_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:08:04 by rbetz             #+#    #+#             */
/*   Updated: 2023/02/22 10:58:28 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy_input(char **array, size_t *lengths, size_t len)
{
	char	*str;
	size_t	i;
	size_t	pos;

	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	pos = 0;
	while (array[i] != NULL)
	{
		ft_memcpy(&str[pos], array[i], lengths[i]);
		pos += lengths[i];
		i++;
	}
	return (str);
}

static size_t	get_total_length(char **array, size_t *lengths)
{
	size_t	total_len;
	size_t	i;

	total_len = 0;
	i = 0;
	while (array[i] != NULL)
	{
		lengths[i] = ft_strlen(array[i]);
		total_len += lengths[i];
		i++;
	}
	return (total_len);
}

/*Combines every string inside array into a single string. Array needs to be
terminated with NULL pointer.
Will not free any string inside the array, but frees the array.*/
char	*ft_multijoin_array(char **array)
{
	size_t	len;
	size_t	*lengths;
	size_t	size;
	char	*str;

	if (array == NULL)
		return (NULL);
	size = ft_arraycount(array);
	lengths = ft_calloc(size, sizeof(size_t));
	if (lengths == NULL)
		return (NULL);
	len = get_total_length(array, lengths);
	str = copy_input(array, lengths, len);
	free(lengths);
	free(array);
	array = NULL;
	return (str);
}
