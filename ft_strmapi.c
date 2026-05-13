/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:59:02 by niijima           #+#    #+#             */
/*   Updated: 2026/05/08 11:31:56 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*answer;
	unsigned int	len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	answer = malloc(sizeof(char) * (len + 1));
	if (!answer)
		return (NULL);
	i = 0;
	while (i < len)
	{
		answer[i] = f(i, s[i]);
		i++;
	}
	answer[i] = '\0';
	return (answer);
}
