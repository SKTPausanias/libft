/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:45:31 by mlaplana          #+#    #+#             */
/*   Updated: 2019/11/05 18:13:06 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	c = (unsigned char)c;
	while (n--)
	{
		if (str[i] == c)
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}
