/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_create_cmd_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:10:50 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/19 00:26:10 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static size_t	get_degits(t_info *info);
// static void		ternary_radix_sort(t_info *info, size_t roop_count);
void	argc_three_sort(t_info *info, int decre);
void	argc_three_r_sort(t_info *info, int decre);
void	argc_ander_six_sort(t_info *info);
void	insert_sort(t_info *info);
ssize_t	rotate_cost(t_stack *stk_p, int min, int max);
ssize_t	r_rotate_cost(t_stack *stk_p, int min, int max);
t_chunk_info	*new_chunk_info(int min, int max, char stk);
t_chunk_info	*addfront_chunk_info(t_chunk_info *chunk_info, t_chunk_info *add_node);
void	add_a_back_chunk_info(t_chunk_info **chunk_info, t_chunk_info *add_node);
void	add_b_back_chunk_info(t_chunk_info **chunk_info, t_chunk_info *add_node);
void	addback_chunk_info(t_chunk_info **chunk_info, t_chunk_info *add_node);

void	recursive_sort(t_info *info);
void	recursive_trisection(t_info *info, t_chunk_info **chunk_info);
void	division_from_a(t_info *info, t_chunk_info **chunk_info, int pivot_num1, int pivot_num2);
void	division_from_b(t_info *info, t_chunk_info **chunk_info, int pivot_num1, int pivot_num2);
void	prefinish_sort(t_info *info, t_chunk_info **chunk_info);
void	size_one(t_info *info, t_chunk_info **chunk_info);
void	size_two(t_info *info, t_chunk_info **chunk_info);
void	size_three(t_info *info, t_chunk_info **chunk_info);
void	size_four(t_info *info, t_chunk_info **chunk_info);
void	size_five(t_info *info, t_chunk_info **chunk_info);
void	size_over_five(t_info *info, t_chunk_info **chunk_info, int pivot_num);
void	finish_sort(t_info *info, t_chunk_info *chunk_info);
void	pre_finish_sort(t_info *info, t_chunk_info **chunk_info);
void	recursive_trisection(t_info *info, t_chunk_info **chunk_info);
void	division_from_a(t_info *info, t_chunk_info **chunk_info, int pivot_num1, int pivot_num2);
void	division_from_b(t_info *info, t_chunk_info **chunk_info, int pivot_num1, int pivot_num2);



void	create_cmd_list(t_info *info)
{
	// size_t	ternary_digits;
	// size_t	roop_count;


	if (info->argc - 1 == 2)
		cmd_sa(info);
	else if (info->argc - 1 == 3)
		argc_three_sort(info, 0);
	else if (info->argc - 1 <= 6)
		argc_ander_six_sort(info);
	else if ((info->argc - 1 > 6))
		recursive_sort(info);
	// {
	// 	ternary_digits = get_degits(info);
	// 	roop_count = 0;
	// 	while (roop_count < ternary_digits)
	// 	{
	// 		ternary_radix_sort(info, roop_count);
	// 		roop_count++;
	// 	}
	// }
	// put_error_and_exit();
	// cmd_optimization(info);
	// cmd_optimization(info);

	// test
	size_t i = 0;
	while (info->cmd_list[i] != '\0')
	{
		if (info->cmd_list[i] == _PA)
			printf("pa\n");
		if (info->cmd_list[i] == _PB)
			printf("pb\n");
		if (info->cmd_list[i] == _RA)
			printf("ra\n");
		if (info->cmd_list[i] == _RB)
			printf("rb\n");
		if (info->cmd_list[i] == _RR)
			printf("rr\n");
		if (info->cmd_list[i] == _SA)
			printf("sa\n");
		if (info->cmd_list[i] == _SB)
			printf("sb\n");
		if (info->cmd_list[i] == _SS)
			printf("ss\n");
		if (info->cmd_list[i] == _RRA)
			printf("rra\n");
		if (info->cmd_list[i] == _RRB)
			printf("rrb\n");
		if (info->cmd_list[i] == _RRR)
			printf("rrr\n");
		i++;
	}

	// printf("\n-------------------\nresult ... %d cmd\n", i);
	exit(0);
	//test
	return ;
}

