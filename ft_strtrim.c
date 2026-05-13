/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:52:12 by niijima           #+#    #+#             */
/*   Updated: 2026/05/08 11:34:33 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			return (i);
		i++;
	}
	return (i);
}

static size_t	check_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			return (i);
		if (i != 0)
			i--;
	}
	return (i);
}

static void	cpystr(char *answer, char const *s1, size_t len, size_t start)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		answer[i] = s1[start + i];
		i++;
	}
	answer[i] = '\0';
	return ;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*answer;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1)
		return (NULL);
	start = check_start(s1, set);
	if (*s1 == '\0' || start == ft_strlen(s1))
		len = 0;
	else
	{
		end = check_end(s1, set);
		if (end < start)
			len = 0;
		else
			len = end - start + 1;
	}
	answer = malloc(sizeof(char) * (len + 1));
	if (!answer)
		return (NULL);
	cpystr(answer, s1, len, start);
	return (answer);
}
