 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define  PUSH_SWAP_H

# include "../libft/Includes/libft.h"

typedef	struct		s_coor
{
	unsigned long	front;
	unsigned long	back;
}					t_coor;

void 				print_stack(t_dllist *stack, int mode);
void 				print_stack_rev(t_dllist *stack, int mode);

int					control(char *av, t_dllist **stack);
t_dllist			*error_gest(t_dllist **stack, int cod);

int					swap(t_dllist *stack, t_dllist *stack1, int opt);
int					ft_rotate(t_dllist *stack, t_dllist *stack1, int opt);
int					ft_rrotate(t_dllist *stack, t_dllist *stack1, int opt);

int					stack_is_ok(t_dllist *stack_a, t_dllist *stack_b);

void 				push(t_dllist **stack_src, t_dllist **stack_dst);


void 				swap_stack(t_dllist **stack);
void				rotate(t_dllist **stack);
void				rrotate(t_dllist **stack);
t_dllist			*validate_and_stacka(char **av, int ac);

#endif