// static size_t	get_degits(t_info *info)
// {
// 	int		max;
// 	size_t	digits;
//
// 	max = info->argc - 2;
// 	digits = 1;
// 	while (max / 4 != 0)
// 	{
// 		max = max / 4;
// 		digits++;
// 	}
// 	return (digits);
// }
//
//
//
// static void	ternary_radix_sort(t_info *info, size_t roop_count)
// {
// 	int	mod;
// 	int	ra_count;
// 	int	pb_count;
// 	int	i;
//
// 	i = 0;
// 	pb_count = 0;
// 	ra_count = 0;
// 	while (i < info->argc - 1)
// 	{
// 	// printf("\n1111111111111111111");
// 	// show_stk(info);
// 	// usleep(2000000);
// 		mod = (info->stk_a_top->num / ft_pow(4, roop_count)) % 4;
// 		if (mod == 3)
// 		{
// 			cmd_ra(info);
// 		}
// 		else if (mod == 2)
// 		{
// 			cmd_pb(info);
// 			pb_count++;
// 		}
// 		else if (mod == 1)
// 		{
// 			cmd_pb(info);
// 			cmd_rb(info);
// 			pb_count++;
// 		}
// 		else if (mod == 0)
// 		{
// 			cmd_pb(info);
// 			pb_count++;
// 		}
// 		i++;
// 	}
// 	while (pb_count--)
// 	{
// 		mod = (info->stk_b_top->num / ft_pow(4, roop_count)) % 4;
// 		if (mod == 2)
// 			cmd_pa(info);
// 		else if (mod == 1)
// 		{
// 			cmd_pa(info);
// 			cmd_ra(info);
// 			ra_count++;
// 		}
// 		else if (mod == 0)
// 			cmd_rb(info);
// 	}
// 	// printf("\n2222222222222222");
// 	// show_stk(info);
// 	// usleep(3000000);
// 	while (ra_count--)
// 	{
// 		cmd_rra(info);
// 	}
// 	while (info->stk_b_top->sentinel_flag != 1)
// 	{
// 		cmd_pa(info);
// 	}
// 	// printf("\n333333333333333");
// 	// show_stk(info);
// 	// usleep(3000000);
// 	// free(info->stk_b_top);
// 	// info->stk_b_top = NULL;
// 	return ;
// }

void	argc_three_sort(t_info *info, int decre)
{
	if (info->stk_a_top->num - decre == 0 && info->stk_a_top->nxt->num - decre == 2)
	{
		cmd_sa(info);
		cmd_ra(info);
	}
	if (info->stk_a_top->num - decre == 1)
	{
		if (info->stk_a_top->nxt->num - decre == 0)
			cmd_sa(info);
		else if (info->stk_a_top->nxt->num - decre == 2)
			cmd_rra(info);
	}
	if (info->stk_a_top->num - decre == 2)
	{
		if (info->stk_a_top->nxt->num - decre == 0)
			cmd_ra(info);
		else if (info->stk_a_top->nxt->num - decre == 1)
		{
			cmd_sa(info);
			cmd_rra(info);
		}
	}
}

void	argc_three_r_sort(t_info *info, int decre)
{
	if (info->stk_b_top->num - decre == 0)
	{
		if (info->stk_b_top->nxt->num - decre == 1)
		{
			cmd_sb(info);
			cmd_rrb(info);
		}
		else if (info->stk_b_top->nxt->num - decre == 2)
			cmd_rb(info);
	}
	if (info->stk_b_top->num - decre == 1)
	{
		if (info->stk_b_top->nxt->num - decre == 0)
			cmd_rrb(info);
		else if (info->stk_b_top->nxt->num - decre == 2)
			cmd_sb(info);
	}
	if (info->stk_b_top->num - decre == 2)
	{
		if (info->stk_b_top->nxt->num - decre == 0)
		{
			cmd_sb(info);
			cmd_rb(info);
		}
	}
}

void	argc_ander_six_sort(t_info *info)
{
	ssize_t	cost_rotate;
	ssize_t	cost_r_rotate;
	ssize_t	i;
	ssize_t	j;

	j = 0;
	while (j < info->argc - 4)
	{
		cost_rotate = rotate_cost(info->stk_a_top, 0, info->argc - 5);
		cost_r_rotate = r_rotate_cost(info->stk_a_top, 0, info->argc - 5);
		if (cost_rotate == -1)
			break ;
		i = -1;
		if (cost_rotate <= cost_r_rotate)
		{
			while (++i < cost_rotate)
				cmd_ra(info);
			cmd_pb(info);
		}
		else
		{
			while (++i < cost_r_rotate)
				cmd_rra(info);
			cmd_pb(info);
		}
		j++;
	}
	argc_three_sort(info, info->argc - 4);
	if (info->argc - 1 == 4)
		cmd_pa(info);
	if (info->argc - 1 == 5)
	{
		if (info->stk_b_top->num == 0)
			cmd_rb(info);
		cmd_pa(info);
		cmd_pa(info);
	}
	if (info->argc - 1 == 6)
	{
		argc_three_r_sort(info, 0);
		cmd_pa(info);
		cmd_pa(info);
		cmd_pa(info);
	}
}

ssize_t	rotate_cost(t_stack *stk_p, int min, int max)
{
	ssize_t	i;
	ssize_t	count;

	count = 0;
	while (stk_p->sentinel_flag != 1)
	{
		count++;
		stk_p = stk_p->nxt;
	}
	stk_p = stk_p->nxt;
	i = 0;
	while (stk_p->sentinel_flag != 1)
	{
		if (min <= stk_p->num && stk_p->num <= max)
			return (i);
		i++;
		stk_p = stk_p->nxt;
	}
	if (i == count)
		return (-1);
	return (i);
}

