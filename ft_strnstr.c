/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:48:38 by mlaplana          #+#    #+#             */
/*   Updated: 2019/11/10 20:10:56 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i != len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (needle[j] && (i + j) != len)
			{
				if (haystack[i + j] != needle[j])
					break ;
				j++;
			}
		}
		if (!needle[j])
			break ;
		i++;
	}
	if (!needle[j])
		return ((char *)&haystack[i]);
	return (0);
}
