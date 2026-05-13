/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:54:28 by niijima           #+#    #+#             */
/*   Updated: 2026/05/13 09:25:51 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cpy_s1;
	unsigned char	*cpy_s2;

	cpy_s1 = (unsigned char *)s1;
	cpy_s2 = (unsigned char *)s2;
	while (n > 0 && (*cpy_s1 || *cpy_s2))
	{
		if (*cpy_s1 != *cpy_s2)
			return ((unsigned char)*cpy_s1 - (unsigned char)*cpy_s2);
		n--;
		cpy_s1++;
		cpy_s2++;
	}
	return (0);
}