ssize_t	r_rotate_cost(t_stack *stk_p, int min, int max)
{
	ssize_t	i;
	ssize_t	count;

	count = 0;
	while (stk_p->sentinel_flag != 1)
	{
		count++;
		stk_p = stk_p->nxt;
	}
	stk_p = stk_p->prv;
	i = 1;
	while (stk_p->sentinel_flag != 1)
	{
		if (min <= stk_p->num && stk_p->num <= max)
			return (i);
		i++;
		stk_p = stk_p->prv;
	}
	if (i - 1 == count)
		return (-1);
	return (i);
}

void	recursive_sort(t_info *info)
{
	t_chunk_info	*chunk_info;

	chunk_info = new_chunk_info(0, info->argc - 2, 'a');
	while (1)
	{
		if (chunk_info->stk == 'a' && chunk_info->size <= 20)
		{
	// printf("\n?????????\n\n");
			pre_finish_sort(info, &chunk_info);
			finish_sort(info, chunk_info);
			break;
		}
		if (chunk_info->stk == 'b' && chunk_info->size <= 10)
		{
			finish_sort(info, chunk_info);
			break ;
		}
		recursive_trisection(info, &chunk_info);
		// printf("\n\nchunk min%d max%d size%d stk_[%c]\n\n",chunk_info->min, chunk_info->max, chunk_info->size, chunk_info->stk);
	}
	return ;
}

void	size_one(t_info *info, t_chunk_info **chunk_info)
{
	t_chunk_info	*tmp;

	cmd_pa(info);
	tmp = (*chunk_info)->nxt;
	free(*chunk_info);
	*chunk_info = tmp;
	return ;
}

void	size_two(t_info *info, t_chunk_info **chunk_info)
{
	t_chunk_info	*tmp;

	if (info->stk_b_top->num == (*chunk_info)->min)
	{
		cmd_sb(info);
		cmd_pa(info);
		cmd_pa(info);
	}
	else
	{
		cmd_pa(info);
		cmd_pa(info);
	}
	tmp = (*chunk_info)->nxt;
	free(*chunk_info);
	*chunk_info = tmp;
	return ;
}

void	size_three(t_info *info, t_chunk_info **chunk_info)
{
	t_chunk_info	*tmp;

	while ((*chunk_info)->size--)
	{
		if (info->stk_b_top->num == (*chunk_info)->min)
		{
			cmd_pa(info);
			cmd_ra(info);
		}
		else if (info->stk_b_top->num == (*chunk_info)->max)
			cmd_pa(info);
		else
			cmd_rb(info);
	}
	cmd_rrb(info);
	cmd_pa(info);
	cmd_rra(info);
	tmp = (*chunk_info)->nxt;
	free(*chunk_info);
	*chunk_info = tmp;
	return ;
}

void	size_four(t_info *info, t_chunk_info **chunk_info)
{
	t_chunk_info	*tmp;

	while ((*chunk_info)->size--)
	{
		if (info->stk_b_top->num == (*chunk_info)->max || info->stk_b_top->num == (*chunk_info)->max - 1)
			cmd_pa(info);
		else if (info->stk_b_top->num == (*chunk_info)->min || info->stk_b_top->num == (*chunk_info)->min + 1)
		{
			cmd_pa(info);
			cmd_ra(info);
		}
	}
	if (info->stk_a_top->num == (*chunk_info)->max)
		cmd_sa(info);
	cmd_rra(info);
	cmd_rra(info);
	if (info->stk_a_top->num != (*chunk_info)->min)
		cmd_sa(info);

	tmp = (*chunk_info)->nxt;
	free(*chunk_info);
	*chunk_info = tmp;
	return ;
}

void	size_five(t_info *info, t_chunk_info **chunk_info)
{
	t_chunk_info	*tmp;

	while ((*chunk_info)->size--)
	{
		if (info->stk_b_top->num == (*chunk_info)->max || info->stk_b_top->num == (*chunk_info)->max - 1)
			cmd_pa(info);
		else if (info->stk_b_top->num == (*chunk_info)->min || info->stk_b_top->num == (*chunk_info)->min + 1)
		{
			cmd_pa(info);
			cmd_ra(info);
		}
		else
			cmd_rb(info);
	}
	if (info->stk_a_top->num == (*chunk_info)->max)
		cmd_sa(info);
	cmd_rrb(info);
	cmd_pa(info);
	cmd_rra(info);
	cmd_rra(info);
	if (info->stk_a_top->num != (*chunk_info)->min)
		cmd_sa(info);
	tmp = (*chunk_info)->nxt;
	free(*chunk_info);
	*chunk_info = tmp;
	return ;
}

