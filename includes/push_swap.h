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

int			swap(t_dllist *stack, t_dllist *stack1, int opt);
int			ft_rotate(t_dllist *stack, t_dllist *stack1, int opt);
int			ft_rrotate(t_dllist *stack, t_dllist *stack1, int opt);

int			stack_is_ok(t_dllist *stack_a, t_dllist *stack_b);

void 		push(t_dllist **stack_src, t_dllist **stack_dst);


void 		swap_stack(t_dllist **stack);
void		rotate(t_dllist **stack);
void		rrotate(t_dllist **stack);
t_dllist	*validate_and_stacka(char **av, int ac);

#endif
