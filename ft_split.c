/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: epanholz <epanholz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 12:24:44 by epanholz       #+#    #+#                */
/*   Updated: 2019/11/18 19:31:02 by epanholz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordlen(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int		ft_wordcount(char const *s, char c)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		j++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (j);
}

static	int		ft_count(const char *s, char c, int i, int j)
{
	if (j == 0)
	{
		while (s[i] && s[i] == c)
			i++;
	}
	if (j == 1)
	{
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (i);
}

static void		ft_free(char **new, int j)
{
	while (j)
	{
		j--;
		free(new[j]);
	}
	free(new);
}

char			**ft_split(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = ft_count(s, c, 0, 0);
	j = 0;
	new = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (new == NULL)
		return (NULL);
	while (s[i])
	{
		new[j] = ft_substr(s, i, ft_wordlen(s + i, c));
		if (new[j] == NULL)
		{
			ft_free(new, j);
			return (NULL);
		}
		i = ft_count(s, c, i, 1);
		j++;
	}
	new[j] = NULL;
	return (new);
}
