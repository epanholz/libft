/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: epanholz <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 16:40:21 by epanholz       #+#    #+#                */
/*   Updated: 2019/11/18 19:56:28 by epanholz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	compare(const char *hay, const char *needle, int i, int length)
{
	int j;

	j = 0;
	while (needle[j] && j < length)
	{
		if (hay[i] != needle[j])
			return (0);
		j++;
		i++;
	}
	return (1);
}

char
	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t nlen;

	i = 0;
	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0] &&
			compare(haystack, needle, i, nlen))
		{
			if (nlen > len - i)
				return (0);
			return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