void	size_over_five(t_info *info, t_chunk_info **chunk_info, int pivot_num)
{
	t_chunk_info	*tmp;
	int	i;
	int	tmp_max;

	i = 0;
	while (i++ < (*chunk_info)->size)
	{
		if (info->stk_b_top->num <= pivot_num)
			cmd_rb(info);
		else if (info->stk_b_top->num > pivot_num)
			cmd_pa(info);
	}
	i = 0;
	while (pivot_num >= (*chunk_info)->min + i++)
		cmd_rrb(info);
	i = 0;
	while ((*chunk_info)->max > pivot_num + i++)
		cmd_pb(info);
	i = (*chunk_info)->min;
	tmp_max = (*chunk_info)->max;
	tmp = (*chunk_info)->nxt;
	free(*chunk_info);
	*chunk_info = tmp;
	*chunk_info = addfront_chunk_info(*chunk_info, new_chunk_info(i, pivot_num, 'b'));
	*chunk_info = addfront_chunk_info(*chunk_info, new_chunk_info(pivot_num + 1, tmp_max, 'b'));
	return ;
}

void	finish_sort(t_info *info, t_chunk_info *chunk_info)
{
	// int i = 1;

	while (chunk_info != NULL)
	{
		// printf("\n\n[%d]  ", i++);
		// printf("chunk min%d max%d size%d stk_[%c]\n", chunk_info->min, chunk_info->max, chunk_info->size, chunk_info->stk);
		// usleep(1000000);
		// show_stk(info);
		// printf("bbbbbbbbbbbb\n\n");

		if (chunk_info->size == 1)
			size_one(info, &chunk_info);
		else if (chunk_info->size == 2)
			size_two(info, &chunk_info);
		else if (chunk_info->size == 3)
			size_three(info, &chunk_info);
		else if (chunk_info->size == 4)
			size_four(info, &chunk_info);
		else if (chunk_info->size == 5)
			size_five(info, &chunk_info);
		else if (chunk_info->size >= 6)
			size_over_five(info, &chunk_info, chunk_info->size / 2 - 1 + chunk_info->min);
	}
	// printf("\n-----------finish-------------\n\n");
	// show_stk(info);
	return ;
}

void	pre_finish_sort(t_info *info, t_chunk_info **chunk_info)
{
	int	pivot_num;
	t_chunk_info *tmp;
	int	i;

	while ((*chunk_info)->stk == 'a')
	{
		pivot_num = (*chunk_info)->size / 2 - 1 + (*chunk_info)->min;
		i = 0;
		while ((*chunk_info)->size--)
		{
			if (info->stk_a_top->num <= pivot_num)
				cmd_pb(info);
			else if (info->stk_a_top->num > pivot_num)
			{
				cmd_pb(info);
				cmd_rb(info);
				i++;
			}
		}
		while (i--)
			cmd_rrb(info);
		add_a_back_chunk_info(chunk_info, new_chunk_info((*chunk_info)->min, pivot_num, 'b'));
		add_a_back_chunk_info(chunk_info, new_chunk_info(pivot_num + 1, (*chunk_info)->max, 'b'));
		tmp = (*chunk_info)->nxt;
		free(*chunk_info);
		*chunk_info = tmp;
				// printf("aaaaaaaaaa\n\n");
	}
	return ;
}

void	recursive_trisection(t_info *info, t_chunk_info **chunk_info)
{
	int	pivot_num1;
	int	pivot_num2;
	char	stk;

	stk = (*chunk_info)->stk;
	while ((*chunk_info)->stk == stk)
	{
		pivot_num1 = (*chunk_info)->size / 3 - 1 + (*chunk_info)->min;
		if ((*chunk_info)->size % 3 == 2)
			pivot_num2 = ((*chunk_info)->size / 3 - 1) * 2 + 2 + (*chunk_info)->min;
		else
			pivot_num2 = ((*chunk_info)->size / 3 - 1) * 2 + 1 + (*chunk_info)->min;
		if ((*chunk_info)->stk == 'a')
		{
			addback_chunk_info(chunk_info, new_chunk_info(pivot_num2 + 1, (*chunk_info)->max, 'b'));
			addback_chunk_info(chunk_info, new_chunk_info(pivot_num1 + 1, pivot_num2, 'b'));
			addback_chunk_info(chunk_info, new_chunk_info((*chunk_info)->min, pivot_num1, 'b'));
			division_from_a(info, chunk_info, pivot_num1, pivot_num2);
		}
		else
		{
			add_b_back_chunk_info(chunk_info, new_chunk_info(pivot_num2 + 1, (*chunk_info)->max, 'a'));
			add_b_back_chunk_info(chunk_info, new_chunk_info(pivot_num1 + 1, pivot_num2, 'a'));
			add_b_back_chunk_info(chunk_info, new_chunk_info((*chunk_info)->min, pivot_num1, 'a'));
			division_from_b(info, chunk_info, pivot_num1, pivot_num2);
		}
		// printf("stk?? [%c]\n", (*chunk_info)->stk);
	}
	// printf("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\n\n");
	return ;
}

