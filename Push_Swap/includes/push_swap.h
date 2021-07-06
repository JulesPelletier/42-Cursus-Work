/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:08:27 by Jules             #+#    #+#             */
/*   Updated: 2021/04/30 14:22:44 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H_
#define _PUSH_SWAP_H_

# include "../Libft/libft.h"
# include "../GNL/get_next_line.h"
# include <stdio.h>

# define BUFFER_SIZE 10
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_params
{
    int     max;
    int     index_max;
    int     min;
    int     index_min;
    int     divider;
    int     chunck;
    int     pivot;
    int     median;
}               t_params;


typedef struct  s_stack
{
    int         *stack;
    char        **stack_aff;
    int         len;
    int         init;
    t_params    params;
}               t_stack;

typedef struct  s_operations
{
    char    *line;
}               t_operations;

typedef struct  s_errors
{
    int     errors[20];
    int     nb_errors;
    int     kill;
}               t_errors;

typedef struct  s_all
{
    t_stack         stA;
    t_stack         stB;
    t_operations    op;
    t_errors        err;
}               t_all;

// SHOW 
void    ft_show_2stacks(t_stack stack1, t_stack stack2);
void    ft_show_2stacks_char(t_stack stack1, t_stack stack2);
int     *ft_init_tab(int ac);

// INIT 
void    ft_init_errors(t_all *all);
void    ft_init_stack(t_all *all);
void    ft_init_operations(t_all *all);
void    ft_init_all(t_all *all);
void    ft_init_params(t_stack *stack);

void    ft_free_all(t_all *all);

// ERROR
void    ft_add_error(t_all *all, int error);
void    ft_show_errors(t_all *all);
void    ft_display_errors(t_all *all);
void    ft_display_error(int error);

// MOVES
void    ft_operation_apply(t_all *all);
void    ft_operation_move(t_all *all);
void    ft_operation_options(t_all *all);
void    ft_sa_move(t_all *all);
void    ft_sb_move(t_all *all);
void    ft_ss_move(t_all *all);
void    ft_pa_move(t_all *all);
void    ft_pb_move(t_all *all);
void    ft_ra_move(t_all *all);
void    ft_rb_move(t_all *all);
void    ft_rr_move(t_all *all);
void    ft_rra_move(t_all *all);
void    ft_rrb_move(t_all *all);
void    ft_rrr_move(t_all *all);

// CHECKS
int     ft_check_push(t_all *all);
int     ft_check_swap(t_all *all);
int     ft_check_operations(t_all *all);
int     ft_check_rotate(t_all *all);
int     ft_check_options(t_all *all);
int     ft_check_sort(t_all *all);
int     ft_check_stack(int *stack, int len);
int     ft_check_stack_desc(int *stack, int len);
int     ft_check_int(char *str);
int     ft_check_doublons(t_stack stack);

// PUSH SWAP
void    ft_opti_three(t_all *all, t_stack *stack, int *stack_dup);
void    ft_options_three(t_all *all, t_stack *stack);
int     *ft_test_three(t_stack *stack, int *stack_dup, int a, int b, int c);
void    ft_algo(t_all *all);
int     ft_find_inser_pos(t_stack *stack, int value);
void    ft_trivial(t_all *all);
void    ft_insert_min(t_all *all);
void    ft_insert_max(t_all *all);
void    ft_insert(t_all *all);
void    ft_insert_after_mid(t_all *all, int pos);
void    ft_insert_before_mid(t_all *all, int pos);


// UTILS
int     ft_max(int a, int b);
void    ft_fill_stack(t_all *all, int ac, char **av);
void    ft_swap(int a, int b);
void    ft_heapsort_recursive(t_all *all, int n, int i);
void    ft_heapsort(t_all *all);
void    ft_get_divider(t_stack *stack);
void    ft_get_max(t_stack *stack);
void    ft_get_min(t_stack *stack);
void    ft_get_median(t_stack *stack);


void    ft_putint(int a);

//TEST
void    ft_zero_stack(t_all *all);

#endif

