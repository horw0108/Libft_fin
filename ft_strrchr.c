/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:18:49 by niijima           #+#    #+#             */
/*   Updated: 2026/05/03 16:53:36 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cpy;
	char	*answer;

	cpy = (char *)s;
	answer = NULL;
	while (*cpy)
	{
		if (*cpy == (char)c)
			answer = cpy;
		cpy++;
	}
	if ((char)c == '\0')
		return (cpy);
	return (answer);
}
