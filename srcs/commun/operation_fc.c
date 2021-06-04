/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_fc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void 			swap_stack(t_dllist **stack)
{
	t_llist		*ptr;
	t_llist		*to_swap;
	t_llist		*to_swap1;

	if (!(*stack)->head || !(*stack)->head->next)
			return ;
	if (!(*stack)->head->next->next)
	{
		ptr = (*stack)->head->next;
		(*stack)->head->next = NULL;
		ptr->next = (*stack)->head;
		(*stack)->tail = (*stack)->head;
		(*stack)->head = ptr;
		(*stack)->tail->prev = (*stack)->head;
		ptr->prev = NULL;
		return ;
	}
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

void find_smallest(t_dllist *stack)
{
	t_llist *ptr;

	ptr = stack->head;
	while (ptr)
	{
		if (!(stack->last_entry_smallest)
				|| stack->last_entry_smallest->content > ptr->content)
		{
			if (stack->last_entry_smallest)
				stack->last_entry_smallest->smallest = 0;
			stack->last_entry_smallest = ptr;
			ptr->smallest = 1;
		}
		ptr = ptr->next;
	}
}

void		ft_lstaddhead(t_dllist **alst, t_llist *n)
{
	if (*alst != NULL)
	{
		if (n != NULL)
		{
			(*alst)->head->prev = n;
			n->next = (*alst)->head;
			(*alst)->head = n;
			(*alst)->lenght++;
			return ;
		}
	}
	*alst = (t_dllist*)ft_memalloc(sizeof(t_dllist));
	(*alst)->lenght = 1;
	(*alst)->head = n;
	(*alst)->tail = n;
}

void 			push(t_dllist **stack_src, t_dllist **stack_dst)
{
	t_llist *ptr;
	t_llist *tmp;

	if (!(*stack_src))
		return ;
	tmp = (*stack_src)->head;
	if (!(*stack_src)->head->next)
	{
		ft_lstaddhead(stack_dst, tmp);
		(*stack_src)->head = NULL;
		(*stack_src)->tail = NULL;
		(*stack_src)->lenght = 0;
		(*stack_src) = NULL;
		return ;
	}
	ptr = (*stack_src)->head->next;
	tmp->next = NULL;
	tmp->prev = NULL;
	if ((*stack_src) != NULL)
	{
		ft_lstaddhead(stack_dst, tmp);
		(*stack_src)->head = ptr;
		(*stack_src)->lenght = (*stack_src)->lenght - 1;
		ptr->prev = NULL;
	}
}
