/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 04:57:23 by mlaplana          #+#    #+#             */
/*   Updated: 2019/11/12 14:56:15 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content)
{
	void	*cont;
	t_list	*new;

	cont = (void *)content;
	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->content = cont;
	new->next = NULL;
	return (new);
}
