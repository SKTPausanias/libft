/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zerosandspaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:33:42 by mlaplana          #+#    #+#             */
/*   Updated: 2019/12/06 11:43:49 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_spaces(t_flags *iflags, int len)
{
	int i;

	i = 0;
	if (iflags->ast == 1)
	{
		while (i < iflags->astval1 - len)
		{
			i++;
			ft_putchar(' ');
		}
	}
	else
	{
		while (i < iflags->number - len)
		{
			i++;
			ft_putchar(' ');
		}
	}
	return (i);
}

int		cond_if(t_flags *iflags, int len)
{
	int i;

	i = 0;
	if (iflags->ast == 1)
	{
		while (i < iflags->astval1 - len)
			i++;
	}
	else
	{
		while (i < iflags->number - len)
			i++;
	}
	return (i);
}

int		cond_while(t_flags *iflags, int len)
{
	int i;

	i = 0;
	if (iflags->zero == 1 && iflags->point != 1)
		i = cond_if(iflags, len);
	else if (iflags->point == 1)
	{
		if (iflags->ast2 == 1)
		{
			while (i < iflags->astval2 - len)
				i++;
		}
		else
		{
			while (i < iflags->number2 - len)
				i++;
		}
	}
	return (i);
}

char	*fill_zeros(t_flags *iflags, int len)
{
	int		i;
	char	*s;
	int		j;

	i = cond_while(iflags, len);
	s = malloc(sizeof(char) * (i + 1));
	j = 0;
	while (j < i)
	{
		s[j] = '0';
		j++;
	}
	s[j] = '\0';
	return (s);
}

int		fill_zeros2(t_flags *iflags, int len)
{
	int		i;
	int		j;

	i = cond_while(iflags, len);
	j = 0;
	while (j < i)
	{
		ft_putchar('0');
		j++;
	}
	return (j);
}
