/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:05:21 by niijima           #+#    #+#             */
/*   Updated: 2026/05/06 18:12:47 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	dummy;
	t_list	*now_node;
	t_list	*next_node;
	char	*check_f;

	if (!lst || !f || !del)
		return (NULL);
	now_node = &dummy;
	dummy.next = NULL;
	while (lst)
	{
		check_f = f(lst -> content);
		next_node = ft_lstnew(check_f);
		if (!next_node)
		{
			del(check_f);
			ft_lstclear(&dummy.next, del);
			return (NULL);
		}
		now_node -> next = next_node;
		now_node = next_node;
		lst = lst -> next;
	}
	return (dummy.next);
}
