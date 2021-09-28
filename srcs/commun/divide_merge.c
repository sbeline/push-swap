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

void 	fusion_merge(t_dllist *stack_a, t_dllist *stack_b)
{
	while (stack_b)
	{
		if (stack_b && stack_a->head->lastest && stack_b->head->content > stack_a->head->content)
		{
			if (stack_a->head->lastest && stack_b->head->content > stack_a->head->content)
			{
				stack_a->head->lastest = 0;
				stack_b->head->lastest = 1;
				if (stack_a->lenght > 2)
					ft_rotate(stack_a, NULL, 0);
			}
			push(&stack_b, &stack_a);
			ft_putendl("pa");
		}
		else if (stack_b  && (stack_a->head->smallest && stack_b->head->content < stack_a->head->content)
			|| (stack_b->head->content < stack_a->head->content))
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

void 	r_s_brut(t_dllist *s_a, t_dllist *s_b, int a, int b, int (*l_last)[2])
{
	if (!swap_check(s_a, s_b, a, b) )
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

void	stack_brut(t_dllist *s_a, t_dllist *s_b, int a, int b, int (*l_last)[2])
{
	if (!swap_check(s_a, s_b, a, b))
	{
		if (!a && !b
			&& !(*l_last)[0] && !(*l_last)[1])
			ft_rotate(s_a, s_b, 2);
		else if (!a && !(*l_last)[0])
			ft_rotate(s_a, NULL, 0);
		else if (!b && !(*l_last)[1])
			ft_rotate(NULL, s_b, 1);
	}
	if (s_a->head->lastest)
		(*l_last)[0] = 1;
	if (s_b->head->lastest)
		(*l_last)[1] = 1;
}

void 	merge_stack_brut(t_dllist *stack_a, t_dllist *stack_b)
{
	int		a_merge;
	int		b_merge;
	int		l_lastest[2];

	a_merge = 0;
	b_merge = 0;
	l_lastest[0] = 0;
	l_lastest[1] = 0;
	l_lastest[1] = '\0';
	while (!a_merge || !b_merge)
	{
		if (!a_merge)
			a_merge = stack_raw_is_merge(stack_a);
		if (!b_merge)
			b_merge = stack_raw_is_merge(stack_b);
		/*view_stack(stack_a, stack_b, 42);
		ft_putstr("stack_a status=");
		ft_putnbr(a_merge);
		ft_putstr("-------stack_b status=");
		ft_putnbr(b_merge);
		ft_putstr("lastest0 status=");
		ft_putnbr(l_lastest[0]);
		ft_putstr("-------------lastest1 status=");
		ft_putnbr(l_lastest[0]);*/
		if (l_lastest[0] || l_lastest[1])
			r_s_brut(stack_a, stack_b, a_merge, b_merge, &l_lastest);
		else if (!l_lastest[0] || !l_lastest[1])
			stack_brut(stack_a, stack_b, a_merge, b_merge, &l_lastest);
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
	//view_stack(stack_a, stack_b, 42);
	merge_stack_brut(stack_a, stack_b);
	rest_src(stack_a, stack_b);
	fusion_merge(stack_a, stack_b);
	if (!stack_b->lenght)
	{
		free(stack_b);
		stack_b = NULL;
	}
	stack_is_ok(stack_a, stack_b);
	//view_stack(stack_a, stack_b, 42);
}
