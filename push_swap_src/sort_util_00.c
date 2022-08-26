/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:48:18 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/25 23:44:32 by nfukuma          ###   ########.fr       */
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