void	division_from_a(t_info *info, t_chunk_info **chunk_info, int pivot_num1, int pivot_num2)
{
	t_chunk_info *tmp;

	// int i = 1;
	// printf("\ndivision_from_a\nchunk min%d max%d size%d stk%c pi1_%d pi2_%d\n\n",(*chunk_info)->min,(*chunk_info)->max, (*chunk_info)->size, (*chunk_info)->stk, pivot_num1, pivot_num2);
		// show_stk(info);
	while ((*chunk_info)->size--)
	{
		// printf("\n\n[%d]", i++);
		if (info->stk_a_top->num > pivot_num2)
			cmd_ra(info);
		else if (info->stk_a_top->num > pivot_num1 && info->stk_a_top->num <= pivot_num2)
		{
			cmd_pb(info);
			cmd_rb(info);
		}
		else if (info->stk_a_top->num <= pivot_num1)
			cmd_pb(info);
	}
	while (pivot_num2 > pivot_num1++)
	{
		// printf("\n\n[%d]", i++);
		// show_stk(info);
		cmd_rrb(info);

	}

	while (pivot_num2++ < (*chunk_info)->max)
	{
		// printf("\n\n[%d]", i++);
		// show_stk(info);

		cmd_rra(info);
		cmd_pb(info);
	}
	// show_stk(info);
	tmp = (*chunk_info)->nxt;
	free(*chunk_info);
	*chunk_info = tmp;
	// printf("aaaaaaaaaaaaaaaaaaaaa\n");
	// printf("chun min%d max%d size%d stk_[%c]\n\n\n",(*chunk_info)->min, (*chunk_info)->max, (*chunk_info)->size, (*chunk_info)->stk);
	return ;
}

void	division_from_b(t_info *info, t_chunk_info **chunk_info, int pivot_num1, int pivot_num2)
{
	t_chunk_info *tmp;


	// int i = 1;
	// printf("\ndivision_from_b\nchunk min%d max%d size%d stk%c pi1_%d pi2_%d\n\n",(*chunk_info)->min,(*chunk_info)->max, (*chunk_info)->size, (*chunk_info)->stk, pivot_num1, pivot_num2);
	// 	show_stk(info);

	while ((*chunk_info)->size--)
	{
		// printf("\n\n[%d]", i++);
		// show_stk(info);
		if (info->stk_b_top->num <= pivot_num1)
			cmd_rb(info);
		else if (info->stk_b_top->num > pivot_num1 && info->stk_b_top->num <= pivot_num2)
		{
			cmd_pa(info);
			cmd_ra(info);
		}
		else if (info->stk_b_top->num > pivot_num2)
			cmd_pa(info);
	}
	while (pivot_num2-- - pivot_num1)
		{
		// printf("\n\n[%d]", i++);
		// show_stk(info);
		cmd_rra(info);

		}
	while (pivot_num1-- >= (*chunk_info)->min)
	{
		// printf("\n\n[%d]", i++);
		cmd_rrb(info);
		cmd_pa(info);
	}
		// show_stk(info);
	tmp = (*chunk_info)->nxt;
	free(*chunk_info);
	*chunk_info = tmp;
	return ;
}

