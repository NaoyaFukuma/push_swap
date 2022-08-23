/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils_p_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 01:41:15 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/23 15:10:38 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutil.h"

void	cmd_pa(t_info *info)
{
	char	*cmd;
	char	*tmp;

	info->stk_a = addfront_stk(info->stk_a,
									new_node(info->stk_b->num));
	info->stk_b = deltop_stk(info->stk_b);
	cmd = ft_calloc(sizeof(char), 2);
	if (cmd == NULL)
		put_error_and_exit();
	cmd[0] = _PA;
	tmp = ft_strjoin(info->cmd_list, cmd);
	free(info->cmd_list);
	free(cmd);
	info->cmd_list = tmp;
	return ;
}

void	cmd_pb(t_info *info)
{
	char	*cmd;
	char	*tmp;

	info->stk_b = addfront_stk(info->stk_b,
									new_node(info->stk_a->num));
	info->stk_a = deltop_stk(info->stk_a);
	cmd = ft_calloc(sizeof(char), 2);
	if (cmd == NULL)
		put_error_and_exit();
	cmd[0] = _PB;
	tmp = ft_strjoin(info->cmd_list, cmd);
	free(info->cmd_list);
	free(cmd);
	info->cmd_list = tmp;
	return ;
}

void	cmd_ra(t_info *info)
{
	char	*cmd;
	char	*tmp;
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (info->stk_a->nxt->sentinel_flag == 1)
		return ;
	tmp_1 = info->stk_a->prv;
	tmp_2 = info->stk_a;
	tmp_1->prv->nxt = tmp_2;
	tmp_2->nxt->prv = tmp_1;
	tmp_2->prv = tmp_1->prv;
	tmp_1->prv = tmp_2;
	tmp_1->nxt = tmp_2->nxt;
	tmp_2->nxt = tmp_1;
	info->stk_a = tmp_1->nxt;
	cmd = ft_calloc(sizeof(char), 2);
	if (cmd == NULL)
		put_error_and_exit();
	cmd[0] = _RA;
	tmp = ft_strjoin(info->cmd_list, cmd);
	free(info->cmd_list);
	free(cmd);
	info->cmd_list = tmp;
	return ;
}

// for   sort
void	cmd_rb(t_info *info)
{
	char	*cmd;
	char	*tmp;
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (info->stk_b->nxt->sentinel_flag == 1)
		return ;
	tmp_1 = info->stk_b->prv;
	tmp_2 = info->stk_b;
	tmp_1->prv->nxt = tmp_2;
	tmp_2->nxt->prv = tmp_1;
	tmp_2->prv = tmp_1->prv;
	tmp_1->prv = tmp_2;
	tmp_1->nxt = tmp_2->nxt;
	tmp_2->nxt = tmp_1;
	info->stk_b = tmp_1->nxt;
	cmd = ft_calloc(sizeof(char), 2);
	if (cmd == NULL)
		put_error_and_exit();
	cmd[0] = _RB;
	tmp = ft_strjoin(info->cmd_list, cmd);
	free(info->cmd_list);
	free(cmd);
	info->cmd_list = tmp;
	return ;
}

void	cmd_rr(t_info *info)
{
	cmd_ra(info);
	cmd_rb(info);
	return ;
}
