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

void 		print_stack_rev(t_dllist *stack, int mode)
{
	t_llist *ptr;

	if (stack == NULL)
		return ;
	ptr = stack->tail;
	if (mode == 0)
		ft_putstr("stack_a=");
	if (mode == 1)
		ft_putstr("stack_b=");
	while (ptr)
	{
		ft_putnbr(ptr->content);
		ft_putchar(';');
		ptr = ptr->prev;
	}
	ft_putchar('\n');
}

void 		print_stack(t_dllist *stack, int mode)
{
	t_llist *ptr;

	if (stack == NULL)
		return ;
	ptr = stack->head;
	if (mode == 0)
		ft_putstr("stack_a=");
	if (mode == 1)
		ft_putstr("stack_b=");
	while (ptr)
	{
		ft_putnbr(ptr->content);
		ft_putchar(';');
		ptr = ptr->next;
	}
	ft_putchar('\n');
}

int			stack_is_ok(t_dllist *stack_a, t_dllist *stack_b)
{
	t_llist *ptr;

	ptr = stack_a->head;
	if (stack_b)
		return (-1);
	while (ptr->next)
	{
		if (ptr->content > ptr->next->content)
			return (-1);
		ptr = ptr->next;
	}
	ft_putendl("OK");
	return (1);
}
