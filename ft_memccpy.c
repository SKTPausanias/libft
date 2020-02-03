/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:12:00 by mlaplana          #+#    #+#             */
/*   Updated: 2019/11/09 15:44:14 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				bol;
	unsigned char	*dst2;
	unsigned char	*src2;

	c = (unsigned char)c;
	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	bol = 1;
	while (n-- && bol == 1)
	{
		if (*src2 == c)
		{
			bol = 0;
		}
		*dst2 = *src2;
		dst2++;
		src2++;
	}
	if (bol == 1)
		return (0);
	else
		return (dst2);
}
