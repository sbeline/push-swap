/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_fc1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void rest_one_stack(t_dllist *stack)
{
	if (!stack)
		return ;
}

void	rest_stack(t_dllist *stack_a, t_dllist *stack_b)
{
	while (!stack_a->head->smallest || !stack_b->head->smallest)
	{
		if (!stack_a->head->smallest && !stack_b->head->smallest)
			ft_rotate(stack_a, stack_b, 2);
		else if (!stack_a->head->smallest)
			ft_rotate(stack_a, NULL, 0);
		else if (!stack_b->head->smallest)
			ft_rotate(NULL, stack_b, 1);
	}
}

void rest_src(t_dllist *stack_a, t_dllist *stack_b)
{
	if (stack_a->last_entry_smallest) {
		stack_a->last_entry_smallest->smallest = 0;
		stack_a->last_entry_smallest = NULL;
	}
	if (stack_b->last_entry_smallest) {
		stack_b->last_entry_smallest->smallest = 0;
		stack_b->last_entry_smallest = NULL;
	}
	find_smallest(stack_a);
	find_smallest(stack_b);
	rest_stack(stack_a, stack_b);
	stack_a->tail->lastest = 1;
	stack_b->tail->lastest = 1;
}

int			stack_is_ok(t_dllist *stack_a, t_dllist *stack_b)
{
	t_llist *ptr;

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
