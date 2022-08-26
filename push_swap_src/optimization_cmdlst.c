/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_cmdlst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:41:37 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/26 23:48:10 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb_and_pa(t_info *info, size_t i)
{
	size_t	j;
	size_t	k;

	if (info->cmd_list[i] == _PB)
	{
		j = 1;
		k = 0;
		while (info->cmd_list[i + j] == _PB)
			j++;
		while (info->cmd_list[i + j + k] == _PA)
		{
			k++;
			if (j == k)
			{
				while (k--)
					info->cmd_list[i + j + k] = _IGNORE;
				while (j--)
					info->cmd_list[i + j] = _IGNORE;
				break ;
			}
		}
	}
}

void	ra_and_rb_to_rr(t_info *info, size_t i)
{
	size_t	j;

	j = 1;
	if (info->cmd_list[i] == _RA)
	{
		while (info->cmd_list[i + j] == _RB || info->cmd_list[i + j] == _RRB
			|| info->cmd_list[i + j] == _SB || info->cmd_list[i + j] == _IGNORE)
			j++;
		if (info->cmd_list[i + j] == _RRA)
		{
			info->cmd_list[i] = _IGNORE;
			info->cmd_list[i + j] = _IGNORE;
		}
	}
	if (info->cmd_list[i] == _RB)
	{
		while (info->cmd_list[i + j] == _RA || info->cmd_list[i + j] == _RRA
			|| info->cmd_list[i + j] == _SA || info->cmd_list[i + j] == _IGNORE)
			j++;
		if (info->cmd_list[i + j] == _RRB)
		{
			info->cmd_list[i] = _IGNORE;
			info->cmd_list[i + j] = _IGNORE;
		}
	}
}

void	rra_and_rrb(t_info *info, size_t i)
{
	size_t	j;

	j = 1;
	if (info->cmd_list[i] == _RRA)
	{
		while (info->cmd_list[i + j] == _RB || info->cmd_list[i + j] == _RRB
			|| info->cmd_list[i + j] == _SB || info->cmd_list[i + j] == _IGNORE)
			j++;
		if (info->cmd_list[i + j] == _RA)
		{
			info->cmd_list[i] = _IGNORE;
			info->cmd_list[i + j] = _IGNORE;
		}
	}
	if (info->cmd_list[i] == _RRB)
	{
		while (info->cmd_list[i + j] == _RA || info->cmd_list[i + j] == _RRA
			|| info->cmd_list[i + j] == _SA || info->cmd_list[i + j] == _IGNORE)
			j++;
		if (info->cmd_list[i + j] == _RB)
		{
			info->cmd_list[i] = _IGNORE;
			info->cmd_list[i + j] = _IGNORE;
		}
	}
}

void	cmd_optimization(t_info *info)
{
	size_t	i;

	i = 0;
	while (info->cmd_list[i] != '\0')
	{
		if (info->cmd_list[i] == _RA || info->cmd_list[i] == _RB)
			ra_and_rb(info, i);
		if (info->cmd_list[i] == _PA)
			pa_and_pb(info, i);
		if (info->cmd_list[i] == _PB)
			pb_and_pa(info, i);
		if (info->cmd_list[i] == _RA || info->cmd_list[i] == _RB)
			ra_and_rb_to_rr(info, i);
		if (info->cmd_list[i] == _RRA || info->cmd_list[i] == _RRB)
			rra_and_rrb(info, i);
		i++;
	}
}
