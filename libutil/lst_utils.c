/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 00:43:54 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/26 23:50:31 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutil.h"

t_stack	*new_node(int num)
{
	t_stack	*new_node;

	new_node = ft_calloc(sizeof(t_stack), 1);
	if (new_node == NULL)
		put_error_and_exit();
	new_node->num = num;
	return (new_node);
}

t_stack	*deltop_stk(t_stack *stk_top)
{
	t_stack	*tmp;

	tmp = stk_top->nxt;
	tmp->prv = stk_top->prv;
	stk_top->prv->nxt = tmp;
	free(stk_top);
	return (tmp);
}

t_stack	*addfront_stk(t_stack *stk, t_stack *add_node)
{
	if (stk == NULL)
	{
		stk = add_node;
		add_node->prv = new_node(-1);
		add_node->prv->sentinel_flag = (char)1;
		add_node->nxt = add_node->prv;
		add_node->prv->nxt = add_node;
		add_node->prv->prv = add_node;
	}
	else
	{
		add_node->nxt = stk;
		add_node->prv = stk->prv;
		stk->prv->nxt = add_node;
		stk->prv = add_node;
		stk = add_node;
	}
	return (stk);
}

t_stack	*addback_stk(t_stack *stk, t_stack *add_node)
{
	if (stk == NULL)
	{
		stk = add_node;
		stk->prv = new_node(-1);
		stk->prv->sentinel_flag = (char)1;
		stk->nxt = stk->prv;
		stk->nxt->nxt = stk;
		stk->nxt->prv = stk;
	}
	else
	{
		add_node->nxt = stk->prv;
		add_node->prv = stk->prv->prv;
		stk->prv->prv->nxt = add_node;
		stk->prv->prv = add_node;
	}
	return (stk);
}
