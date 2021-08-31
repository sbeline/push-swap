/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2021/07/29 19:30:28 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void 	push_swap(t_dllist *stack_a, int maxLenghtNb)
{
	divide_algo(stack_a, maxLenghtNb);
}

int 	main(int ac, char **av)
{
	t_dllist	*stack_a;
	int			maxLenghtNb;

	ac--;
	av++;
	stack_a = NULL;
	maxLenghtNb = 0;
	if (!ac)
		return (-1);
	stack_a = validate_and_stacka(av, ac, &maxLenghtNb);
	if (stack_a)
		push_swap(stack_a, maxLenghtNb);
	return (0);
}
