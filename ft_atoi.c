/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: epanholz <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 16:43:17 by epanholz       #+#    #+#                */
/*   Updated: 2019/11/18 15:11:22 by epanholz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int		ft_check(long result, long sign)
{
	if (LONG_MAX / result <= 10 && sign == 1)
		return (1);
	if (LONG_MAX / result <= 10 && sign == -1)
		return (2);
	return (0);
}

int		ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if (result != 0 && ft_check(result, sign) == 1)
			return (-1);
		if (result != 0 && ft_check(result, sign) == 2)
			return (0);
		i++;
	}
	return (sign * result);
}
