/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:06:03 by mlaplana          #+#    #+#             */
/*   Updated: 2019/11/11 18:31:39 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		digits(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	else if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		i;
	long	m;

	m = n;
	i = digits(m);
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i--] = '\0';
	if (m < 0)
	{
		s[0] = '-';
		m *= -1;
	}
	if (m == 0)
		s[0] = 48;
	while (m > 0)
	{
		s[i] = m % 10 + '0';
		m /= 10;
		i--;
	}
	return (s);
}
