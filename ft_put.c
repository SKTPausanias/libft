/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:40:32 by mlaplana          #+#    #+#             */
/*   Updated: 2019/12/06 11:43:34 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int		printear(t_flags *iflags, char *s)
{
	int		j;

	j = 0;
	if (iflags->zero == -1)
	{
		ft_putstr(s);
		j = print_spaces(iflags, ft_strlen(s));
	}
	else
	{
		j = print_spaces(iflags, ft_strlen(s));
		ft_putstr(s);
	}
	return (j);
}
