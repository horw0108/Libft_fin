/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:13:38 by niijima           #+#    #+#             */
/*   Updated: 2026/05/03 12:17:08 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*uc_dest;
	unsigned char	*uc_src;

	if (!dest && !src)
		return (NULL);
	uc_dest = (unsigned char *)dest;
	uc_src = (unsigned char *)src;
	while (n--)
	{
		*uc_dest = *uc_src;
		uc_dest++;
		uc_src++;
	}
	return (dest);
}
