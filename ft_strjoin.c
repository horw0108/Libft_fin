/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:54:54 by niijima           #+#    #+#             */
/*   Updated: 2026/05/08 11:31:43 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*answer;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	answer = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!answer)
		return (NULL);
	ft_strlcpy(answer, s1, s1len + 1);
	ft_strlcat(answer, s2, s1len + s2len + 1);
	return (answer);
}
