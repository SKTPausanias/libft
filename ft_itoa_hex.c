/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:04:38 by mlaplana          #+#    #+#             */
/*   Updated: 2019/12/06 11:41:14 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		digits_hexa(unsigned long n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_itoa_lowhex(unsigned long n)
{
	char			*s;
	unsigned int	i;
	unsigned long	m;

	m = n;
	i = digits_hexa(m);
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i--] = '\0';
	if (m == 0)
		s[0] = 48;
	while (m > 0)
	{
		if (m % 16 <= 9)
			s[i] = m % 16 + '0';
		else if (m % 16 < 16)
			s[i] = m % 16 + 'W';
		m /= 16;
		i--;
	}
	return (s);
}

char	*ft_itoa_uphex(unsigned long n)
{
	char			*s;
	unsigned int	i;
	unsigned long	m;

	m = n;
	i = digits_hexa(m);
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i--] = '\0';
	if (m == 0)
		s[0] = 48;
	while (m > 0)
	{
		if (m % 16 <= 9)
			s[i] = m % 16 + '0';
		else if (m % 16 < 16)
			s[i] = m % 16 + 55;
		m /= 16;
		i--;
	}
	return (s);
}
