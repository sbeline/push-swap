/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_fc1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:11:42 by sbeline           #+#    #+#             */
/*   Updated: 2021/08/23 14:42:12 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void 	rest_one_stack(t_dllist *stack)
{
	while (!stack->head->smallest)
	{
		ft_rotate(stack, NULL, 0);
	}
}

void	rest_stack(t_dllist *stack_a, t_dllist *stack_b)
{
	while ((stack_a && !stack_a->head->smallest)
			|| (stack_b && !stack_b->head->smallest))
	{
		if (!stack_a && !stack_a->head->smallest
			&& !stack_b && !stack_b->head->smallest)
			ft_rotate(stack_a, stack_b, 2);
		else if (!stack_a->head->smallest)
			ft_rotate(stack_a, NULL, 0);
		else if (!stack_b->head->smallest)
			ft_rotate(NULL, stack_b, 1);
	}
	if (stack_a)
		stack_a->tail->lastest = 1;
	if (stack_b)
		stack_b->tail->lastest = 1;
}

void 	rest_src(t_dllist *stack_a, t_dllist *stack_b)
{
	if (stack_a)
	{
		if (stack_a->last_entry_smallest)
		{
			stack_a->last_entry_smallest->smallest = 0;
			stack_a->last_entry_smallest = NULL;
		}
		find_smallest(stack_a);
	}
	if (stack_b)
	{
		if(stack_b->last_entry_smallest)
		{
			stack_b->last_entry_smallest->smallest = 0;
			stack_b->last_entry_smallest = NULL;
		}
		find_smallest(stack_b);
	}
	rest_stack(stack_a, stack_b);
}

int 	stack_is_ok(t_dllist *stack_a, t_dllist *stack_b)
{
	t_llist	*ptr;

	ptr = stack_a->head;

	if (stack_b)
		return (-1);
	while (ptr->next)
	{
		if (ptr->content > ptr->next->content)
			return (-1);
		ptr = ptr->next;
	}
	ft_putendl("OK");
	return (1);
}

void	rotate(t_dllist **stack)
{
	t_llist		*ptr;
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
