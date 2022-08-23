/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:49:26 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/23 13:07:45 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_chunk	*new_chunk(int min, int max, char stk)
{
	t_chunk	*chunk;

	chunk = ft_calloc(sizeof(t_chunk), 1);
	if (chunk == NULL)
		put_error_and_exit();
	chunk->min = min;
	chunk->max = max;
	chunk->size = chunk->max + 1 - chunk->min;
	chunk->stk = stk;
	chunk->nxt = NULL;
	return (chunk);
}

void	add_b_chunk(t_chunk **chunk, t_chunk *add_node)
{
	t_chunk	*tmp;

	tmp = *chunk;
	if (tmp == NULL)
		tmp = add_node;
	else
	{
		while (tmp->nxt != NULL)
			tmp = tmp->nxt;
		tmp->nxt = add_node;
	}
	return ;
}

t_chunk	*add_f_chunk(t_chunk *chunk, t_chunk *add_node)
{
	if (chunk == NULL)
	{
		add_node->nxt = NULL;
		return (add_node);
	}
	add_node->nxt = chunk;
	return (add_node);
}

void	free_and_nxt(t_chunk **chunk)
{
	t_chunk	*tmp_chunk_pointer;

	tmp_chunk_pointer = (*chunk)->nxt;
	free(*chunk);
	*chunk = tmp_chunk_pointer;
}
