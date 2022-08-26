/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:49:18 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/26 12:32:13 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	division_from_b_to_ander_5(t_info *info, t_chunk *chunk, int *tmp_min, int *tmp_max)
{
	int	pivot;

	*tmp_min = chunk->min;
	*tmp_max = chunk->max;
	pivot = chunk->size / 2 - 1 + chunk->min;
	while (chunk->size-- > 0 && r_cost(info->stk_b, pivot + 1, *tmp_max) != -1)
	{
		if (info->stk_b->num == *tmp_min)
		{
			cmd_pa(info);
			cmd_ra(info);
			(*tmp_min)++;
		}
		else if (info->stk_b->prv->prv->num == *tmp_min)
		{
			cmd_rrb(info);
			cmd_pa(info);
			cmd_ra(info);
			(*tmp_min)++;
		}
		if (info->stk_b->num <= pivot)
			cmd_rb(info);
		else
			cmd_pa(info);
	}
}

void	ra_and_min_incre(t_info *info, t_chunk *chunk)
{
	cmd_ra(info);
	chunk->min++;
}

void	sb_pa(t_info *info)
{
	cmd_sb(info);
	cmd_pa(info);
}

void	pb_sa(t_info *info)
{
	cmd_pb(info);
	cmd_sa(info);
}

void	pb_pb_sa(t_info *info)
{
	cmd_pb(info);
	cmd_pb(info);
	cmd_sa(info);
}
