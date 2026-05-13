/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 13:49:15 by niijima           #+#    #+#             */
/*   Updated: 2026/05/03 16:24:57 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cpy;

	cpy = (char *)s;
	while (*cpy)
	{
		if (*cpy == (char)c)
			return (cpy);
		cpy++;
	}
	if (*cpy == (char)c)
		return (cpy);
	return (NULL);
}
