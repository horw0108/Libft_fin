/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niijima <niijima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 09:18:44 by niijima           #+#    #+#             */
/*   Updated: 2026/05/13 12:12:33 by niijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	ui_n;

	ui_n = (unsigned int)n;
	if (fd < 0)
		return ;
	if (n < 0)
	{
		write (fd, "-", 1);
		ui_n = -ui_n;
	}
	if (ui_n >= 10)
		ft_putnbr_fd(ui_n / 10, fd);
	c = ui_n % 10 + '0';
	write (fd, &c, 1);
	return ;
}