// void	insert_sort(t_info *info)
// {
// 	int	pivot_num1;
// 	int	pivot_num2;
// 	t_chunk_info	*chunk_info;
// 	t_chunk_info	*tmp;
// 	int	i;
//
//
// 	if ((info->argc - 1) % 3 == 2)
// 	{
// 		pivot_num1 = (info->argc - 1) / 3 - 1;
// 		pivot_num2 = pivot_num1 * 2 + 2;
// 	}
// 	else
// 	{
// 		pivot_num1 = (info->argc - 1) / 3 - 1;
// 		pivot_num2 = pivot_num1 * 2 + 1;
// 	}
//
//
//
// 	chunk_info = new_chunk_info(0, info->argc - 2, 'a');
// 	addback_chunk_info(&chunk_info, new_chunk_info(pivot_num2 + 1, info->argc - 2, 'b'));
// 	addback_chunk_info(&chunk_info, new_chunk_info(pivot_num1 + 1, pivot_num2, 'b'));
// 	addback_chunk_info(&chunk_info, new_chunk_info(0, pivot_num1, 'b'));
//
// 		// tmp = chunk_info;
// 		// while (tmp != NULL)
// 		// {
// 		// 	printf("-----\nmin%d  max%d  size%d  stk_%c\n\n",tmp->min,tmp->max, tmp->size,tmp->stk);
// 		// 	tmp = tmp->nxt;
// 		// }
// 	// show_stk(info);
// 	while (chunk_info->size--)
// 	{
// 		if (pivot_num1 >= info->stk_a_top->num)
// 		{
// 			cmd_pb(info);
// 			cmd_rb(info);
// 		}
// 		else if (pivot_num1 < info->stk_a_top->num && info->stk_a_top->num <= pivot_num2)
// 			cmd_pb(info);
// 		else if (info->stk_a_top->num > pivot_num2)
// 			cmd_ra(info);
// 	}
// 	while (info->stk_a_top->sentinel_flag != 1)
// 		cmd_pb(info);
// 	tmp = chunk_info->nxt;
// 	free(chunk_info);
// 	chunk_info = tmp;
// 	if (chunk_info->size <= 5)
// 	{
// 		while (chunk_info != NULL)
// 		{
// 			if (chunk_info->size == 1)
// 				cmd_pa(info);
// 			else if (chunk_info->size == 2)
// 			{
// 				if (info->stk_b_top->num == chunk_info->min)
// 				{
// 					cmd_sb(info);
// 					cmd_pa(info);
// 					cmd_pa(info);
// 				}
// 				else
// 				{
// 					cmd_pa(info);
// 					cmd_pa(info);
// 				}
// 			}
// 			else if (chunk_info->size == 3)
// 			{
// 				if (info->stk_b_top->num == chunk_info->max)
// 				{
// 					cmd_pa(info);
// 					if (info->stk_b_top->num == chunk_info->min)
// 					{
// 						cmd_sb(info);
// 						cmd_pa(info);
// 						cmd_pa(info);
// 					}
// 					else
// 					{
// 						cmd_pa(info);
// 						cmd_pa(info);
// 					}
// 				}
// 				else if (info->stk_b_top->num == chunk_info->min)
// 				{
// 					cmd_pa(info);
// 					cmd_ra(info);
// 					if (info->stk_b_top->num == chunk_info->max)
// 					{
// 						cmd_pa(info);
// 						cmd_pa(info);
// 					}
// 					else
// 					{
// 						cmd_sb(info);
// 						cmd_pa(info);
// 						cmd_pa(info);
// 					}
// 					cmd_rra(info);
// 				}
// 				else
// 				{
// 					cmd_pa(info);
// 					cmd_ra(info);
// 					if (info->stk_b_top->num == chunk_info->max)
// 					{
// 						cmd_pa(info);
// 						cmd_rra(info);
// 						cmd_pa(info);
// 					}
// 					else
// 					{
// 						cmd_sb(info);
// 						cmd_pa(info);
// 						cmd_rra(info);
// 						cmd_pa(info);
// 					}
// 				}
// 			}
// 			else if (chunk_info->size == 4)
// 			{
// 				i = 0;
// 				while (i < chunk_info->size)
// 				{
// 					if (info->stk_b_top->num == chunk_info->max || info->stk_b_top->num == chunk_info->max - 1)
// 						cmd_pa(info);
// 					else if (info->stk_b_top->num == chunk_info->min || info->stk_b_top->num == chunk_info->min + 1)
// 					{
// 						cmd_pa(info);
// 						cmd_ra(info);
// 					}
// 					i++;
// 				}
// 				if (info->stk_a_top->num == chunk_info->max)
// 					cmd_sa(info);
// 				cmd_rra(info);
// 				cmd_rra(info);
// 				if (info->stk_a_top->num != chunk_info->min)
// 					cmd_sa(info);
// 			}
// 			else if (chunk_info->size == 5)
// 			{
// 				i = 0;
// 				while (i < chunk_info->size)
// 				{
// 					if (info->stk_b_top->num == chunk_info->max || info->stk_b_top->num == chunk_info->max - 1)
// 						cmd_pa(info);
// 					else if (info->stk_b_top->num == chunk_info->min || info->stk_b_top->num == chunk_info->min + 1)
// 					{
// 						cmd_pa(info);
// 						cmd_ra(info);
// 					}
// 					else
// 						cmd_rb(info);
// 					i++;
// 				}
// 				if (info->stk_a_top->num == chunk_info->max)
// 					cmd_sa(info);
// 				cmd_rrb(info);
// 				cmd_pa(info);
// 				cmd_rra(info);
// 				cmd_rra(info);
// 				if (info->stk_a_top->num != chunk_info->min)
// 					cmd_sa(info);
// 			}
// 			tmp = chunk_info->nxt;
// 			free(chunk_info);
// 			chunk_info = tmp;
// 		}
// 		return ;
// 	}
//
// 	if (chunk_info->size <= 10)
// 	{
// 		while (chunk_info != NULL)
// 		{
// 			pivot_num1 = chunk_info->size / 2 + chunk_info->min - 1;
// 			i = 0;
// 			pivot_num2 = 0;
// 			while (chunk_info->size--)
// 			{
// 				if (info->stk_b_top->num <= pivot_num1)
// 				{
// 					cmd_rb(info);
// 					i++;
// 				}
// 				else if (info->stk_b_top->num > pivot_num1)
// 				{
// 					cmd_pa(info);
// 					pivot_num2++;
// 				}
// 			}
// 			while (i--)
// 				cmd_rrb(info);
// 			while (pivot_num2--)
// 				cmd_pb(info);
// 			i = chunk_info->min;
// 			pivot_num2 = chunk_info->max;
// 			tmp = chunk_info->nxt;
// 			free(chunk_info);
// 			chunk_info = tmp;
//
// 			// show_stk(info);
//
// 			chunk_info = addfront_chunk_info(chunk_info, new_chunk_info(i, pivot_num1, 'b'));
// 			chunk_info = addfront_chunk_info(chunk_info, new_chunk_info(pivot_num1 + 1, pivot_num2, 'b'));
// // 			printf("chunk 1 min[%d] max[%d] size[%d]\n", chunk_info->min, chunk_info->max, chunk_info->size);
// //
// //
// // 			printf("chunk 2 min[%d] max[%d] size[%d]\n", chunk_info->nxt->min, chunk_info->nxt->max, chunk_info->nxt->size);
// 			// printf("chunk 3 min[%d] max[%d] size[%d]\n", chunk_info->nxt->nxt->min, chunk_info->nxt->nxt->max, chunk_info->nxt->nxt->size);
//
//
// 			i = 0;
// 			while (i++ < 2)
// 			{
// 				if (chunk_info->size == 1)
// 					cmd_pa(info);
// 				else if (chunk_info->size == 2)
// 				{
// 					if (info->stk_b_top->num == chunk_info->min)
// 					{
// 						cmd_sb(info);
// 						cmd_pa(info);
// 						cmd_pa(info);
// 					}
// 					else
// 					{
// 						cmd_pa(info);
// 						cmd_pa(info);
// 					}
// 				}
// 				else if (chunk_info->size == 3)
// 				{
// 					if (info->stk_b_top->num == chunk_info->max)
// 					{
// 						cmd_pa(info);
// 						if (info->stk_b_top->num == chunk_info->min)
// 						{
// 							cmd_sb(info);
// 							cmd_pa(info);
// 							cmd_pa(info);
// 						}
// 						else
// 						{
// 							cmd_pa(info);
// 							cmd_pa(info);
// 						}
// 					}
// 					else if (info->stk_b_top->num == chunk_info->min)
// 					{
// 						cmd_pa(info);
// 						cmd_ra(info);
// 						if (info->stk_b_top->num == chunk_info->max)
// 						{
// 							cmd_pa(info);
// 							cmd_pa(info);
// 						}
// 						else
// 						{
// 							cmd_sb(info);
// 							cmd_pa(info);
// 							cmd_pa(info);
// 						}
// 						cmd_rra(info);
// 					}
// 					else
// 					{
// 						cmd_pa(info);
// 						cmd_ra(info);
// 						if (info->stk_b_top->num == chunk_info->max)
// 						{
// 							cmd_pa(info);
// 							cmd_rra(info);
// 							cmd_pa(info);
// 						}
// 						else
// 						{
// 							cmd_sb(info);
// 							cmd_pa(info);
// 							cmd_rra(info);
// 							cmd_pa(info);
// 						}
// 					}
// 				}
// 				else if (chunk_info->size == 4)
// 				{
// 					i = 0;
// 					while (i < chunk_info->size)
// 					{
// 						if (info->stk_b_top->num == chunk_info->max || info->stk_b_top->num == chunk_info->max - 1)
// 							cmd_pa(info);
// 						else if (info->stk_b_top->num == chunk_info->min || info->stk_b_top->num == chunk_info->min + 1)
// 						{
// 							cmd_pa(info);
// 							cmd_ra(info);
// 						}
// 						i++;
// 					}
// 					if (info->stk_a_top->num == chunk_info->max)
// 						cmd_sa(info);
// 					cmd_rra(info);
// 					cmd_rra(info);
// 					if (info->stk_a_top->num != chunk_info->min)
// 						cmd_sa(info);
// 				}
// 				else if (chunk_info->size == 5)
// 				{
// 					i = 0;
// 					while (i < chunk_info->size)
// 					{
// 						if (info->stk_b_top->num == chunk_info->max || info->stk_b_top->num == chunk_info->max - 1)
// 							cmd_pa(info);
// 						else if (info->stk_b_top->num == chunk_info->min || info->stk_b_top->num == chunk_info->min + 1)
// 						{
// 							cmd_pa(info);
// 							cmd_ra(info);
// 						}
// 						else
// 							cmd_rb(info);
// 						i++;
// 					}
// 					if (info->stk_a_top->num == chunk_info->max)
// 						cmd_sa(info);
// 					cmd_rrb(info);
// 					cmd_pa(info);
// 					cmd_rra(info);
// 					cmd_rra(info);
// 					if (info->stk_a_top->num != chunk_info->min)
// 						cmd_sa(info);
// 				}
// 				tmp = chunk_info->nxt;
// 				free(chunk_info);
// 				chunk_info = tmp;
// 			}
// 		}
// 		return ;
// 	}
//
//
// 	while (chunk_info != NULL)
// 	{
// 		pivot_num1 = chunk_info->size / 3 + chunk_info->min;
// 		pivot_num2 = pivot_num1 + chunk_info->size / 3;
//
// 		while (chunk_info->size--)
// 		{
// 			if (info->stk_b_top->num < pivot_num1)
// 			{
// 				cmd_rb(info);
// 			}
// 			else if (info->stk_b_top->num >= pivot_num1 && info->stk_b_top->num < pivot_num2)
// 			{
// 				cmd_pa(info);
// 				cmd_ra(info);
// 			}
// 			else if (info->stk_b_top->num >= pivot_num2)
// 			{
// 				cmd_pa(info);
// 			}
// 		}
// 		while (pivot_num2-- - pivot_num1)
// 			cmd_rra(info);
// 		while (pivot_num1-- - chunk_info->min)
// 		{
// 			cmd_rrb(info);
// 			cmd_pa(info);
// 		}
// 		tmp = chunk_info->nxt;
// 		free(chunk_info);
// 		chunk_info = tmp;
// 	}
// 	insert_sort(info);
// 	// put_error_and_exit();
// 	return ;
// }

