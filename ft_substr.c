/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:55:57 by niijima           #+#    #+#             */
/*   Updated: 2026/05/08 11:34:46 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cpystr(char *cpy, char const *s, unsigned int start, size_t cpylen)
{
	size_t	i;

	i = 0;
	while (i < cpylen)
	{
		cpy[i] = s[start + i];
		i++;
	}
	cpy[i] = '\0';
	return ;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	cpylen;

	if (ft_strlen(s) < start)
	{
		cpy = malloc(1);
		if (!cpy)
			return (NULL);
		*cpy = '\0';
		return (cpy);
	}
	else if (ft_strlen(s) - start < len)
		cpylen = (ft_strlen(s) - start);
	else
		cpylen = len;
	cpy = malloc(sizeof(char) * (cpylen + 1));
	if (!cpy)
		return (NULL);
	cpystr(cpy, s, start, cpylen);
	return (cpy);
}
