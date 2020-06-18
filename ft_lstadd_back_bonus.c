/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: epanholz <epanholz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/10 13:13:37 by epanholz       #+#    #+#                */
/*   Updated: 2019/11/20 15:50:00 by epanholz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *current;

	current = *alst;
	if (!new)
		return ;
	if (current == NULL)
	{
		*alst = new;
		return ;
	}
	if (current->next == NULL)
	{
		current->next = new;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}
