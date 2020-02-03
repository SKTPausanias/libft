/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdiuxX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:21:58 by mlaplana          #+#    #+#             */
/*   Updated: 2019/12/06 11:42:19 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_apostrophe(char *str)
{
	int len;

	len = ft_strlen(str);
	if (str[0] != '-')
	{
		if (len > 3)
			return (ft_strjoin(ft_apostrophe(ft_substr(str, 0, (len - 3))),
						ft_strjoin(",", ft_substr(str, (len - 3), 3))));
		else
			return (str);
	}
	else
	{
		if (len > 4)
			return (ft_strjoin(ft_apostrophe(ft_substr(str, 0, (len - 3))),
						ft_strjoin(",", ft_substr(str, (len - 3), 3))));
		else
			return (str);
	}
}

int		print_cond(t_flags *iflags, char *s)
{
	int j;

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

int		print_di(va_list argptr, t_flags *iflags)
{
	char			*s;
	unsigned long	res;
	int				j;

	res = va_arg(argptr, int);
	if ((iflags->point == 1 && iflags->number2 > 0 && iflags->ast2 > 0)
			|| (res == 0 && iflags->point == 1 && iflags->astval2 >= 0))
		s = ft_strdup("");
	else
		s = ft_itoa(res);
	if (iflags->com == 1)
		s = ft_apostrophe(s);
	if (s[0] != '-')
	{
		s = ft_strjoin(fill_zeros(iflags, ft_strlen(s)), s);
		if (iflags->plus == 1)
			s = ft_strjoin("+", s);
		else if (iflags->space == 1)
			s = ft_strjoin(" ", s);
	}
	else
		s = cond_aux(iflags, s);
	j = print_cond(iflags, s);
	return (ft_strlen(s) + j);
}

int		print_u(va_list argptr, t_flags *iflags)
{
	char			*s;
	unsigned int	res;
	int				j;

	res = (unsigned int)va_arg(argptr, unsigned int);
	if (res == 4294967295)
		s = ft_strdup("4294967295");
	else if ((iflags->point == 1 && iflags->number2 > 0 && iflags->ast2 > 0)
		|| (res == 0 && iflags->point == 1 && iflags->astval2 >= 0))
		s = ft_strdup("");
	else
		s = ft_itoa_unsigned(res);
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
	return (ft_strlen(s) + j);
}
