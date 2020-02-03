/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condaux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:15:07 by mlaplana          #+#    #+#             */
/*   Updated: 2019/12/06 11:40:42 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*cambiar_neg(char *s)
{
	int		i;
	char	aux;

	i = 0;
	while (s[i] != '-')
		i++;
	aux = s[i];
	s[i] = s[0];
	s[0] = aux;
	return (s);
}

char	*cond_aux(t_flags *iflags, char *s)
{
	if (iflags->point != 1)
		s = ft_strjoin(fill_zeros(iflags, ft_strlen(s)), s);
	else
		s = ft_strjoin(fill_zeros(iflags, ft_strlen(s) - 1), s);
	s = cambiar_neg(s);
	return (s);
}
