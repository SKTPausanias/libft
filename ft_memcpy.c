/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:55:48 by mlaplana          #+#    #+#             */
/*   Updated: 2019/11/10 18:57:37 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*dst2;
	char			*src2;

	dst2 = (char*)dst;
	src2 = (char*)src;
	if (n >= 0 && (dst2 || src2))
	{
		i = 0;
		while (i < n)
		{
			dst2[i] = src2[i];
			i++;
		}
		return (dst);
	}
	else
		return (NULL);
}
