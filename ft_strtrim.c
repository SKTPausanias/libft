/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:57:16 by mlaplana          #+#    #+#             */
/*   Updated: 2019/11/14 16:20:06 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*slice(char *s1, int i, int j)
{
	char	*s2;
	int		k;

	k = 0;
	if (!(s2 = malloc(sizeof(char) * ((j - i) + 2))))
		return (NULL);
	while (i <= j)
	{
		s2[k] = s1[i];
		k++;
		i++;
	}
	s2[k] = '\0';
	return (s2);
}

static int		comprobar(const char *set, char c)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	str = (char*)s1;
	while (comprobar(set, s1[i]) == 1)
	{
		i++;
		if (i == j)
		{
			return (ft_strdup(""));
		}
	}
	while (comprobar(set, s1[i]) == 1)
		i++;
	while (comprobar(set, s1[j]) == 1)
		j--;
	str = slice(str, i, j);
	return (str);
}
