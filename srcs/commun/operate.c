/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2021/06/14 11:46:00 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	find_smallest(t_dllist *stack)
{
	t_llist		*ptr;

	ptr = stack->head;
	while (ptr)
	{
		if (!(stack->last_entry_smallest)
			|| stack->last_entry_smallest->content > ptr->content)
		{
			if (stack->last_entry_smallest)
				stack->last_entry_smallest->smallest = 0;
			stack->last_entry_smallest = ptr;
			ptr->smallest = 1;
		}
		ptr = ptr->next;
	}
}

int 	swap(t_dllist *stack, t_dllist *stack1, int opt)
{
	if (opt == 0 && stack)
	{
		swap_stack(&stack);
		ft_putstr("[sa]");
	}
	else if (opt == 1 && stack1)
	{
		swap_stack(&stack1);
		ft_putstr("[sb]");
	}
	else if (opt == 2)
	{
		if (stack)
			swap_stack(&stack);
		if (stack1)
			swap_stack(&stack1);
		ft_putstr("[ss]");
	}
	return (0);
}

int 	ft_rotate(t_dllist *stack, t_dllist *stack1, int opt)
{
	if (opt == 0 && stack)
	{
		rotate(&stack);
		ft_putstr("[ra]");
	}
	else if (opt == 1 && stack1)
	{
		rotate(&stack1);
		ft_putstr("[rb]");
	}
	else if (opt == 2)
	{
		if (stack)
			rotate(&stack);
		if (stack1)
			rotate(&stack1);
		ft_putstr("[rr]");
	}
	return (0);
}

int 	ft_rrotate(t_dllist *stack, t_dllist *stack1, int opt)
{
	if (opt == 0 && stack)
	{
		rrotate(&stack);
		ft_putstr("[rra]");
	}
	else if (opt == 1 && stack1)
	{
		rrotate(&stack1);
		ft_putstr("[rrb]");
	}
	else if (opt == 2)
	{
		if (stack)
			rrotate(&stack);
		if (stack1)
			rrotate(&stack1);
		ft_putstr("[rrr]");
	}
	return (0);
}
