/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			checker(char *buf, t_dllist *stack_a, t_dllist *stack_b)
{
	if (!ft_strcmp(buf, "sa"))
		return (swap(stack_a, NULL, 0));
	if (!ft_strcmp(buf, "sb"))
		return (swap(NULL, stack_b, 1));
	if (!ft_strcmp(buf, "ss"))
		return (swap(stack_a, stack_b, 2));
	if (!ft_strcmp(buf, "ra"))
		return (ft_rotate(stack_a, NULL, 0));
	if (!ft_strcmp(buf, "rb"))
		return (ft_rotate(NULL, stack_b, 1));
	if (!ft_strcmp(buf, "rr"))
		return (ft_rotate(stack_a, stack_b, 2));
	if (!ft_strcmp(buf, "rra"))
		return (ft_rrotate(stack_a, NULL, 0));
	if (!ft_strcmp(buf, "rrb"))
		return (ft_rrotate(NULL, stack_b, 1));
	if (!ft_strcmp(buf, "rrr"))
		return (ft_rrotate(stack_a, stack_b, 2));
	if (!ft_strcmp(buf, "pa"))
		return (1);
	if (!ft_strcmp(buf, "pb"))
		return (1);
	return (-1);
}



int			main(int ac, char **av)
{
	t_dllist	*stack_a;
	t_dllist	*stack_b;
	char		*buf;

	ac--;
	av++;
	stack_a = NULL;
	stack_b = NULL;
	if (!ac)
		return (-1);
	if ((stack_a = validate_and_stacka(av, ac)) == NULL)
		return (-1);
	while ((get_next_line(1, &buf)) > 0)
	{
		if ((checker(buf, stack_a, stack_b)) != -1)
		{
			if (!ft_strcmp(buf, "pa"))
				push(&stack_b, &stack_a);
			if (!ft_strcmp(buf, "pb"))
				push(&stack_a, &stack_b);
		}
		else
			return (stack_is_ok(stack_a, stack_b));
	}
	return (0);
}
