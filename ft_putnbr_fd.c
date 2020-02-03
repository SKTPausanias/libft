/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 04:56:06 by mlaplana          #+#    #+#             */
/*   Updated: 2019/11/08 11:52:23 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		m;
	int		i;
	char	c;

	i = 1;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	m = n;
	while (m > 9)
	{
		m /= 10;
		i *= 10;
	}
	while (i != 0)
	{
		c = ((n / i) % 10) + '0';
		write(fd, &c, 1);
		i /= 10;
	}
}
