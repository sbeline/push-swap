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

t_llist	*define_lastest(t_llist *l, t_llist *l_next)
{
	if (l_next->lastest)
	{
		l->lastest = 1;
		l_next->lastest = 0;
		return (l);
	}
	return (l_next);
}

void 	fusion_phase_one(t_dllist *stack_a, t_dllist *stack_b)
{
	stack_a->head->lastest = 0;
	stack_b->head->lastest = 1;
	if (stack_a->lenght > 2)
		ft_rotate(stack_a, NULL, 0);
}

void 	fusion_merge(t_dllist *stack_a, t_dllist *stack_b)
{
	while (stack_b)
	{
		if (stack_b && stack_a->head->lastest
			&& stack_b->head->content > stack_a->head->content)
		{
			if (stack_a->head->lastest
				&& stack_b->head->content > stack_a->head->content)
				fusion_phase_one(stack_a, stack_b);
			push(&stack_b, &stack_a);
			ft_putendl("pa");
		}
		else if (stack_b && ((stack_a->head->smallest
					&& stack_b->head->content < stack_a->head->content)
				|| (stack_b->head->content < stack_a->head->content)))
		{
			push(&stack_b, &stack_a);
			ft_putendl("pa");
		}
		else if (stack_b && stack_b->head->content > stack_a->head->content)
			ft_rotate(stack_a, NULL, 0);
		else if (stack_b && stack_b->head->content < stack_a->head->content)
			ft_rrotate(stack_a, NULL, 0);
	}
	rest_src(stack_a, NULL);
}
