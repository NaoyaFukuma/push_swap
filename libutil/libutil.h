/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutil.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 00:51:02 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/27 00:10:00 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUTIL_H
# define LIBUTIL_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*prv;
	struct s_stack	*nxt;
	char			sentinel_flag;
}					t_stack;

typedef struct s_info
{
	int				argc;
	char			**argv;
	int				*src_array;
	int				*tmp_array;
	t_stack			*stk_a;
	t_stack			*stk_b;
	char			*cmd_list;
	int				sorted_flag;
	int				error_flag;
}					t_info;

void				error_check_and_fill_stack(t_info *info);
// in lst_utils.c
t_stack				*new_node(int num);
t_stack				*deltop_stk(t_stack *stk_top);
void				delall_lst(t_stack *node);
t_stack				*addfront_stk(t_stack *stk, t_stack *add_node);
t_stack				*addback_stk(t_stack *stk, t_stack *add_node);

// in free_and_exit_utils.c
void				put_error_and_exit(void);
void				free_stk_and_cmdlist(t_info *info);
void				swap(int *a, int *b, int *pl, int *pr);

/* 22_cmd_utils.c */
void				cmd_pa(t_info *info);
void				cmd_pb(t_info *info);
void				cmd_ra(t_info *info);
void				cmd_rb(t_info *info);
void				cmd_rr(t_info *info);
void				cmd_sa(t_info *info);
void				cmd_sb(t_info *info);
void				cmd_ss(t_info *info);
void				cmd_rra(t_info *info);
void				cmd_rrb(t_info *info);
void				cmd_rrr(t_info *info);

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
