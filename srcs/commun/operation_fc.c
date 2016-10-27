/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_fc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_dllist		*validate_and_stacka(char **av, int ac)
{
	t_dllist	*stack;
	char		*ptr;
	int			cod;
	int			i;

	i = 0;
	stack = NULL;
	while (i < ac)
	{
		if ((cod = control(av[i], stack)) < 0)
			return (error_gest(&stack, cod));
		ft_lstadd(&stack, ft_lstnew(ft_atoi(av[i]), sizeof(int)));
		i++;
	}
	return (stack);
}

void 			swap_stack(t_dllist **stack)
{
	t_llist		*ptr;
	t_llist		*to_swap;
	t_llist		*to_swap1;

	ptr = (*stack)->head->next->next;
	to_swap = (*stack)->head->next;
	to_swap1 = (*stack)->head;
	to_swap->prev = NULL;
	to_swap->next = to_swap1;
	to_swap1->prev = to_swap;
	to_swap1->next = ptr;
	ptr->prev = to_swap1;
	(*stack)->head = to_swap;
}

void			rrotate(t_dllist **stack)
{
	t_llist		*ptr;
	t_llist		*to_swap;

	ptr = (*stack)->tail->prev;
	to_swap = (*stack)->tail;
	to_swap->next = (*stack)->head;
	(*stack)->head->prev = to_swap;
	ptr->next = NULL;
	(*stack)->head = to_swap;
	to_swap->prev = NULL;
	(*stack)->tail = ptr;
}

void			rotate(t_dllist **stack)
{
	t_llist 	*ptr;
	t_llist		*to_swap;

	ptr = (*stack)->head->next;
	to_swap = (*stack)->head;
	(*stack)->tail->next = to_swap;
	to_swap->prev = (*stack)->tail;
	(*stack)->tail = to_swap;
	to_swap->next = NULL;
	(*stack)->head = ptr;
	(*stack)->head->prev = NULL;
}

void 			push(t_dllist **stack_src, t_dllist **stack_dst)
{
	t_llist *ptr;
	t_llist *ptra;
	t_llist *tmp;

	ptr = (*stack_src)->head->next;
	tmp = (*stack_src)->head;
	tmp->next = NULL;
	tmp->prev = NULL;
	if ((*stack_src) != NULL)
	{
		ft_lstadd(stack_dst, tmp);
		(*stack_src)->head = ptr;
		ptr->prev = NULL;
	}
}
