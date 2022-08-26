/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:48:18 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/26 23:21:55 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

ssize_t	r_cost(t_stack *stk_p, int min, int max)
{
	ssize_t	i;
	ssize_t	count;

	count = 0;
	while (stk_p->sentinel_flag != 1)
	{
		count++;
		stk_p = stk_p->nxt;
	}
	stk_p = stk_p->nxt;
	i = 0;
	while (stk_p->sentinel_flag != 1)
	{
		if (min <= stk_p->num && stk_p->num <= max)
			return (i);
		i++;
		stk_p = stk_p->nxt;
	}
	if (i == count)
		return (-1);
	return (i);
}

ssize_t	rr_cost(t_stack *stk_p, int min, int max)
{
	ssize_t	i;
	ssize_t	count;

	count = 0;
	while (stk_p->sentinel_flag != 1)
	{
		count++;
		stk_p = stk_p->nxt;
	}
	stk_p = stk_p->prv;
	i = 1;
	while (stk_p->sentinel_flag != 1)
	{
		if (min <= stk_p->num && stk_p->num <= max)
			return (i);
		i++;
		stk_p = stk_p->prv;
	}
	if (i - 1 == count)
		return (-1);
	return (i);
}

void	argc_3_r_sort(t_info *info, int decre)
{
	if (info->stk_b->num - decre == 0)
	{
		if (info->stk_b->nxt->num - decre == 1)
		{
			cmd_sb(info);
			cmd_rrb(info);
		}
		else if (info->stk_b->nxt->num - decre == 2)
			cmd_rb(info);
	}
	if (info->stk_b->num - decre == 1)
	{
		if (info->stk_b->nxt->num - decre == 0)
			cmd_rrb(info);
		else if (info->stk_b->nxt->num - decre == 2)
			cmd_sb(info);
	}
	if (info->stk_b->num - decre == 2)
	{
		if (info->stk_b->nxt->num - decre == 0)
		{
			cmd_sb(info);
			cmd_rb(info);
		}
	}
}

void	chunk_all_push_b(t_info *info, t_chunk **chunk, int tmp_min,
		int tmp_max)
{
	min_get_and_fix(info, chunk, &tmp_min, tmp_max);
	free_and_nxt(chunk);
	if (!(tmp_min > tmp_max))
		*chunk = add_f_chunk(*chunk, new_chunk(tmp_min, tmp_max, 'b'));
	return ;
}

void	insert_a_bottom_from_a_top(t_info *info, t_chunk **chunk)
{
	if (info->stk_a->num == (*chunk)->min)
		ra_and_min_incre(info, *chunk);
	while (1)
	{
		if (info->stk_b->num == (*chunk)->min)
			cmd_pa(info);
		if (info->stk_b->nxt->num == (*chunk)->min)
			sb_pa(info);
		if (info->stk_a->nxt->num == (*chunk)->min)
			cmd_sa(info);
		else if (info->stk_a->nxt->nxt->num == (*chunk)->min)
			pb_sa(info);
		else if (info->stk_a->nxt->nxt->nxt->num == (*chunk)->min)
			pb_pb_sa(info);
		if (info->stk_a->num == (*chunk)->min)
			ra_and_min_incre(info, *chunk);
		if ((*chunk)->min > (*chunk)->max)
			break ;
	}
	free_and_nxt(chunk);
	return ;
}
