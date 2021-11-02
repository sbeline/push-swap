/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:09:51 by sbeline           #+#    #+#             */
/*   Updated: 2021/08/26 16:46:31 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int 	swap_check(t_dllist *stack_a, t_dllist *stack_b, int a, int b)
{
	if (!a && stack_a && stack_a->head->next
		&& stack_a->head->content > stack_a->head->next->content
		&& !b && stack_b && stack_b->head->next
		&& stack_b->head->content > stack_b->head->next->content)
	{
		define_lastest(stack_a->head, stack_a->head->next);
		define_lastest(stack_b->head, stack_b->head->next);
		swap(stack_a, stack_b, 2);
		return (1);
	}
	if (!a && stack_a && stack_a->head->next
		&& stack_a->head->content > stack_a->head->next->content)
	{
		define_lastest(stack_a->head, stack_a->head->next);
		swap(stack_a, NULL, 0);
		return (1);
	}
	if (!b && stack_b && stack_b->head->next
		&& stack_b->head->content > stack_b->head->next->content)
	{
		define_lastest(stack_b->head, stack_b->head->next);
		swap(NULL, stack_b, 1);
		return (1);
	}
	return (0);
}

void 	r_s_brut(t_dllist *s_a, t_dllist *s_b, int (*ab)[2], int (*l_last)[2])
{
	if (!swap_check(s_a, s_b, (*ab)[0], (*ab)[1]))
	{
		if ((*l_last)[0] && (*l_last)[1])
			ft_rrotate(s_a, s_b, 2);
		else if ((*l_last)[0])
			ft_rrotate(s_a, NULL, 0);
		else if ((*l_last)[1])
			ft_rrotate(NULL, s_b, 1);
	}
	if (s_a->head->smallest)
		(*l_last)[0] = 0;
	if (s_b->head->smallest)
		(*l_last)[1] = 0;
}

void	stack_brut(t_dllist *s_a, t_dllist *s_b, int (*ab)[2], int (*l_last)[2])
{
	if (!swap_check(s_a, s_b, (*ab)[0], (*ab)[1]))
	{
		if (!(*ab)[0] && !(*ab)[1]
			&& !(*l_last)[0] && !(*l_last)[1])
			ft_rotate(s_a, s_b, 2);
		else if (!(*ab)[0] && !(*l_last)[0])
			ft_rotate(s_a, NULL, 0);
		else if (!(*ab)[1] && !(*l_last)[1])
			ft_rotate(NULL, s_b, 1);
	}
	if (s_a->head->lastest)
		(*l_last)[0] = 1;
	if (s_b->head->lastest)
		(*l_last)[1] = 1;
}

void 	merge_stack_brut(t_dllist *stack_a, t_dllist *stack_b)
{
	int		ab_merge[2];
	int		l_lastest[2];

	ab_merge[0] = 0;
	ab_merge[1] = 0;
	ab_merge[1] = '\0';
	l_lastest[0] = 0;
	l_lastest[1] = 0;
	l_lastest[1] = '\0';
	while (!ab_merge[0] || !ab_merge[1])
	{
		if (!ab_merge[0])
			ab_merge[0] = stack_raw_is_merge(stack_a);
		if (!ab_merge[1])
			ab_merge[1] = stack_raw_is_merge(stack_b);
		if (l_lastest[0] || l_lastest[1])
			r_s_brut(stack_a, stack_b, &ab_merge, &l_lastest);
		else if (!l_lastest[0] || !l_lastest[1])
			stack_brut(stack_a, stack_b, &ab_merge, &l_lastest);
	}
}

void 	divide_algo(t_dllist *stack_a, int maxLenghtNb)
{
	t_dllist	*stack_b;

	stack_b = NULL;
	if (stack_a->lenght)
	{
		 stack_b = divide_stack(stack_a, stack_a->lenght / 2);
	}
	merge_stack_brut(stack_a, stack_b);
	rest_src(stack_a, stack_b);
	fusion_merge(stack_a, stack_b);
	if (!stack_b->lenght)
	{
		free(stack_b);
		stack_b = NULL;
	}
	stack_is_ok(stack_a, stack_b);
}
