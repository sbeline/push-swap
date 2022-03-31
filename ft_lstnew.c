/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2021/07/02 15:39:39 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

t_llist 	*ft_lstnew(int content, size_t content_size)
{
	t_llist	*ptr;

	ptr = (t_llist *)ft_memalloc(sizeof(t_llist));
	ptr->content_size = content_size;
	ptr->content = content;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}
