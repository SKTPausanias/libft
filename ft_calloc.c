/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:51:47 by mlaplana          #+#    #+#             */
/*   Updated: 2019/11/10 18:53:39 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!(p = malloc(size * count)))
		return (NULL);
	while (i < count * size)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
