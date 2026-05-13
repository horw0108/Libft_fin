/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:19:26 by niijima           #+#    #+#             */
/*   Updated: 2026/05/08 11:34:36 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_list(char *answer, long long_n, int sign, int digits)
{
	answer[digits + sign] = '\0';
	while (digits > 0)
	{
		answer[digits + sign - 1] = long_n % 10 + '0';
		long_n /= 10;
		digits--;
	}
	if (sign == 1)
		answer[0] = '-';
	return ;
}

static long	count_digits(long long_n)
{
	long	digits;

	digits = 0;
	if (long_n == 0)
		return (1);
	while (long_n > 0)
	{
		long_n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*answer;
	int		sign;
	long	long_n;
	long	digits;

	sign = 0;
	long_n = n;
	if (long_n < 0)
	{
		long_n *= -1;
		sign = 1;
	}
	digits = count_digits(long_n);
	answer = malloc(sizeof(char) * (sign + digits + 1));
	if (!answer)
		return (NULL);
	fill_list(answer, long_n, sign, digits);
	return (answer);
}
