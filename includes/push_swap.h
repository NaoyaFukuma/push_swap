/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:37:40 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/26 23:31:51 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libget_next_line/libget_next_line.h"
# include "../libutil/libutil.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_chunk
{
	int				min;
	int				max;
	int				size;
	struct s_chunk	*nxt;
	char			stk;
}					t_chunk;

void				create_cmd_list(t_info *info);
void				cmd_pa(t_info *info);
void				cmd_pb(t_info *info);
void				cmd_ra(t_info *info);
void				cmd_rb(t_info *info);
void				cmd_sa(t_info *info);
void				cmd_sb(t_info *info);
void				cmd_rra(t_info *info);
void				cmd_rrb(t_info *info);
void				cmd_optimization(t_info *info);
void				argc_3_r_sort(t_info *info, int decre);
void				insert_sort(t_info *info);
ssize_t				r_cost(t_stack *stk_p, int min, int max);
ssize_t				rr_cost(t_stack *stk_p, int min, int max);
t_chunk				*new_chunk(int min, int max, char stk);
t_chunk				*add_f_chunk(t_chunk *chunk, t_chunk *add_node);
void				add_b_chunk(t_chunk **chunk, t_chunk *add_node);
void				free_and_nxt(t_chunk **chunk);
void				division_from_b_to_ander_5(t_info *info, t_chunk *chunk,
						int *tmp_min, int *tmp_max);
void				division_b_to_ander_5(t_info *info, t_chunk **chunk);
void				put_cmd(t_info *info);
void				cmd_r_rotate_util(char cmd);
void				cmd_rotate_util(char cmd);
void				cmd_swap_util(char cmd);
void				cmd_push_util(char cmd);
void				harf_set_a_b(t_info *info, t_chunk **chunk);
void				chunk_all_push_b(t_info *info, t_chunk **chunk, int tmp_min,
						int tmp_max);
void				insert_a_bottom_from_b(t_info *info, t_chunk **chunk);
void				insert_a_bottom_from_a_top(t_info *info, t_chunk **chunk);
void				v_pa_ra(t_info *info, int count, int *tmp_min);
void				sb_pa_ra_incre(t_info *info, int *tmp_min);
void				vrrb_pa_ra_incre(t_info *info, int *tmp_min, int rrb_count);
void				ra_incre(t_info *info, int *tmp_min);
void				sa_ra_incre(t_info *info, int *tmp_min);
void				min_get_and_fix(t_info *info, t_chunk **chunk, int *tmp_min,
						int tmp_max);

void				ra_and_min_incre(t_info *info, t_chunk *chunk);
void				sb_pa(t_info *info);
void				pb_sa(t_info *info);
void				pb_pb_sa(t_info *info);
void				pa_and_pb(t_info *info, size_t i);
void				ra_and_rb(t_info *info, size_t i);
void				chunk_size_1_or_2(t_info *info, t_chunk **chunk);
void				top_min(t_info *info, t_chunk **chunk);
void				top_max(t_info *info, t_chunk **chunk);
void				top_mid(t_info *info, t_chunk **chunk);

#endif
