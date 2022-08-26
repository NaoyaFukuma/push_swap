/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:17:04 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/26 22:17:50 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra_and_rb(t_info *info, size_t i)
{
	if (info->cmd_list[i] == _RA && info->cmd_list[i + 1] == _RB)
	{
		info->cmd_list[i] = _RR;
		info->cmd_list[i + 1] = _IGNORE;
	}
	if (info->cmd_list[i] == _RB && info->cmd_list[i + 1] == _RA)
	{
		info->cmd_list[i] = _RR;
		info->cmd_list[i + 1] = _IGNORE;
	}
}

void	pa_and_pb(t_info *info, size_t i)
{
	size_t	j;
	size_t	k;

	if (info->cmd_list[i] == _PA)
	{
		j = 1;
		k = 0;
		while (info->cmd_list[i + j] == _PA)
			j++;
		while (info->cmd_list[i + j + k] == _PB)
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
