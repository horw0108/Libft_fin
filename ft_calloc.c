/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 09:51:29 by niijima           #+#    #+#             */
/*   Updated: 2026/05/08 11:40:51 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*list;

	if (size == 0 || nmemb == 0)
	{
		size = 0;
		nmemb = 1;
	}
	if (size > (SIZE_MAX / nmemb))
		return (NULL);
	list = malloc(size * nmemb);
	if (!list)
		return (NULL);
	ft_memset(list, '\0', size * nmemb);
	return (list);
}
