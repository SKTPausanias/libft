/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:19:40 by mlaplana          #+#    #+#             */
/*   Updated: 2019/11/10 19:28:07 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst2;
	const unsigned char	*src2;

	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	i = 0;
	if (dst2 || src2)
	{
		if (src2 < dst2)
			while (++i <= len)
				dst2[len - i] = src2[len - i];
		else
			while (len-- > 0)
				*(dst2++) = *(src2++);
		return (dst);
	}
	else
		return (NULL);
}
