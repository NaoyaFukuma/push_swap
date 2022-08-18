/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:37:40 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/17 17:46:59 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h> // for test
# include <stdlib.h>

/* Linked list used for stacks */
typedef struct s_stack
{
	int				num;
	struct s_stack	*prv;
	struct s_stack	*nxt;
	char			sentinel_flag;
}					t_stack;

typedef struct s_chunk_info
{
	int	min;
	int	max;
	int size;
	struct s_chunk_info	*nxt;
	char	stk;
}					t_chunk_info;

/* infomation */
typedef struct s_info
{
	int				argc;
	char			**argv;
	int				*src_array;
	int				*tmp_array;
	t_stack			*stk_a_top;
	t_stack			*stk_b_top;
	char			*cmd_list;
	int				sorted_flag;
	int				error_flag;
}					t_info;

/* in compress_utils.c */
void				error_check_and_fill_stack(t_info *info);

/* in create_cmd_list.c */
void				create_cmd_list(t_info *info);

// in lst_utils.c
t_stack				*new_node(int num);
t_stack				*deltop_stk(t_stack *stk_top);
void				delall_lst(t_stack *node);
t_stack				*addfront_stk(t_stack *stk, t_stack *add_node);
t_stack				*addback_stk(t_stack *stk, t_stack *add_node);
void	show_stk(t_info *info);

// in free_and_exit_utils.c
void				put_error_and_exit(void);

/* 22_cmd_utils.c */
void				cmd_pa(t_info *info);
void				cmd_pb(t_info *info);
void				cmd_ra(t_info *info);
void				cmd_rb(t_info *info);
void				cmd_sa(t_info *info);
void				cmd_sb(t_info *info);
void				cmd_rra(t_info *info);
void				cmd_rrb(t_info *info);

/* 12_cmd_optimization.c */
void				cmd_optimization(t_info *info);

/* _sourt_utils.c */
void	argc_three_sort(t_info *info, int decre);
void	argc_three_r_sort(t_info *info, int decre);
void	insert_sort(t_info *info);
ssize_t	rotate_cost(t_stack *stk_p, int min, int max);
ssize_t	r_rotate_cost(t_stack *stk_p, int min, int max);

// operation macro
# define _SA (char)1
# define _SB (char)2
# define _SS (char)3
# define _RA (char)4
# define _RB (char)5
# define _RR (char)6
# define _RRA (char)7
# define _RRB (char)8
# define _RRR (char)9
# define _PA (char)10
# define _PB (char)11
# define _IGNORE (char)100

#endif
