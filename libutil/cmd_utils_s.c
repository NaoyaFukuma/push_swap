/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 01:41:15 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/23 15:10:38 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutil.h"

void	cmd_sa(t_info *info)
{
	char	*cmd;
	char	*tmp;
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (info->stk_a->nxt->sentinel_flag == 1)
		return ;
	tmp_1 = info->stk_a;
	tmp_2 = info->stk_a->nxt;
	tmp_1->prv->nxt = tmp_2;
	tmp_2->nxt->prv = tmp_1;
	tmp_2->prv = tmp_1->prv;
	tmp_1->prv = tmp_2;
	tmp_1->nxt = tmp_2->nxt;
	tmp_2->nxt = tmp_1;
	info->stk_a = tmp_2;
	cmd = ft_calloc(sizeof(char), 2);
	if (cmd == NULL)
		put_error_and_exit();
	cmd[0] = _SA;
	tmp = ft_strjoin(info->cmd_list, cmd);
	free(info->cmd_list);
	free(cmd);
	info->cmd_list = tmp;
	return ;
}

void	cmd_sb(t_info *info)
{
	char	*cmd;
	char	*tmp;
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (info->stk_b->nxt->sentinel_flag == 1)
		return ;
	tmp_1 = info->stk_b;
	tmp_2 = info->stk_b->nxt;
	tmp_1->prv->nxt = tmp_2;
	tmp_2->nxt->prv = tmp_1;
	tmp_2->prv = tmp_1->prv;
	tmp_1->prv = tmp_2;
	tmp_1->nxt = tmp_2->nxt;
	tmp_2->nxt = tmp_1;
	info->stk_b = tmp_2;
	cmd = ft_calloc(sizeof(char), 2);
	if (cmd == NULL)
		put_error_and_exit();
	cmd[0] = _SB;
	tmp = ft_strjoin(info->cmd_list, cmd);
	free(info->cmd_list);
	free(cmd);
	info->cmd_list = tmp;
	return ;
}

void	cmd_ss(t_info *info)
{
	cmd_sa(info);
	cmd_sb(info);
	return ;
}
