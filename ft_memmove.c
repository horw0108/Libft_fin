/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:10:10 by niijima           #+#    #+#             */
/*   Updated: 2026/05/06 09:49:39 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cpy_str(unsigned char *uc_dest, unsigned char *uc_src, size_t n)
{
	if (uc_dest < uc_src)
	{
		while (n--)
		{
			*uc_dest = *uc_src;
			uc_dest++;
			uc_src++;
		}
	}
	else
	{
		uc_dest += n -1;
		uc_src += n -1;
		while (n--)
		{
			*uc_dest = *uc_src;
			uc_dest--;
			uc_src--;
		}
	}
	return ;
}

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
	cpy_str(uc_dest, uc_src, n);
	return (dest);
}
