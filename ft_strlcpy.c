/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: epanholz <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:30:57 by epanholz       #+#    #+#                */
/*   Updated: 2019/11/22 14:32:56 by epanholz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	if (!dst && !src)
		return (0);
	ft_memccpy(dst, src, '\0', dstsize);
	if (dstsize)
		dst[dstsize - 1] = '\0';
	return (ft_strlen(src));
}
