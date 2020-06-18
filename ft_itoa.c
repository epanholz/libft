/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: epanholz <epanholz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 14:59:23 by epanholz       #+#    #+#                */
/*   Updated: 2019/11/15 17:53:21 by epanholz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_count(long n)
{
	long j;

	j = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		j++;
	while (n != 0)
	{
		j++;
		n = n / 10;
	}
	return (j);
}

static char		*ft_fill(char *new, long n, int i)
{
	if (n < 0)
	{
		new[i] = '-';
		n = n * -1;
		i++;
	}
	while (new[i])
		i++;
	if (n < 10)
		new[i] = n + '0';
	else if (n > 9)
	{
		ft_fill(new, n / 10, i);
		ft_fill(new, n % 10, i);
	}
	return (new);
}

char			*ft_itoa(int n)
{
	char	*new;
	long	j;

	j = n;
	new = (char *)ft_calloc((ft_count(j) + 1), sizeof(char));
	if (new == NULL)
		return (NULL);
	new = ft_fill(new, j, 0);
	new[ft_count(n)] = '\0';
	return (new);
}
