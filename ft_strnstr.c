/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 18:15:01 by niijima           #+#    #+#             */
/*   Updated: 2026/05/03 18:18:18 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*char_big;
	char	*char_little;
	size_t	i;
	size_t	j;

	char_big = (char *)big;
	char_little = (char *)little;
	i = 0;
	if (*little == '\0')
		return (char_big);
	while (char_big[i] && i < len)
	{
		j = 0;
		while (i + j < len && char_little[j]
			&& char_big[i + j] == char_little[j])
			j++;
		if (!char_little[j])
			return (&char_big[i]);
		i++;
	}
	return (NULL);
}
