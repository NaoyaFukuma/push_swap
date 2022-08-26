/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_04.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:04:22 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/27 00:09:06 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	min_get_and_fix(t_info *info, t_chunk **chunk, int *tmp_min,
		int tmp_max)
{
	while ((*chunk)->size-- > 0)
	{
		if (info->stk_b->nxt->num == *tmp_min && info->stk_b->num == *tmp_min
			+ 1 && tmp_max >= *tmp_min + 1)
			v_pa_ra(info, 2, tmp_min);
		else if (info->stk_b->nxt->nxt->num == *tmp_min
			&& info->stk_b->nxt->num == *tmp_min + 1
			&& info->stk_b->num == *tmp_min + 2 && tmp_max >= *tmp_min + 2)
			v_pa_ra(info, 3, tmp_min);
		else if (info->stk_b->prv->prv->num == *tmp_min)
			vrrb_pa_ra_incre(info, tmp_min, 1);
		else if (info->stk_b->prv->prv->prv->num == *tmp_min
			&& info->stk_b->prv->prv->num == *tmp_min + 1
			&& tmp_max >= *tmp_min + 1)
			vrrb_pa_ra_incre(info, tmp_min, 2);
		if (info->stk_a->num == *tmp_min)
			ra_incre(info, tmp_min);
		else if (info->stk_a->nxt->num == *tmp_min)
			sa_ra_incre(info, tmp_min);
		else
			cmd_pb(info);
	}
}

void	chunk_size_1_or_2(t_info *info, t_chunk **chunk)
{
	if ((*chunk)->size == 1)
	{
		cmd_pa(info);
		cmd_ra(info);
		free_and_nxt(chunk);
		return ;
	}
	if ((*chunk)->size == 2)
	{
		if (info->stk_b->num == (*chunk)->min)
		{
			cmd_pa(info);
			cmd_ra(info);
			cmd_pa(info);
		}
		else
		{
			cmd_pa(info);
			cmd_pa(info);
			cmd_ra(info);
		}
		cmd_ra(info);
		free_and_nxt(chunk);
		return ;
	}
}

void	top_min(t_info *info, t_chunk **chunk)
{
	if (info->stk_b->nxt->num == (*chunk)->max)
	{
		cmd_pa(info);
		cmd_ra(info);
		cmd_pa(info);
		cmd_pa(info);
		cmd_ra(info);
		cmd_ra(info);
	}
	else
	{
		cmd_pa(info);
		cmd_ra(info);
		cmd_pa(info);
		cmd_ra(info);
		cmd_pa(info);
		cmd_ra(info);
	}
	free_and_nxt(chunk);
	return ;
}

void	top_max(t_info *info, t_chunk **chunk)
{
	if (info->stk_b->nxt->num == (*chunk)->min)
	{
		cmd_pa(info);
		cmd_pa(info);
		cmd_ra(info);
		cmd_pa(info);
		cmd_ra(info);
		cmd_ra(info);
	}
	else
	{
		cmd_pa(info);
		cmd_pa(info);
		cmd_pa(info);
		cmd_ra(info);
		cmd_ra(info);
		cmd_ra(info);
	}
	free_and_nxt(chunk);
	return ;
}

void	top_mid(t_info *info, t_chunk **chunk)
{
	if (info->stk_b->nxt->num == (*chunk)->min)
	{
		cmd_pa(info);
		cmd_pa(info);
		cmd_ra(info);
		cmd_ra(info);
		cmd_pa(info);
		cmd_ra(info);
	}
	else
	{
		cmd_pa(info);
		cmd_pa(info);
		cmd_sa(info);
		cmd_pa(info);
		cmd_ra(info);
		cmd_ra(info);
		cmd_ra(info);
	}
	free_and_nxt(chunk);
	return ;
}
