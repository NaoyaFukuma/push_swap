/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmdlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:10:50 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/26 12:44:37 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	argc_3_sort(t_info *info, int decre);
static void	push_b_few_num(t_info *info);
static void	argc_ander_6_sort(t_info *info);
static void	over_6_sort(t_info *info);

void	create_cmd_list(t_info *info)
{
	if (info->argc - 1 == 2)
		cmd_sa(info);
	else if (info->argc - 1 == 3)
		argc_3_sort(info, 0);
	else if (info->argc - 1 <= 6)
		argc_ander_6_sort(info);
	else if ((info->argc - 1 > 6))
		over_6_sort(info);
	cmd_optimization(info);
	cmd_optimization(info);
	return ;
}

static void	argc_3_sort(t_info *info, int decre)
{
	if (info->stk_a->num - decre == 0 && info->stk_a->nxt->num - decre == 2)
	{
		cmd_sa(info);
		cmd_ra(info);
	}
	if (info->stk_a->num - decre == 1)
	{
		if (info->stk_a->nxt->num - decre == 0)
			cmd_sa(info);
		else if (info->stk_a->nxt->num - decre == 2)
			cmd_rra(info);
	}
	if (info->stk_a->num - decre == 2)
	{
		if (info->stk_a->nxt->num - decre == 0)
			cmd_ra(info);
		else if (info->stk_a->nxt->num - decre == 1)
		{
			cmd_sa(info);
			cmd_rra(info);
		}
	}
}

static void	push_b_few_num(t_info *info)
{
	ssize_t	cost_r;
	ssize_t	cost_rr;
	ssize_t	i;
	ssize_t	j;

	i = -1;
	while (++i < info->argc - 4)
	{
		cost_r = r_cost(info->stk_a, 0, info->argc - 5);
		cost_rr = rr_cost(info->stk_a, 0, info->argc - 5);
		if (cost_r == -1)
			break ;
		j = -1;
		if (cost_r <= cost_rr)
		{
			while (++j < cost_r)
				cmd_ra(info);
			cmd_pb(info);
		}
		else
		{
			while (++j < cost_rr)
				cmd_rra(info);
			cmd_pb(info);
		}
	}
}

static void	argc_ander_6_sort(t_info *info)
{
	push_b_few_num(info);
	argc_3_sort(info, info->argc - 4);
	if (info->argc - 1 == 4)
		cmd_pa(info);
	if (info->argc - 1 == 5)
	{
		if (info->stk_b->num == 0)
			cmd_rb(info);
		cmd_pa(info);
		cmd_pa(info);
	}
	if (info->argc - 1 == 6)
	{
		argc_3_r_sort(info, 0);
		cmd_pa(info);
		cmd_pa(info);
		cmd_pa(info);
	}
}

static void	over_6_sort(t_info *info)
{
	t_chunk	*chunk;

	chunk = NULL;
	harf_set_a_b(info, &chunk);
	while (1)
	{
		if (chunk != NULL && chunk->stk == 'b' && chunk->size >= 5)
			division_b_to_ander_5(info, &chunk);
		if (chunk != NULL && chunk->stk == 'b' && chunk->size < 5)
			insert_a_bottom_from_b(info, &chunk);
		if (chunk != NULL && chunk->stk == 'a' && chunk->size >= 5)
			chunk_all_push_b(info, &chunk, chunk->min, chunk->max);
		if (chunk != NULL && chunk->stk == 'a' && chunk->size < 5)
			insert_a_bottom_from_a_top(info, &chunk);
		if (chunk == NULL)
			break ;
	}
	return ;
}
