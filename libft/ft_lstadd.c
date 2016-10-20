/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void		ft_lstadd(t_dllist **alst, t_llist *n)
{
	if (*alst != NULL)
	{
		if (n != NULL)
		{
			(*alst)->tail->next = n;
			n->prev = (*alst)->tail;
			(*alst)->tail = n;
			(*alst)->lenght++;
			return ;
		}
	}
	*alst = (t_dllist*)ft_memalloc(sizeof(t_dllist));
	(*alst)->lenght = 1;
	(*alst)->head = n;
	(*alst)->tail = n;
}
