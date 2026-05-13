/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:24:29 by niijima           #+#    #+#             */
/*   Updated: 2026/05/06 18:13:58 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*chars1;
	unsigned char	*chars2;
	size_t			i;

	chars1 = (unsigned char *)s1;
	chars2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*chars1 != *chars2)
			return (*chars1 - *chars2);
		i++;
		chars1++;
		chars2++;
	}
	return (0);
}
