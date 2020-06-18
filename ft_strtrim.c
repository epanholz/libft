/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: epanholz <epanholz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 17:55:48 by epanholz       #+#    #+#                */
/*   Updated: 2019/11/15 16:16:06 by epanholz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(char s1, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (0);
		i++;
	}
	return (1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	if (!s1)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	k = ft_strlen(s1) - 1;
	while (s1[i] && (ft_check(s1[i], set) == 0))
		i++;
	while (k > 0 && (ft_check(s1[k], set) == 0))
	{
		k--;
		j++;
	}
	if (i == (int)ft_strlen(s1))
		return (ft_strdup(""));
	new = ft_substr(s1, i, ft_strlen(s1) - i - j);
	if (new == NULL)
		return (NULL);
	return (new);
}
