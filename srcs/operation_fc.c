/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_fc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 06:32:42 by salomon           #+#    #+#             */
/*   Updated: 2016/08/14 01:00:34 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push-swap.h"
#include "../libft/Includes/libft.h"

void 			swap_stack(t_dllist **stack)
{
	t_llist		*ptr;
	t_llist		*to_swap;
	t_llist		*to_swap1;

	ptr = (*stack)->head->next->next;
	to_swap = (*stack)->head->next;
	to_swap1 = (*stack)->head;
	to_swap->prev = NULL;
	to_swap->next = to_swap1;
	to_swap1->prev = to_swap;
	to_swap1->next = ptr;
	ptr->prev = to_swap1;
	(*stack)->head = to_swap;
}

void			rrotate(t_dllist **stack)
{
	t_llist		*ptr;
	t_llist		*to_swap;

	ptr = (*stack)->tail->prev;
	to_swap = (*stack)->tail;
	to_swap->next = (*stack)->head;
	(*stack)->head->prev = to_swap;
	ptr->next = NULL;
	(*stack)->head = to_swap;
	to_swap->prev = NULL;
	(*stack)->tail = ptr;
}

void			rotate(t_dllist **stack)
{
	t_llist 	*ptr;
	t_llist		*to_swap;

	ptr = (*stack)->head->next;
	to_swap = (*stack)->head;
	(*stack)->tail->next = to_swap;
	to_swap->prev = (*stack)->tail;
	(*stack)->tail = to_swap;
	to_swap->next = NULL;
	(*stack)->head = ptr;
	(*stack)->head->prev = NULL;
}
