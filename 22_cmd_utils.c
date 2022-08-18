/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22_cmd_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 01:41:15 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/17 20:59:56 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_pa(t_info *info)
{
	char	*cmd;
	char	*tmp;

	info->stk_a_top = addfront_stk(info->stk_a_top,
			new_node(info->stk_b_top->num));
	info->stk_b_top = deltop_stk(info->stk_b_top);
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


	info->stk_b_top = addfront_stk(info->stk_b_top,
			new_node(info->stk_a_top->num));
	info->stk_a_top = deltop_stk(info->stk_a_top);


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

// for radix_sort
// void	cmd_ra_radix(t_info *info)
// {
// 	char	*cmd;
// 	char	*tmp;
//
// 	info->stk_a_top = info->stk_a_top->nxt;
// 	cmd = ft_calloc(sizeof(char), 2);
// 	if (cmd == NULL)
// 		put_error_and_exit();
// 	cmd[0] = _RA;
// 	tmp = ft_strjoin(info->cmd_list, cmd);
// 	free(info->cmd_list);
// 	free(cmd);
// 	info->cmd_list = tmp;
// 	return ;
// }

// for   sort
void	cmd_ra(t_info *info)
{
	char	*cmd;
	char	*tmp;
	t_stack *tmp_1;
	t_stack *tmp_2;

	if (info->stk_a_top->nxt->sentinel_flag == 1)
		return ;
	tmp_1 = info->stk_a_top->prv;
	tmp_2 = info->stk_a_top;
	tmp_1->prv->nxt = tmp_2;
	tmp_2->nxt->prv = tmp_1;
	tmp_2->prv = tmp_1->prv;
	tmp_1->prv = tmp_2;
	tmp_1->nxt = tmp_2->nxt;
	tmp_2->nxt = tmp_1;
	info->stk_a_top = tmp_1->nxt;
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

// for radix sort
// void	cmd_rb_radix(t_info *info)
// {
// 	char	*cmd;
// 	char	*tmp;
//
// 	info->stk_b_top = info->stk_b_top->nxt;
// 	cmd = ft_calloc(sizeof(char), 2);
// 	if (cmd == NULL)
// 		put_error_and_exit();
// 	cmd[0] = _RB;
// 	tmp = ft_strjoin(info->cmd_list, cmd);
// 	free(info->cmd_list);
// 	free(cmd);
// 	info->cmd_list = tmp;
// 	return ;
// }

// for   sort
void	cmd_rb(t_info *info)
{
	char	*cmd;
	char	*tmp;
	t_stack *tmp_1;
	t_stack *tmp_2;

	if (info->stk_b_top->nxt->sentinel_flag == 1)
		return ;
	tmp_1 = info->stk_b_top->prv;
	tmp_2 = info->stk_b_top;
	tmp_1->prv->nxt = tmp_2;
	tmp_2->nxt->prv = tmp_1;
	tmp_2->prv = tmp_1->prv;
	tmp_1->prv = tmp_2;
	tmp_1->nxt = tmp_2->nxt;
	tmp_2->nxt = tmp_1;
	info->stk_b_top = tmp_1->nxt;
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

void	cmd_sa(t_info *info)
{
	char	*cmd;
	char	*tmp;
	t_stack *tmp_1;
	t_stack *tmp_2;

	if (info->stk_a_top->nxt->sentinel_flag == 1)
		return ;
	tmp_1 = info->stk_a_top;
	tmp_2 = info->stk_a_top->nxt;
	tmp_1->prv->nxt = tmp_2;
	tmp_2->nxt->prv = tmp_1;
	tmp_2->prv = tmp_1->prv;
	tmp_1->prv = tmp_2;
	tmp_1->nxt = tmp_2->nxt;
	tmp_2->nxt = tmp_1;
	info->stk_a_top = tmp_2;
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
	t_stack *tmp_1;
	t_stack *tmp_2;

	if (info->stk_b_top->nxt->sentinel_flag == 1)
		return ;
	tmp_1 = info->stk_b_top;
	tmp_2 = info->stk_b_top->nxt;
	tmp_1->prv->nxt = tmp_2;
	tmp_2->nxt->prv = tmp_1;
	tmp_2->prv = tmp_1->prv;
	tmp_1->prv = tmp_2;
	tmp_1->nxt = tmp_2->nxt;
	tmp_2->nxt = tmp_1;
	info->stk_b_top = tmp_2;
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

void	cmd_rra(t_info *info)
{
	char	*cmd;
	char	*tmp;
	t_stack *tmp_1;
	t_stack *tmp_2;

	if (info->stk_a_top->nxt->sentinel_flag == 1)
		return ;
	tmp_1 = info->stk_a_top->prv->prv;
	tmp_2 = info->stk_a_top->prv;
	tmp_1->prv->nxt = tmp_2;
	tmp_2->nxt->prv = tmp_1;
	tmp_2->prv = tmp_1->prv;
	tmp_1->prv = tmp_2;
	tmp_1->nxt = tmp_2->nxt;
	tmp_2->nxt = tmp_1;
	info->stk_a_top = tmp_1;
	cmd = ft_calloc(sizeof(char), 2);
	if (cmd == NULL)
		put_error_and_exit();
	cmd[0] = _RRA;
	tmp = ft_strjoin(info->cmd_list, cmd);
	free(info->cmd_list);
	free(cmd);
	info->cmd_list = tmp;
	return ;
}

void	cmd_rrb(t_info *info)
{
	char	*cmd;
	char	*tmp;
	t_stack *tmp_1;
	t_stack *tmp_2;


	if (info->stk_b_top->nxt->sentinel_flag == 1)
		return ;
	tmp_1 = info->stk_b_top->prv->prv;
	tmp_2 = info->stk_b_top->prv;
	tmp_1->prv->nxt = tmp_2;
	tmp_2->nxt->prv = tmp_1;
	tmp_2->prv = tmp_1->prv;
	tmp_1->prv = tmp_2;
	tmp_1->nxt = tmp_2->nxt;
	tmp_2->nxt = tmp_1;
	info->stk_b_top = tmp_1;
	cmd = ft_calloc(sizeof(char), 2);
	if (cmd == NULL)
		put_error_and_exit();
	cmd[0] = _RRB;
	tmp = ft_strjoin(info->cmd_list, cmd);
	free(info->cmd_list);
	free(cmd);
	info->cmd_list = tmp;
	return ;
}
