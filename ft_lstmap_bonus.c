/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:06:08 by mlaplana          #+#    #+#             */
/*   Updated: 2019/11/12 14:03:04 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newlst;
	t_list *first;
	t_list *aux;

	if (lst && f)
	{
		newlst = ft_lstnew(f(lst->content));
		first = newlst;
		lst = lst->next;
		while (lst)
		{
			aux = lst->next;
			if (!(newlst->next = ft_lstnew(f(lst->content))))
				del(lst);
			newlst = newlst->next;
			lst = aux;
		}
		return (first);
	}
	return (NULL);
}
