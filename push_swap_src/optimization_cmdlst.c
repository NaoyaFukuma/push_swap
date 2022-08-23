/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_cmdlst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:41:37 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/23 01:03:59 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	cmd_optimization(t_info *info)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (info->cmd_list[i] != '\0')
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
		if (info->cmd_list[i] == _RA)
		{
			j = 1;
			while (info->cmd_list[i + j] == _RB || info->cmd_list[i + j] == _RRB
				|| info->cmd_list[i + j] == _SB || info->cmd_list[i
				+ j] == _IGNORE)
				j++;
			if (info->cmd_list[i + j] == _RRA)
			{
				info->cmd_list[i] = _IGNORE;
				info->cmd_list[i + j] = _IGNORE;
			}
		}
		if (info->cmd_list[i] == _RB)
		{
			j = 1;
			while (info->cmd_list[i + j] == _RA || info->cmd_list[i + j] == _RRA
				|| info->cmd_list[i + j] == _SA || info->cmd_list[i
				+ j] == _IGNORE)
				j++;
			if (info->cmd_list[i + j] == _RRB)
			{
				info->cmd_list[i] = _IGNORE;
				info->cmd_list[i + j] = _IGNORE;
			}
		}
		if (info->cmd_list[i] == _RRA)
		{
			j = 1;
			while (info->cmd_list[i + j] == _RB || info->cmd_list[i + j] == _RRB
				|| info->cmd_list[i + j] == _SB || info->cmd_list[i
				+ j] == _IGNORE)
				j++;
			if (info->cmd_list[i + j] == _RA)
			{
				info->cmd_list[i] = _IGNORE;
				info->cmd_list[i + j] = _IGNORE;
			}
		}
		if (info->cmd_list[i] == _RRB)
		{
			j = 1;
			while (info->cmd_list[i + j] == _RA || info->cmd_list[i + j] == _RRA
				|| info->cmd_list[i + j] == _SA || info->cmd_list[i
				+ j] == _IGNORE)
				j++;
			if (info->cmd_list[i + j] == _RB)
			{
				info->cmd_list[i] = _IGNORE;
				info->cmd_list[i + j] = _IGNORE;
			}
		}
		// //
		// //
		// //
		// // //
		// // // 		if (info->cmd_list[i] == _PA && info->cmd_list[i
						// + 1] == _PB)
		// // // 		{
		// // // 			info->cmd_list[i] = _IGNORE;
		// // // 			info->cmd_list[i + 1] = _IGNORE;
		// // // 		}
		// // // 		if (info->cmd_list[i] == _PB && info->cmd_list[i
						// + 1] == _PA)
		// // // 		{
		// // // 			info->cmd_list[i] = _IGNORE;
		// // // 			info->cmd_list[i + 1] = _IGNORE;
		// // // 		}
		// //
		if (info->cmd_list[i] == _PB && info->cmd_list[i + 1] == _RA
			&& info->cmd_list[i + 2] == _PA)
		{
			info->cmd_list[i] = _SA;
			info->cmd_list[i + 1] = _RA;
			info->cmd_list[i + 2] = _IGNORE;
		}
		if (info->cmd_list[i] == _PA && info->cmd_list[i + 1] == _RB
			&& info->cmd_list[i + 2] == _PB)
		{
			info->cmd_list[i] = _SB;
			info->cmd_list[i + 1] = _RB;
			info->cmd_list[i + 2] = _IGNORE;
		}
		if (info->cmd_list[i] == _PB && info->cmd_list[i + 1] == _RRA
			&& info->cmd_list[i + 2] == _PA)
		{
			info->cmd_list[i] = _RRA;
			info->cmd_list[i + 1] = _SA;
			info->cmd_list[i + 2] = _IGNORE;
		}
		if (info->cmd_list[i] == _PA && info->cmd_list[i + 1] == _RRB
			&& info->cmd_list[i + 2] == _PB)
		{
			info->cmd_list[i] = _RRB;
			info->cmd_list[i + 1] = _SB;
			info->cmd_list[i + 2] = _IGNORE;
		}
		if (info->cmd_list[i] == _SB && info->cmd_list[i + 1] == _RB
			&& info->cmd_list[i + 2] == _PA)
		{
			info->cmd_list[i] = _PA;
			info->cmd_list[i + 1] = _RB;
			info->cmd_list[i + 2] = _IGNORE;
		}
		if (info->cmd_list[i] == _SA && info->cmd_list[i + 1] == _RA
			&& info->cmd_list[i + 2] == _PB)
		{
			info->cmd_list[i] = _PB;
			info->cmd_list[i + 1] = _RA;
			info->cmd_list[i + 2] = _IGNORE;
		}
		if (info->cmd_list[i] == _SA && info->cmd_list[i + 1] == _PB
			&& info->cmd_list[i + 2] == _RA)
		{
			info->cmd_list[i] = _RA;
			info->cmd_list[i + 1] = _PB;
			info->cmd_list[i + 2] = _IGNORE;
		}
		if (info->cmd_list[i] == _SB && info->cmd_list[i + 1] == _PA
			&& info->cmd_list[i + 2] == _RB)
		{
			info->cmd_list[i] = _RB;
			info->cmd_list[i + 1] = _PA;
			info->cmd_list[i + 2] = _IGNORE;
		}
		if (info->cmd_list[i] == _RRA && info->cmd_list[i + 1] == _PB
			&& info->cmd_list[i + 2] == _SB && info->cmd_list[i + 3] == _PA)
		{
			info->cmd_list[i] = _SA;
			info->cmd_list[i + 1] = _RRA;
			info->cmd_list[i + 2] = _IGNORE;
			info->cmd_list[i + 3] = _IGNORE;
		}
		if (info->cmd_list[i] == _PA && info->cmd_list[i + 1] == _RA
			&& info->cmd_list[i + 2] == _SA && info->cmd_list[i + 3] == _RRA)
		{
			info->cmd_list[i] = _SA;
			info->cmd_list[i + 1] = _PA;
			info->cmd_list[i + 2] = _IGNORE;
			info->cmd_list[i + 3] = _IGNORE;
		}
		if (info->cmd_list[i] == _RRB && info->cmd_list[i + 1] == _PA
			&& info->cmd_list[i + 2] == _SB && info->cmd_list[i + 3] == _PB)
		{
			info->cmd_list[i] = _SB;
			info->cmd_list[i + 1] = _RRB;
			info->cmd_list[i + 2] = _IGNORE;
			info->cmd_list[i + 3] = _IGNORE;
		}
		if (info->cmd_list[i] == _PB && info->cmd_list[i + 1] == _RB
			&& info->cmd_list[i + 2] == _SB && info->cmd_list[i + 3] == _RRB)
		{
			info->cmd_list[i] = _SB;
			info->cmd_list[i + 1] = _PB;
			info->cmd_list[i + 2] = _IGNORE;
			info->cmd_list[i + 3] = _IGNORE;
		}
		if (info->cmd_list[i] == _RRA)
		{
			j = 1;
			while (info->cmd_list[i + j] != _SA && info->cmd_list[i + j] != _RA
				&& info->cmd_list[i + j] != _RRA && info->cmd_list[i + j] != _PA
				&& info->cmd_list[i + j] != _PB)
				j++;
			if (info->cmd_list[i + j] == _RRB)
			{
				info->cmd_list[i] = _IGNORE;
				info->cmd_list[i + j] = _RRR;
			}
		}
		if (info->cmd_list[i] == _RRB)
		{
			j = 1;
			while (info->cmd_list[i + j] != _SB && info->cmd_list[i + j] != _RB
				&& info->cmd_list[i + j] != _RRB && info->cmd_list[i + j] != _PA
				&& info->cmd_list[i + j] != _PB)
				j++;
			if (info->cmd_list[i + j] == _RRA)
			{
				info->cmd_list[i] = _IGNORE;
				info->cmd_list[i + j] = _RRR;
			}
		}
		if (info->cmd_list[i] == _SA)
		{
			j = 1;
			while (info->cmd_list[i + j] != _SA && info->cmd_list[i + j] != _RA
				&& info->cmd_list[i + j] != _RRA && info->cmd_list[i + j] != _PA
				&& info->cmd_list[i + j] != _PB)
				j++;
			if (info->cmd_list[i + j] == _SB)
			{
				info->cmd_list[i] = _IGNORE;
				info->cmd_list[i + j] = _SS;
			}
		}
		if (info->cmd_list[i] == _SB)
		{
			j = 1;
			while (info->cmd_list[i + j] != _SB && info->cmd_list[i + j] != _RB
				&& info->cmd_list[i + j] != _RRB && info->cmd_list[i + j] != _PA
				&& info->cmd_list[i + j] != _PB)
				j++;
			if (info->cmd_list[i + j] == _SA)
			{
				info->cmd_list[i] = _IGNORE;
				info->cmd_list[i + j] = _SS;
			}
		}
		i++;
	}
}
