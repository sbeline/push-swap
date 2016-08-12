/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_fc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 06:32:42 by salomon           #+#    #+#             */
/*   Updated: 2016/08/12 00:47:34 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push-swap.h"
#include "../libft/Includes/libft.h"

void 			swap_stack(t_dllist **stack)
{
	t_llist		*ptr;
	t_llist		*to_swap;

	to_swap = (*stack)->head->next->next;
	ptr = (*stack)->head->next;
	ptr->next = (*stack)->head;
	(*stack)->head->next = to_swap;
	(*stack)->head = ptr;

}

void			rotate(t_dllist **stack)
{
	t_llist		*ptr;

	ptr = (*stack)->tail;
	(*stack)->tail->prev->next = NULL;
	ptr->next = (*stack)->head;
	(*stack)->head = ptr;
}

void			rrotate()
{
	/* code */
}
