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

int				push_swap(t_dllist *stack_a)
{
	print_stack(stack_a,0);
	print_stack_rev(stack_a,0);
	swap_stack(&stack_a);
	print_stack(stack_a,0);
	print_stack_rev(stack_a,0);
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
