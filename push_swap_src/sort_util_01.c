/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:53:05 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/26 22:15:31 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	harf_set_a_b(t_info *info, t_chunk **chunk)
{
	int	i;
	int	pivot;
	int	pb_count;

	pivot = (info->argc - 1) / 2 - 1;
	i = 0;
	pb_count = 0;
	while (i++ < info->argc - 1 && pb_count <= pivot)
	{
		if (info->stk_a->num <= pivot)
		{
			cmd_pb(info);
			pb_count++;
		}
		else
			cmd_ra(info);
	}
	*chunk = add_f_chunk(*chunk, new_chunk((info->argc - 1) / 2, info->argc - 2,
				'a'));
	*chunk = add_f_chunk(*chunk, new_chunk(0, (info->argc - 1) / 2 - 1, 'b'));
	return ;
}

void	division_b_to_ander_5(t_info *info, t_chunk **chunk)
{
	int		pivot;
	int		tmp_min;
	int		tmp_max;

	pivot = (*chunk)->size / 2 - 1 + (*chunk)->min;
	division_from_b_to_ander_5(info, *chunk, &tmp_min, &tmp_max);
	free_and_nxt(chunk);
	if (pivot < tmp_min && tmp_min < tmp_max)
		*chunk = add_f_chunk(*chunk, new_chunk(tmp_min, tmp_max, 'a'));
	else if (tmp_min <= pivot)
	{
		*chunk = add_f_chunk(*chunk, new_chunk(pivot + 1, tmp_max, 'a'));
		*chunk = add_f_chunk(*chunk, new_chunk(tmp_min, pivot, 'b'));
	}
	return ;
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
			cmd_ra(info);
		}
		else
		{
			cmd_pa(info);
			cmd_pa(info);
			cmd_ra(info);
			cmd_ra(info);
		}
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

void	chunk_size_3(t_info *info, t_chunk **chunk)
{
	if (info->stk_b->num == (*chunk)->min)
		top_min(info, chunk);
	else if (info->stk_b->num == (*chunk)->max)
		top_max(info, chunk);
	else
		top_mid(info, chunk);
}

void	chunk_size_else(t_info *info, t_chunk **chunk)
{
	while ((*chunk)->min <= (*chunk)->max)
	{
		if (info->stk_b->prv->prv->num == (*chunk)->min)
		{
			cmd_rrb(info);
			cmd_pa(info);
		}
		else if (info->stk_b->num == (*chunk)->min)
			cmd_pa(info);
		else if (info->stk_a->num == (*chunk)->min)
			;
		else if (info->stk_a->nxt->num == (*chunk)->min)
			cmd_sa(info);
		else
		{
			cmd_pa(info);
			continue ;
		}
		cmd_ra(info);
		(*chunk)->min++;
	}
	free_and_nxt(chunk);
	return ;
}

void	insert_a_bottom_from_b(t_info *info, t_chunk **chunk)
{
	if ((*chunk)->size == 1 && (*chunk)->size == 2)
		chunk_size_1_or_2(info, chunk);
	else if ((*chunk)->size == 3)
		chunk_size_3(info, chunk);
	else
		chunk_size_else(info, chunk);
	return ;
}

void	chunk_all_push_b(t_info *info, t_chunk **chunk, int tmp_min, int tmp_max)
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
