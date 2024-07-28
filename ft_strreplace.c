/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humbi <humbi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:32:03 by rbetz             #+#    #+#             */
/*   Updated: 2024/07/11 19:56:42 by humbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


// This function replaces the first occurrence of 'tofind' with 'replace'
// in 'str'. It modifies the original string 'str' in place. Note: This
// implementation is not safe if 'replace' is longer than 'tofind', as
// it does not allocate additional memory to accommodate a longer
// replacement string.
void	ft_strreplace(char *str, char *tofind, char *replace)
{
	char	*tempstring;
	char	*searchstart;
	int		len;

	len = 0;
	searchstart = ft_strstr(str, tofind);
	tempstring = ft_strdup(str);
	len = ft_strlen(str) - ft_strlen(searchstart);
	str[len] = '\0';
	ft_strlcat(str, replace, ft_strlen(str) + ft_strlen(replace) + 1);
	len += ft_strlen(tofind);
	ft_strlcat(str, &tempstring[len], ft_strlen(tempstring) \
		- ft_strlen(tofind) + ft_strlen(replace) + 1);
	free(tempstring);
}
