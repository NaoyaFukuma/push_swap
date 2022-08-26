/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 00:20:40 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/27 00:10:21 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutil.h"

static int	error_check_and_atoi(char *str);
static void	error_check_dup(int *array, size_t count);
static void	compression_and_fill_stack(t_info *info);
static void	quick_sort(int *array, int pivot, int left, int right);

void	error_check_and_fill_stack(t_info *info)
{
	int	i;

	info->src_array = ft_calloc(sizeof(int), info->argc - 1);
	if (info->src_array == NULL)
		put_error_and_exit();
	i = 0;
	while (i < info->argc - 1)
	{
		info->src_array[i] = error_check_and_atoi(info->argv[i + 1]);
		if (i != 0 && info->src_array[i - 1] > info->src_array[i])
			info->sorted_flag = 0;
		error_check_dup(info->src_array, i);
		i++;
	}
	compression_and_fill_stack(info);
	return ;
}

static int	error_check_and_atoi(char *str)
{
	long	res;
	int		sign_flag;

	sign_flag = 1;
	if (*str == '-')
	{
		sign_flag = -1;
		str++;
	}
	if (*str == '+')
		str++;
	res = 0;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == false)
			put_error_and_exit();
		res = (10 * res) + (*str - '0') * sign_flag;
		if (res < INT_MIN || INT_MAX < res)
			put_error_and_exit();
		str++;
	}
	return ((int)res);
}

static void	error_check_dup(int *array, size_t count)
{
	size_t	i;

	i = -1;
	while (++i < count)
		if (array[i] == array[count])
			put_error_and_exit();
	return ;
}

static void	compression_and_fill_stack(t_info *info)
{
	int	i;
	int	j;

	info->tmp_array = ft_calloc(sizeof(int), info->argc - 1);
	if (info->tmp_array == NULL)
		put_error_and_exit();
	ft_memcpy(info->tmp_array, info->src_array, sizeof(int) * (info->argc - 1));
	quick_sort(info->tmp_array, info->tmp_array[(0 + info->argc - 2) / 2], 0,
		info->argc - 2);
	i = 0;
	while (i < info->argc - 1)
	{
		j = 0;
		while (j < info->argc - 1)
		{
			if (info->src_array[i] == info->tmp_array[j])
				info->stk_a = addback_stk(info->stk_a, new_node(j));
			j++;
		}
		i++;
	}
	free(info->src_array);
	free(info->tmp_array);
	return ;
}

static void	quick_sort(int *array, int pivot, int left, int right)
{
	int	pl;
	int	pr;

	pl = left;
	pr = right;
	while (1)
	{
		while (array[pl] < pivot)
			pl++;
		while (array[pr] > pivot)
			pr--;
		if (pl <= pr)
			swap(&array[pl], &array[pr], &pl, &pr);
		if (pl > pr)
			break ;
	}
	if (left < pr)
		quick_sort(array, array[(left + pr) / 2], left, pr);
	if (pl < right)
		quick_sort(array, array[(pl + right) / 2], pl, right);
	return ;
}
