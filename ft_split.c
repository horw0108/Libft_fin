/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:56:34 by niijima           #+#    #+#             */
/*   Updated: 2026/05/08 11:34:20 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*is_error(char *split_str, char **answers, size_t now_str)
{
	if (!split_str)
	{
		while (now_str > 0)
		{
			now_str--;
			free (answers[now_str]);
		}
		free (answers);
		return (NULL);
	}
	return (split_str);
}

static char	*split_list(char const *s, char c, size_t *idx)
{
	char	*answer;
	size_t	len;

	len = 0;
	while (s[*idx + len] && s[*idx + len] != c)
		len++;
	answer = malloc(sizeof(char) * (len + 1));
	if (!answer)
		return (NULL);
	len = 0;
	while (s[*idx + len] && s[*idx + len] != c)
	{
		answer[len] = s[*idx + len];
		len++;
	}
	*idx += len;
	answer[len] = '\0';
	return (answer);
}

static size_t	count_list(char const *s, char c)
{
	size_t	count_w;
	size_t	i;

	count_w = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count_w++;
		i++;
	}
	return (count_w);
}

char	**ft_split(char const *s, char c)
{
	char			**answers;
	char			*split_str;
	const size_t	max_str = count_list(s, c);
	size_t			now_str;
	size_t			idx;

	if (!s)
		return (NULL);
	answers = malloc(sizeof(char *) * (max_str + 1));
	if (!answers)
		return (answers);
	now_str = 0;
	idx = 0;
	while (max_str != now_str)
	{
		while (s[idx] && s[idx] == c)
			idx++;
		split_str = split_list(s, c, &idx);
		if (!(is_error(split_str, answers, now_str)))
			return (NULL);
		answers[now_str] = split_str;
		now_str++;
	}
	answers[now_str] = NULL;
	return (answers);
}
