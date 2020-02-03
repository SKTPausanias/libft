/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:44:44 by mlaplana          #+#    #+#             */
/*   Updated: 2019/12/06 11:41:35 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		digits2(unsigned int nb)
{
	unsigned int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char			*s;
	unsigned int	i;
	unsigned int	m;

	m = n;
	i = digits2(m);
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i--] = '\0';
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
