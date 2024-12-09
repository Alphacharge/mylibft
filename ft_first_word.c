/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbetz <rbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:00:51 by rbetz             #+#    #+#             */
/*   Updated: 2022/10/31 10:46:43 by rbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Returns a malloced string to first occurens of c in str from beginning*/
/*or if rev = 1 from the end*/
char	*ft_first_word(const char *str, char limiter, int rev)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if (limiter == '\0')
		limiter = ' ';
	if (rev != 1)
		rev = 0;
	while (str[i] != '\0' && str[i] != limiter)
		i++;
	if (rev == 0)
		ret = ft_calloc(i + 1, sizeof(char));
	else
		ret = ft_calloc(len - i + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	if (rev == 0)
		ft_memcpy(ret, &str[0], i);
	else
		ft_memcpy(ret, &str[i], len - i);
	return (ret);
}