// void	insert_sort(t_info *info)
// {
// 	ssize_t	cost_rotate;
// 	ssize_t	cost_r_rotate;
// 	ssize_t	i;
// 	ssize_t	chunk_count;
//
// 	// show_stk(info);
// 	chunk_count = (info->argc - 1) / 40 + 1;
//
// 	i = 0;
// 	while (i < chunk_count - 1)
// 	{
// 		while (1)
// 		{
// 			cost_rotate = rotate_cost(info->stk_a_top, i * 40, i * 40 - 1);
// 			cost_r_rotate = r_rotate_cost(info->stk_a_top, i * 40, i * 40 - 1);
// 			if (cost_rotate == -1)
// 				break;
// 			if (cost_rotate <= cost_r_rotate)
// 				while (cost_rotate--)
// 					cmd_ra(info);
// 			else
// 				while (cost_r_rotate--)
// 					cmd_rra(info);
// 			cmd_pb(info);
// 			i++;
// 		}
// 		i++;
// 	}
// 	while (info->stk_a_top->sentinel_flag != 1)
// 		cmd_pb(info);
// 	// show_stk(info);
// 	while (info->stk_b_top->sentinel_flag != 1)
// 	{
// 		cost_rotate = rotate_cost(info->stk_b_top, info->argc - 2, info->argc - 2);
// 		cost_r_rotate = r_rotate_cost(info->stk_b_top, info->argc - 2, info->argc - 2);
// 		if (cost_rotate == -1)
// 			break;
// 		if (cost_rotate <= cost_r_rotate)
// 			while (cost_rotate--)
// 				cmd_rb(info);
// 		else
// 			while (cost_r_rotate--)
// 				cmd_rrb(info);
// 		cmd_pa(info);
// 		info->argc--;
// 	}
// 	// show_stk(info);
// 	return ;
// }

