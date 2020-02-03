/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printxX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:18:10 by mlaplana          #+#    #+#             */
/*   Updated: 2019/12/06 11:43:14 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_else(t_flags *iflags, char c)
{
	int		j;
	char	*s;

	s = malloc(sizeof(char) * 2);
	s[0] = c;
	s[1] = '\0';
	if (iflags->point == 1 && iflags->number2 > 0 && iflags->ast2 > 0)
		s = ft_strdup("");
	if (iflags->point == 1 && iflags->number > iflags->number2)
		s = ft_strjoin(fill_zeros(iflags, ft_strlen(s) + 1), s);
	else if (iflags->number > iflags->number2)
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

void	print_n(va_list argptr, t_flags *iflags)
{
	int *l;

	l = va_arg(argptr, void*);
	if (l == NULL)
		return ;
	*l = iflags->dev;
}

int		print_x(va_list argptr, t_flags *iflags)
{
	unsigned long	res;
	char			*s;
	int				j;

	res = va_arg(argptr, unsigned int);
	if (res < 0)
		s = ft_itoa_lowhex(UINT64_MAX - res);
	else if ((iflags->point == 1 && iflags->number2 > 0 && iflags->ast2 > 0)
		|| (res == 0 && iflags->point == 1 && iflags->astval2 >= 0))
		s = ft_strdup("");
	else
		s = ft_itoa_lowhex(res);
	s = ft_strjoin(fill_zeros(iflags, ft_strlen(s)), s);
	if (iflags->hashtag == 1)
		s = ft_strjoin("0x", s);
	j = ft_strlen(s) + printear(iflags, s);
	free(s);
	return (j);
}

int		print_mayusx(va_list argptr, t_flags *iflags)
{
	unsigned long	res;
	char			*s;
	int				j;

	res = va_arg(argptr, unsigned int);
	if (res < 0)
		s = ft_itoa_uphex(UINT64_MAX - res);
	else if ((iflags->point == 1 && iflags->number2 > 0 && iflags->ast2 > 0)
		|| (res == 0 && iflags->point == 1 && iflags->astval2 >= 0))
		s = ft_strdup("");
	else
		s = ft_itoa_uphex(res);
	s = ft_strjoin(fill_zeros(iflags, ft_strlen(s)), s);
	if (iflags->hashtag == 1)
		s = ft_strjoin("0X", s);
	j = ft_strlen(s) + printear(iflags, s);
	free(s);
	return (j);
}
