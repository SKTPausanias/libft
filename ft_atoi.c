/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:26:44 by mlaplana          #+#    #+#             */
/*   Updated: 2019/11/11 18:20:22 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int						neg;
	unsigned long long		res;
	int						i;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-')
		neg *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res > __LONG_LONG_MAX__) || (i >= 19))
		{
			if (neg == 1)
				return (-1);
			else
				return (0);
		}
		res = res * 10 + (str[i++] - 48);
	}
	return (res * neg);
}
