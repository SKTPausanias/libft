/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:50:36 by mlaplana          #+#    #+#             */
/*   Updated: 2019/11/12 13:57:46 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count(char const *s, char c)
{
	int		k;
	size_t	count;

	count = 0;
	k = 0;
	while (s[k] && s[k] == c)
		k++;
	while (s[k])
	{
		while (s[k] && s[k] == c)
			k++;
		if (s[k])
		{
			while (s[k] && s[k] != c)
				k++;
			count++;
		}
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		k;
	size_t	j;
	int		start;

	if (!s || !(tab = (char **)malloc(sizeof(char *) * (count(s, c) + 1))))
		return (NULL);
	k = 0;
	j = 0;
	while (s[k])
	{
		if (s[k] == c)
			k++;
		else
		{
			start = k;
			while (s[k] && s[k] != c)
				k++;
			tab[j++] = ft_substr(s, start, k - start);
		}
	}
	tab[j] = NULL;
	return (tab);
}
