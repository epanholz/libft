/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: epanholz <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 12:44:44 by epanholz       #+#    #+#                */
/*   Updated: 2019/11/19 15:51:42 by epanholz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void			*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = dst;
	s = src;
	i = 0;
	while (n)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			return (d + (i + 1));
		i++;
		n--;
	}
	return (NULL);
}
