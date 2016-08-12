/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 13:38:39 by sbeline           #+#    #+#             */
/*   Updated: 2016/08/11 23:59:27 by salomon          ###   ########.fr       */
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
	(*alst)->lenght++;
	(*alst)->head = n;
	(*alst)->tail = n;
}
