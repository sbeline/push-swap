/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_fc1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			stack_is_ok(t_dllist *stack_a, t_dllist *stack_b)
{
	t_llist *ptr;

	ptr = stack_a->head;
	ft_putnbr(stack_a->lenght);
	if (stack_b)
	{
		ft_putendl("KO");
		return (-1);
	}
	while (ptr->next)
	{
		if (ptr->content > ptr->next->content)
		{
			ft_putendl("KO");
			return (-1);
		}
		ptr = ptr->next;
	}
	ft_putendl("OK");
	return (1);
}
