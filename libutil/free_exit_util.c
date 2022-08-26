/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:09:03 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/25 11:59:08 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_error_and_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	free_stk_and_cmdlist(t_info *info)
{
	t_stack	*tmp;
	while (info->stk_a->sentinel_flag != 1)
	{
		tmp = info->stk_a->nxt;
		free(info->stk_a);
		info->stk_a = tmp;
	}
	free(info->stk_a);
	free(info->stk_b);
	free(info->cmd_list);
	return ;
}
