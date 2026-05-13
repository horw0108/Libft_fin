/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 11:57:27 by niijima           #+#    #+#             */
/*   Updated: 2026/05/01 17:09:56 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*c;

	if (!lst || !del || !*lst)
		return ;
	p = *lst;
	while (p)
	{
		del (p -> content);
		c = p -> next;
		free (p);
		p = c;
	}
	*lst = NULL;
	return ;
}
