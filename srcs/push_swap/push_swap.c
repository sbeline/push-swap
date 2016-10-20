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

#include "../../includes/push_swap.h"

void 			push_swap(t_dllist *stack_a)
{
	t_dllist	*stack_b;
	t_llist		*ptr_head;
	t_llist		*ptr_tail;
	int			mid;

	if ((stack_a->lenght % 2) == 0)
		mid = stack_a->lenght / 2;
	else
		mid = stack_a->lenght / 2 + 1;
	stack_b =  NULL;
	ptr_head = stack_a->head;
	ptr_tail = stack_a->tail;
	while (mid != 0)
	{
		ft_putstr("head=");
		ft_putnbr(ptr_head->content);
		ft_putstr(" ; tail=");
		ft_putnbr(ptr_tail->content);
		ft_putchar('\n');
		ptr_head = ptr_head->next;
		ptr_tail = ptr_tail->prev;
		mid--;
	}
}

int				main(int ac, char **av)
{
	t_dllist	*stack_a;
	t_llist		*ptr;

	ac--;
	av++;
	stack_a = NULL;
	if (!ac)
		return (-1);
	stack_a = validate_and_stacka(av, ac);
	push_swap(stack_a);
	return (0);
}
