/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace_first.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humbi <humbi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:42:33 by rbetz             #+#    #+#             */
/*   Updated: 2024/07/11 19:56:46 by humbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*concat_parts(char *str, char *tofind, char *replace, int pos)
{
	int		str_len;
	int		tofind_len;
	int		replace_len;
	int		new_len;
	char	*newstr;

	str_len = ft_strlen(str);
	tofind_len = ft_strlen(tofind);
	replace_len = ft_strlen(replace);
	new_len = str_len - tofind_len + replace_len;
	newstr = ft_calloc(new_len + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, str, pos);
	ft_memcpy(newstr + pos, replace, replace_len);
	ft_memcpy(newstr + pos + replace_len, str + pos + tofind_len,
			  str_len - pos - tofind_len + 1);
	return (newstr);
}

char	*ft_strreplace_first(char *str, char *tofind, char *replace)
{
	char	*searchstart;
	int		pos;

	searchstart = ft_strstr(str, tofind);
	if (!searchstart)
		return (ft_strdup(str));
	pos = searchstart - str;
	return (concat_parts(str, tofind, replace, pos));
}