t_chunk_info *new_chunk_info(int min, int max, char stk)
{
	t_chunk_info *chunk_info;

	chunk_info = ft_calloc(sizeof(t_chunk_info), 1);
	if (chunk_info == NULL)
		put_error_and_exit();
	chunk_info->min = min;
	chunk_info->max = max;
	chunk_info->size = chunk_info->max + 1 - chunk_info->min;
	chunk_info->stk = stk;
	return (chunk_info);
}

void	addback_chunk_info(t_chunk_info **chunk_info, t_chunk_info *add_node)
{
	t_chunk_info *tmp;

	tmp	= *chunk_info;
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

void	add_a_back_chunk_info(t_chunk_info **chunk_info, t_chunk_info *add_node)
{
	t_chunk_info *tmp;

	tmp	= *chunk_info;
	if (tmp == NULL)
		tmp = add_node;
	else
	{
		while (tmp->nxt != NULL && tmp->nxt->stk == 'a')
			tmp = tmp->nxt;
		if (tmp->nxt == NULL)
			addback_chunk_info(chunk_info, add_node);
		else
		{
			add_node->nxt = tmp->nxt;
			tmp->nxt = add_node;
		}
	}
	return ;
}

void	add_b_back_chunk_info(t_chunk_info **chunk_info, t_chunk_info *add_node)
{
	t_chunk_info *tmp;

	tmp	= *chunk_info;
	if (tmp == NULL)
		tmp = add_node;
	else
	{
		while (tmp->nxt != NULL && tmp->nxt->stk == 'b')
			tmp = tmp->nxt;
		if (tmp->nxt == NULL)
			addback_chunk_info(chunk_info, add_node);
		else
		{
			add_node->nxt = tmp->nxt;
			tmp->nxt = add_node;
		}
	}
	return ;
}

t_chunk_info	*addfront_chunk_info(t_chunk_info *chunk_info, t_chunk_info *add_node)
{
	add_node->nxt = chunk_info;
	return (add_node);
}
