/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 12:58:29 by mlaplana          #+#    #+#             */
/*   Updated: 2019/11/12 11:46:06 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *current;

	current = (*alst);
	if (current == NULL)
		(*alst) = new;
	else
	{
		current = ft_lstlast(*alst);
		current->next = new;
	}
}
