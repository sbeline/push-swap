/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_merge1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 07:37:57 by sbeline           #+#    #+#             */
/*   Updated: 2021/08/20 14:07:10 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void divide_merge(t_dllist *s_a, t_dllist *s_b)
{
	
}

t_dllist	*divide_stack(t_dllist *stack_a, int midLenghtStack)
{
	t_dllist	*stack_b;
	int			count;

	count = 0;
	stack_b = NULL;
	while (count != midLenghtStack)
	{
		push(&stack_a, &stack_b);
		ft_putendl("pb");
		count++;
	}
	rest_src(stack_a, stack_b);
	return (stack_b);
}
