/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: epanholz <epanholz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/10 13:45:08 by epanholz       #+#    #+#                */
/*   Updated: 2019/11/16 17:59:07 by epanholz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *listnew;
	t_list *temp;

	listnew = *lst;
	while (listnew)
	{
		(*del)(listnew->content);
		temp = listnew;
		listnew = listnew->next;
		free(temp);
	}
	*lst = NULL;
}
