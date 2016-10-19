/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			swap(t_dllist *stack, t_dllist *stack1, int opt)
{
	if (opt == 0 && stack)
		swap_stack(&stack);
	else if (opt == 1 && stack1)
		swap_stack(&stack1);
	else if (opt == 2)
	{
		if (stack)
			swap_stack(&stack);
		if (stack1)
			swap_stack(&stack);
	}
	return (0);
}

int			ft_rotate(t_dllist *stack, t_dllist *stack1, int opt)
{
	if (opt == 0 && stack)
		rotate(&stack);
	else if (opt == 1 && stack1)
		rotate(&stack1);
	else if (opt == 2)
	{
		if (stack)
			rotate(&stack);
		if (stack1)
			rotate(&stack);
	}
	return (0);
}

int			ft_rrotate(t_dllist *stack, t_dllist *stack1, int opt)
{
	if (opt == 0 && stack)
		rrotate(&stack);
	else if (opt == 1 && stack1)
		rrotate(&stack1);
	else if (opt == 2)
	{
		if (stack)
			rrotate(&stack);
		if (stack1)
			rrotate(&stack);
	}
	return (0);
}
