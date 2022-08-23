/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:44:49 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/23 02:14:19 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	cmd_swap_util(t_info *info)
{
	if (info->argv_cmd_list[1] == 'a')
		cmd_sa(info);
	if (info->argv_cmd_list[1] == 'b')
		cmd_sb(info);
	if (info->argv_cmd_list[1] == 's')
		cmd_ss(info);
	info->argv_cmd_list += 3;
	return ;
}

void	cmd_rotate_util(t_info *info)
{
	if (info->argv_cmd_list[2] == '\n')
	{
		if (info->argv_cmd_list[1] == 'a')
			cmd_ra(info);
		if (info->argv_cmd_list[1] == 'b')
			cmd_rb(info);
		if (info->argv_cmd_list[1] == 'r')
			cmd_rr(info);
		info->argv_cmd_list += 3;
		return ;
	}
	else
	{
		if (info->argv_cmd_list[2] == 'a')
			cmd_rra(info);
		if (info->argv_cmd_list[2] == 'b')
			cmd_rrb(info);
		if (info->argv_cmd_list[2] == 'r')
			cmd_rrr(info);
		info->argv_cmd_list += 4;
		return ;
	}
}

void	cmd_push_util(t_info *info)
{
	if (info->argv_cmd_list[1] == 'a')
		cmd_pa(info);
	if (info->argv_cmd_list[1] == 'b')
		cmd_pb(info);
	info->argv_cmd_list += 3;
	return ;
}
