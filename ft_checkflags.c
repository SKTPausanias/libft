/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:21:25 by mlaplana          #+#    #+#             */
/*   Updated: 2019/12/06 11:40:56 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		transformar_n(char *src, int j)
{
	char	*s;
	int		i;
	int		h;

	h = 0;
	i = j;
	while (src[j] >= '0' && src[i] <= '9')
		j++;
	if (!(s = malloc(sizeof(char) * (j - i + 1))))
		return (-1);
	while (src[i] >= '0' && src[i] <= '9')
	{
		s[h] = src[i];
		h++;
		i++;
	}
	s[h] = '\0';
	return (ft_atoi(s));
}

int		bucle(char *src, int i, t_flags *iflags)
{
	while (src[i] == '0' || src[i] == '-' || src[i] == '+' ||
			src[i] == ' ' || src[i] == '#' || src[i] == '\'')
	{
		if (src[i] == '+')
			iflags->plus = 1;
		else if (src[i] == '#')
			iflags->hashtag = 1;
		else if (src[i] == ' ' && iflags->plus != 1)
			iflags->space = 1;
		else if (src[i] == '\'')
			iflags->com = 1;
		else if (src[i] == '-')
			iflags->zero = -1;
		else if (src[i] == '0' && iflags->zero != -1)
			iflags->zero = 1;
		i++;
	}
	return (i);
}

int		cond_if2(char *src, int i, t_flags *iflags)
{
	int j;

	i++;
	iflags->point = 1;
	if (src[i] == '*' || (src[i] >= '0' && src[i] <= '9'))
	{
		if (src[i] == '*')
		{
			i++;
			iflags->ast2 = 1;
		}
		else
		{
			j = i;
			j = transformar_n(src, j);
			while (src[i] >= '0' && src[i] <= '9')
				i++;
			iflags->number2 = j;
		}
	}
	return (i);
}

int		check_flags(char *src, int i, t_flags *iflags)
{
	int j;

	i = bucle(src, i, iflags);
	if (src[i + 1] != '\0')
	{
		if (src[i] == '*' || (src[i] >= '0' && src[i] <= '9'))
		{
			if (src[i] == '*')
			{
				i++;
				iflags->ast = 1;
			}
			else
			{
				j = i;
				j = transformar_n(src, j);
				while (src[i] >= '0' && src[i] <= '9')
					i++;
				iflags->number = j;
			}
		}
	}
	if (src[i] == '.')
		i = cond_if2(src, i, iflags);
	return (i);
}
