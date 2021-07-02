/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2021/06/16 06:58:39 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define  PUSH_SWAP_H

# include "../libft/Includes/libft.h"

void				print_stack(t_dllist *stack, int mode);
void				print_stack_rev(t_dllist *stack, int mode);
void				view_stack(t_dllist *a, t_dllist *b, int maxLenghtNb);

int					stack_is_merge(t_dllist *stack);
int					stack_raw_is_merge(t_dllist *stack);
int					control(char *av, t_dllist **stack);
t_dllist			*error_gest(t_dllist **stack, int cod);

int					swap(t_dllist *stack, t_dllist *stack1, int opt);
int					ft_rotate(t_dllist *stack, t_dllist *stack1, int opt);
int					ft_rrotate(t_dllist *stack, t_dllist *stack1, int opt);
void				rest_src(t_dllist *stack_a, t_dllist *stack_b);
void				rest_stack(t_dllist *stack_a, t_dllist *stack_b);
void				find_smallest(t_dllist *stack);

int					stack_is_ok(t_dllist *stack_a, t_dllist *stack_b);
void				determine_smallest(t_dllist *stack);

void				push(t_dllist **stack_src, t_dllist **stack_dst);
void				swap_stack(t_dllist **stack);
void				rotate(t_dllist **stack);
void				rrotate(t_dllist **stack);
t_dllist			*validate_and_stacka(char **av, int ac, int *maxLenghtNb);

void				divide_algo(t_dllist *stack_a, int maxLenghtNb);
void				merge_stack_brut(t_dllist *stack_a, t_dllist *stack_b);
t_dllist			*divide_stack(t_dllist *stack_a, int midLenghtStack);
#endif
