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

int				ctrl_stack(t_dllist *stack)
{
	t_llist *ptr;

	ptr = stack->head;
	while (ptr->next)
	{
		if (ptr->content > ptr->next->content)
			return (-1);
		ptr = ptr->next;
	}
	return (0);
}

void 			push_in_b(t_dllist *stack_a, t_dllist *stack_b)
{
	t_llist		*ptr;

	while (stack_a->tail->content > stack_a->head->content)
	{
		swap_stack(&stack_a, &stack_b);
		ptr = stack_a->head;
		if (stack_b->head->content < stack_b->head->next->content)
			swap_stack(&stack_b);
	}
}

void 			push_in_a(t_dllist *stack_a, t_dllist *stack_b)
{

}

void 			push_swap(t_dllist *stack_a)
{
	t_dllist	*stack_b;

	stack_b = NULL;
	while (stack_is_ok(stack_a) != 1)
	{
		if (stack_a->head->content > stack_a->head->next->content)
			swap_stack(&stack_a);
		else if (stack_a->tail->content < stack_a->head->content)
			push_in_b(stack_a, stack_b);
		if ((ctrl_stack(stack_a) && ctrl_stack(stack_b)) &&
			(stack_a->head->content > stack_b->head->content))
			push_in_a();
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
