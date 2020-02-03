/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:59:55 by mlaplana          #+#    #+#             */
/*   Updated: 2019/11/08 06:13:45 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t					ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t h;
	size_t len;

	h = ft_strlen(dst);
	if (dstsize < h)
		h = dstsize;
	len = dstsize - h;
	if (!len)
		return (h + ft_strlen(src));
	i = 0;
	j = h;
	while (j + 1 < dstsize && src[i] != '\0')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (ft_strlen(src) + h);
}
