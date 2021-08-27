/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:11:18 by sbeline           #+#    #+#             */
/*   Updated: 2021/08/22 15:46:02 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void 	aff_stack_title(int maxLenghtNb)
{
	ft_printmuliplecar(maxLenghtNb / 2, ' ');
	ft_putchar('a');
	ft_printmuliplecar(maxLenghtNb / 2, ' ');
	ft_putchar('|');
	ft_printmuliplecar(maxLenghtNb / 2, ' ');
	ft_putchar('b');
	ft_printmuliplecar(maxLenghtNb / 2, ' ');
	ft_putchar('\n');
	ft_printmuliplecar(maxLenghtNb * 2 + 1, '_');
	ft_putchar('\n');
}

void 	placement_print(char *stackName, int maxLenghtNb, int opt)
{
	ft_printmuliplecar(maxLenghtNb / 2, ' ');
	ft_putstr(stackName);
	if (maxLenghtNb % 2 == 0)
		maxLenghtNb--;
	ft_printmuliplecar(maxLenghtNb / 2, ' ');
	if (opt)
		ft_putchar('|');
}

void 	listA_is_supp(int maxLenghtNb, t_dllist *a, t_dllist *b)
{
	t_llist		*lst_a;
	t_llist		*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (a && a->head)
	{
		lst_a = a->head;
		if (b && b->head)
			lst_b = b->head;
		while (lst_a)
		{
			placement_print(ft_itoa(lst_a->content),
				maxLenghtNb - ft_nblen(lst_a->content), 1);
			ft_putstr("lst_a->smallest=");
			ft_putnbr(lst_a->smallest);
			ft_putstr("lst_a->lastest=");
			ft_putnbr(lst_a->lastest);
			lst_a = lst_a->next;
			if (lst_b)
			{
				placement_print(ft_itoa(lst_b->content),
					maxLenghtNb - ft_nblen(lst_b->content), 0);
				lst_b = lst_b->next;
			}
			ft_putchar('\n');
		}
	}
}

void 	listB_is_supp(int maxLenghtNb, t_dllist *a, t_dllist *b)
{
	t_llist		*lst_a;
	t_llist		*lst_b;

	lst_b = NULL;
	if (b && b->head)
	{
		lst_b = b->head;
		if (a)
			lst_a = a->head;
		while (lst_b)
		{
			if (lst_a)
			{
				placement_print(ft_itoa(lst_a->content),
					maxLenghtNb - ft_nblen(lst_a->content), 1);
				lst_a = lst_a->next;
			}
			else
				placement_print(" ", maxLenghtNb - 1, 1);
			placement_print(ft_itoa(lst_b->content),
				maxLenghtNb - ft_nblen(lst_b->content), 0);
			lst_b = lst_b->next;
			ft_putchar('\n');
		}
	}
}

void 	view_stack(t_dllist *a, t_dllist *b, int maxLenghtNb)
{
	int		lenghtA;
	int		lenghtB;

	if (maxLenghtNb % 2 == 0)
		maxLenghtNb--;
	aff_stack_title(maxLenghtNb - 1);
	if (!b)
		lenghtB = 0;
	else
		lenghtB = b->lenght;
	if (!a)
		lenghtA = 0;
	else
		lenghtA = a->lenght;
	if (lenghtA || lenghtB)
	{
		if (a->lenght >= lenghtB)
			listA_is_supp(maxLenghtNb, a, b);
		else
			listB_is_supp(maxLenghtNb, a, b);
	}
}
