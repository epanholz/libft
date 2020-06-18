/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: epanholz <epanholz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 13:13:20 by epanholz       #+#    #+#                */
/*   Updated: 2019/11/20 14:08:57 by epanholz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*new;

	new = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s1, ft_strlen(s1) + 1);
	return (new);
}
