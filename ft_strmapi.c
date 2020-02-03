/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 04:52:09 by mlaplana          #+#    #+#             */
/*   Updated: 2019/11/13 19:47:30 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen((char *)s);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
