/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:17:40 by niijima           #+#    #+#             */
/*   Updated: 2026/05/13 09:26:05 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflow(int sign, unsigned long answer, char next)
{
	if (sign == 1)
	{
		if (LONG_MAX / 10 < answer
			|| (LONG_MAX / 10 == answer && LONG_MAX % 10 < next - '0'))
			return (1);
	}
	if (sign == -1)
	{
		if (((unsigned long)LONG_MAX + 1UL) / 10 < answer
			|| (((unsigned long)LONG_MAX + 1UL) / 10 == answer
				&& (unsigned long)LONG_MAX % 10 +1UL
				< (unsigned long)(next - '0')))
			return (-1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int				sign;
	unsigned long	answer;

	sign = 1;
	answer = 0;
	while ((9 <= *nptr && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while ('0' <= *nptr && *nptr <= '9')
	{
		if (overflow(sign, answer, *nptr) == 1)
			return (-1);
		if (overflow(sign, answer, *nptr) == -1)
			return (0);
		answer = answer * 10 + (unsigned long)(*nptr - '0');
		nptr++;
	}
	return ((int)(answer * sign));
}
