/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:27:22 by mlaplana          #+#    #+#             */
/*   Updated: 2019/12/06 11:41:54 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_c(va_list argptr, t_flags *iflags)
{
	int		c;
	int		j;

	j = 0;
	c = va_arg(argptr, int);
	if (iflags->point == 1)
		iflags->zero = 0;
	if (iflags->zero == -1)
	{
		ft_putchar(c);
		j = print_spaces(iflags, 1);
	}
	else
	{
		if (iflags->point == 0)
			j = print_spaces(iflags, 1);
		ft_putchar(c);
	}
	return (1 + j);
}

char	*change_s(char *s, t_flags *iflags)
{
	int		i;
	char	*p;

	i = ft_strlen(s) - 1;
	if (iflags->point == 1)
	{
		if (iflags->ast2 == 1)
		{
			while (iflags->astval2 <= i)
				i--;
		}
		else
		{
			while (iflags->number2 <= i)
				i--;
		}
	}
	p = ft_substr(s, 0, i + 1);
	return (p);
}

int		print_s(va_list argptr, t_flags *iflags)
{
	char	*s;
	int		j;

	s = va_arg(argptr, char *);
	if (!s)
		s = ft_strdup("(null)");
	if (iflags->point == 1 || iflags->number2 > 0 || iflags->astval2 > 0)
		s = ft_strdup(change_s(s, iflags));
	else if (iflags->point == 1 && iflags->number2 == 0 && iflags->astval2 == 0)
		s = ft_strdup("");
	else
		s = ft_strjoin(fill_zeros(iflags, ft_strlen(s)), s);
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
	j += ft_strlen(s);
	free(s);
	return (j);
}

int		print_p(va_list argptr, t_flags *iflags)
{
	unsigned long	res;
	char			*s;
	int				j;

	res = va_arg(argptr, unsigned long);
	if (iflags->point == 1 && iflags->number2 == 0 &&
			iflags->ast2 == 0 && res == 0)
		s = ft_strdup("");
	else
		s = ft_itoa_lowhex(res);
	s = ft_strjoin(fill_zeros(iflags, ft_strlen(s)), s);
	s = ft_strjoin("0x", s);
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
	j += ft_strlen(s);
	free(s);
	return (j);
}
