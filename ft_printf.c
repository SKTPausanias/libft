/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:39:34 by mlaplana          #+#    #+#             */
/*   Updated: 2019/12/06 11:42:37 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

void	fill_struct(t_flags *iflags)
{
	iflags->point = 0;
	iflags->ast = 0;
	iflags->ast2 = 0;
	iflags->zero = 0;
	iflags->number = 0;
	iflags->number2 = 0;
	iflags->plus = 0;
	iflags->space = 0;
	iflags->hashtag = 0;
	iflags->com = 0;
}

void	cond_if3(va_list argptr, t_flags *iflags, char *src, int i)
{
	if (src[i] == 'c')
		iflags->dev += print_c(argptr, iflags);
	else if (src[i] == 's')
		iflags->dev += print_s(argptr, iflags);
	else if (src[i] == 'p')
		iflags->dev += print_p(argptr, iflags);
	else if (src[i] == 'd' || src[i] == 'i')
		iflags->dev += print_di(argptr, iflags);
	else if (src[i] == 'u')
		iflags->dev += print_u(argptr, iflags);
	else if (src[i] == 'x')
		iflags->dev += print_x(argptr, iflags);
	else if (src[i] == 'X')
		iflags->dev += print_mayusx(argptr, iflags);
	else if (src[i] == 'n')
		print_n(argptr, iflags);
	else
		iflags->dev += print_else(iflags, src[i]);
}

int		cond_dentrowhile(va_list argptr, char *src, int i, t_flags *iflags)
{
	if (src[i] == '%')
	{
		if (src[i + 1] != '\0')
		{
			i = check_flags(src, i + 1, iflags);
			if (iflags->ast == 1)
			{
				iflags->astval1 = va_arg(argptr, int);
				if (iflags->astval1 < 0)
				{
					iflags->zero = -1;
					iflags->astval1 *= -1;
				}
			}
			if (iflags->ast2 == 1)
				iflags->astval2 = va_arg(argptr, int);
			cond_if3(argptr, iflags, src, i);
		}
	}
	else
	{
		ft_putchar(src[i]);
		iflags->dev += 1;
	}
	return (i);
}

int		print_result(va_list argptr, char *src)
{
	int			i;
	t_flags		*iflags;

	if (!(iflags = malloc(sizeof(t_flags))))
		return (-1);
	i = 0;
	fill_struct(iflags);
	iflags->dev = 0;
	while (src[i])
	{
		i = cond_dentrowhile(argptr, src, i, iflags);
		fill_struct(iflags);
		i++;
	}
	return (iflags->dev);
}

int		ft_printf(const char *src, ...)
{
	int			result;
	va_list		argptr;

	va_start(argptr, src);
	result = print_result(argptr, (char*)src);
	va_end(argptr);
	return (result);
}
