/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cmd_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:10:05 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/23 13:12:07 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	cmd_push_util(char cmd)
{
	if (cmd == _PA)
		write(1, "pa\n", 3);
	if (cmd == _PB)
		write(1, "pb\n", 3);
	return ;
}

void	cmd_swap_util(char cmd)
{
	if (cmd == _SA)
		write(1, "sa\n", 3);
	if (cmd == _SB)
		write(1, "sb\n", 3);
	if (cmd == _SS)
		write(1, "ss\n", 3);
	return ;
}

void	cmd_rotate_util(char cmd)
{
	if (cmd == _RA)
		write(1, "ra\n", 3);
	if (cmd == _RB)
		write(1, "rb\n", 3);
	if (cmd == _RR)
		write(1, "rr\n", 3);
	return ;
}

void	cmd_r_rotate_util(char cmd)
{
	if (cmd == _RRA)
		write(1, "rra\n", 4);
	if (cmd == _RRB)
		write(1, "rrb\n", 4);
	if (cmd == _RRR)
		write(1, "rrr\n", 4);
	return ;
}

void	put_cmd(t_info *info)
{
	size_t	i;

	i = 0;
	while (info->cmd_list[i] != '\0')
	{
		if (info->cmd_list[i] == _PA || info->cmd_list[i] == _PB)
			cmd_push_util(info->cmd_list[i]);
		if (info->cmd_list[i] == _SA || info->cmd_list[i] == _SB
			|| info->cmd_list[i] == _SS)
			cmd_swap_util(info->cmd_list[i]);
		if (info->cmd_list[i] == _RA || info->cmd_list[i] == _RB
			|| info->cmd_list[i] == _RR)
			cmd_rotate_util(info->cmd_list[i]);
		if (info->cmd_list[i] == _RRA || info->cmd_list[i] == _RRB
			|| info->cmd_list[i] == _RRR)
			cmd_r_rotate_util(info->cmd_list[i]);
		i++;
	}
	return ;
}
