/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:10:10 by niijima           #+#    #+#             */
/*   Updated: 2026/05/13 12:14:00 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*uc_dest;
	unsigned char	*uc_src;

	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	uc_dest = (unsigned char *)dest;
	uc_src = (unsigned char *)src;
	if (uc_dest < uc_src)
	{
		while (n--)
			*uc_dest++ = *uc_src++;
	}
	else
	{
		while (n--)
			*(uc_dest + n) = *(uc_src + n);
	}
	return (dest);
}
