/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push-swap.h"
#include "../libft/Includes/libft.h"

int			main(int ac, char **av)
{
	t_dllist	*stack_a;
	t_llist		*ptr;

	ac--;
	av++;
	stack_a = NULL;
	if (!ac)
		return (-1);
	stack_a = validate_and_stacka(av, ac);
	checker(&stack_a, ac);
/*	ptr = stack_a->tail;
	while (ptr)
	{
		ft_putendl((const char*)ptr->content);
		ptr = ptr->prev;
	}*/
	ptr = stack_a->head;
	while (ptr)
	{
		ft_putendl((const char*)ptr->content);
		ptr = ptr->next;
	}
	return (0);
}
