/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:53:05 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/23 23:01:29 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	harf_set_a_b(t_info *info, t_chunk **chunk)
{
	int	i;
	int	pivot;

	pivot = (info->argc - 1) / 2 - 1;
	i = 0;
	while (i++ < info->argc - 1)
	{
		if (info->stk_a->num <= pivot)
			cmd_pb(info);
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

void	insert_a_bottom_from_b(t_info *info, t_chunk **chunk)
{
	ssize_t	cost_r;
	ssize_t	cost_rr;

	while ((*chunk)->min <= (*chunk)->max)
	{
		cost_r = r_cost(info->stk_b, (*chunk)->min, (*chunk)->min);
		cost_rr = rr_cost(info->stk_b, (*chunk)->min, (*chunk)->min);
		if (info->stk_b->nxt->num == (*chunk)->min)
			cmd_sb(info);
		else if (cost_r < cost_rr)
			while (cost_r--)
				cmd_rb(info);
		else
			while (cost_rr--)
				cmd_rrb(info);
		cmd_pa(info);
		cmd_ra(info);
		(*chunk)->min++;
	}
	free_and_nxt(chunk);
	return ;
}

void	chunk_all_push_b(t_info *info, t_chunk **chunk)
{
	int		tmp_min;
	int		tmp_max;

	tmp_min = (*chunk)->min;
	tmp_max = (*chunk)->max;
	while ((*chunk)->size-- > 0)
	{
		if (info->stk_b->num == tmp_min)
		{
			cmd_pa(info);
			cmd_ra(info);
			tmp_min++;
		}
		else if (info->stk_b->nxt->num == tmp_min
				&& info->stk_b->num == tmp_min + 1 && tmp_max >= tmp_min
				+ 1)
		{
			cmd_pa(info);
			cmd_pa(info);
			cmd_ra(info);
			cmd_ra(info);
			tmp_min++;
			tmp_min++;
		}
		else if (info->stk_b->nxt->nxt->num == tmp_min
				&& info->stk_b->nxt->num == tmp_min + 1
				&& info->stk_b->num == tmp_min + 2 && tmp_max >= tmp_min
				+ 2)
		{
			cmd_pa(info);
			cmd_pa(info);
			cmd_pa(info);
			cmd_ra(info);
			cmd_ra(info);
			cmd_ra(info);
			tmp_min++;
			tmp_min++;
			tmp_min++;
		}
		else if (info->stk_b->nxt->nxt->nxt->num == tmp_min
				&& info->stk_b->nxt->nxt->num == tmp_min + 1
				&& info->stk_b->nxt->num == tmp_min + 2
				&& info->stk_b->num == tmp_min + 3 && tmp_max >= tmp_min
				+ 3)
		{
			cmd_pa(info);
			cmd_pa(info);
			cmd_pa(info);
			cmd_pa(info);
			cmd_ra(info);
			cmd_ra(info);
			cmd_ra(info);
			cmd_ra(info);
			tmp_min++;
			tmp_min++;
			tmp_min++;
			tmp_min++;
		}
		else if (info->stk_b->nxt->num == tmp_min)
		{
			cmd_sb(info);
			cmd_pa(info);
			cmd_ra(info);
			tmp_min++;
		}
		else if (info->stk_b->prv->prv->num == tmp_min)
		{
			cmd_rrb(info);
			cmd_pa(info);
			cmd_ra(info);
			tmp_min++;
		}
		else if (info->stk_b->prv->prv->prv->num == tmp_min)
		{
			cmd_rrb(info);
			cmd_rrb(info);
			cmd_pa(info);
			cmd_ra(info);
			tmp_min++;
		}
		else if (info->stk_b->prv->prv->prv->prv->num == tmp_min)
		{
			cmd_rrb(info);
			cmd_rrb(info);
			cmd_rrb(info);
			cmd_pa(info);
			cmd_ra(info);
			tmp_min++;
		}
		if (info->stk_a->num == tmp_min)
		{
			cmd_ra(info);
			tmp_min++;
		}
		else if (info->stk_a->nxt->num == tmp_min)
		{
			cmd_sa(info);
			cmd_ra(info);
			tmp_min++;
		}
		else
			cmd_pb(info);
	}
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
