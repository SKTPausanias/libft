/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:51:35 by mlaplana          #+#    #+#             */
/*   Updated: 2019/11/09 18:43:11 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	c = (char)c;
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	while (i > 0 && str[i] != c)
	{
		i--;
	}
	if (str[i] != c)
		return (0);
	else
		return (str + i);
}
