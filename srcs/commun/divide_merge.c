/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:09:51 by sbeline           #+#    #+#             */
/*   Updated: 2021/06/10 14:15:18 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int		swap_check(t_dllist *stack_a, t_dllist *stack_b, int a, int b)
{
	if (!a && stack_a && stack_a->head->next &&
		stack_a->head->content > stack_a->head->next->content &&
		 !b && stack_b &&stack_b->head->next &&
		 stack_b->head->content > stack_b->head->next->content) {
		swap(stack_a, stack_b, 2);
		return(1);
	}
	if (!a && stack_a && stack_a->head->next &&
		 stack_a->head->content > stack_a->head->next->content) {
		swap(stack_a, NULL, 0);
		return(1);
	}
	if (!b && stack_b &&stack_b->head->next &&
		 stack_b->head->content > stack_b->head->next->content) {
		swap(NULL, stack_b, 1);
		return(1);
	}
	return(0);
}

static t_dllist	*divide_stack(t_dllist *stack_a, int midLenghtStack)
{
	t_dllist *stack_b;
	int count;

	count = 0;
	stack_b = NULL;
	while (count != midLenghtStack)
	{
		push(&stack_a, &stack_b);
		ft_putstr("[pb]");
		count++;
	}
	//determine smallest for each stack
	rest_src(stack_a, stack_b);
	//view_stack(stack_a, NULL, 42);
	//view_stack(stack_b, NULL, 42);
	return (stack_b);
}

static void 	fusion_merge(t_dllist *stack_a, t_dllist *stack_b)
{
  int count;

  count = 0;
  while ((stack_is_merge(stack_a) || stack_b) && count < stack_a->lenght)
  {
    if (stack_b && stack_b->head->content < stack_a->head->content)
		{
      push(&stack_b, &stack_a);
			ft_putstr("[pb]");
		}
    else if (stack_b->head->content > stack_a->head->content)
    {
      ft_rotate(stack_a, NULL, 0);
      count++;
    }
  }
  while (!stack_a->head->smallest)
  {
    ft_rotate(stack_a, NULL, 0);
  }
}

void			reverse_stack_brut(t_dllist *s_a, t_dllist *s_b, int a, int b)
{
	if (!swap_check(s_a, s_b, a, b))
	{
		while (!s_a->head->smallest || !s_b->head->smallest)
		{
			if (!s_a->head->smallest && !s_b->head->smallest)
				ft_rrotate(s_a, s_b, 2);
			else if (!s_a->head->smallest)
				ft_rrotate(s_a, NULL, 0);
			else if (!s_b->head->smallest)
				ft_rrotate(NULL, s_b, 1);
			}
	}
}
void			merge_stack_brut(t_dllist *stack_a, t_dllist *stack_b)
{
	int a_merge;
	int b_merge;
	int debug = 0;

	a_merge = 0;
	b_merge = 0;
	while (!a_merge || !b_merge)
	{
		a_merge = stack_raw_is_merge(stack_a);
		b_merge = stack_raw_is_merge(stack_b);
		if (stack_a->head->lastest || stack_b->head->lastest)
		{
			reverse_stack_brut(stack_a, stack_b, a_merge, b_merge);
		}
		else
		{
			if (!swap_check(stack_a, stack_b, a_merge, b_merge))
			{
				if (!a_merge && !b_merge &&
					 !stack_a->head->lastest && !stack_b->head->lastest)
					ft_rotate(stack_a, stack_b, 2);
				else if (!a_merge && !stack_a->head->lastest)
					ft_rotate(stack_a, NULL, 0);
				else if (!b_merge && !stack_a->head->lastest)
					ft_rotate(NULL, stack_b, 1);
			}
		}
	}
}

/*Recursivly sort stack_a and stack_b*/
void 			divide_algo(t_dllist *stack_a, int maxLenghtNb)
{
	t_dllist	*stack_b;

	stack_b = NULL;
  //view_stack(stack_a, stack_b, 42);
	if (stack_a->lenght)
	{
		 stack_b = divide_stack(stack_a, stack_a->lenght / 2);
	}
	merge_stack_brut(stack_a, stack_b);
	rest_src(stack_a, stack_b);
  fusion_merge(stack_a, stack_b);
	ft_putchar('\n');
  view_stack(stack_a, stack_b, 42);
}
