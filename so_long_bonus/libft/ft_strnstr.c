/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 03:21:22 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/04 21:20:04 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (haystack[i + j] == needle[j])
		{
			while (j < ft_strlen(needle) && (i + j) < len
				&& haystack[i + j] == needle[j])
				j++;
			if (j == ft_strlen(needle))
				return ((char *)&haystack[i]);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
