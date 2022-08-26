/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:44:49 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/25 11:56:43 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	cmd_swap_util(char *cmd, t_info *info)
{
	if (cmd[1] == 'a')
		cmd_sa(info);
	if (cmd[1] == 'b')
		cmd_sb(info);
	if (cmd[1] == 's')
		cmd_ss(info);
	return ;
}

void	cmd_rotate_util(char *cmd, t_info *info)
{
	if (cmd[2] == '\n')
	{
		if (cmd[1] == 'a')
			cmd_ra(info);
		if (cmd[1] == 'b')
			cmd_rb(info);
		if (cmd[1] == 'r')
			cmd_rr(info);
		return ;
	}
	else
	{
		if (cmd[2] == 'a')
			cmd_rra(info);
		if (cmd[2] == 'b')
			cmd_rrb(info);
		if (cmd[2] == 'r')
			cmd_rrr(info);
		return ;
	}
}

void	cmd_push_util(char *cmd, t_info *info)
{
	if (cmd[1] == 'a')
		cmd_pa(info);
	if (cmd[1] == 'b')
		cmd_pb(info);
	return ;
}
