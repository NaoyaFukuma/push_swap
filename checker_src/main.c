/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:38:32 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/23 15:10:38 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	init_checker_info(t_info *info, int argc, char **argv);
static void	run_cmd(t_info *info);
static int	check_sorted(t_info *info);

int	main(int argc, char **argv)
{
	t_info	info;

	init_checker_info(&info, argc, argv);
	error_check_and_fill_stack(&info);
	run_cmd(&info);
	if (check_sorted(&info))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

static void	init_checker_info(t_info *info, int argc, char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < (size_t)argc)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		while (argv[i][j] != '\0' && ft_isdigit(argv[i][j]))
			j++;
		if (argv[i][j] != '\0')
			break ;
		i++;
	}
	info->argc = i;
	info->argv = argv;
	info->src_array = NULL;
	info->tmp_array = NULL;
	info->stk_a = NULL;
	info->stk_b = NULL;
	info->cmd_list = ft_calloc(1, 1);
	if (info->cmd_list == NULL)
		put_error_and_exit();
	info->argv_cmd_list = argv[i];
	info->sorted_flag = 1;
}

int	check_sorted(t_info *info)
{
	if (info->stk_b != NULL && info->stk_b->num != -1)
		return (0);
	info->sorted_flag = 1;
	while (info->stk_a->num != -1)
	{
		if (info->stk_a->prv->num > info->stk_a->num)
			info->sorted_flag = 0;
		info->stk_a = info->stk_a->nxt;
	}
	if (info->sorted_flag == 1)
		return (1);
	else
		return (0);
}

void	run_cmd(t_info *info)
{
	while (*(info->argv_cmd_list) != '\0')
	{
		if (*(info->argv_cmd_list) == 's')
			cmd_swap_util(info);
		if (*(info->argv_cmd_list) == 'r')
			cmd_rotate_util(info);
		if (*(info->argv_cmd_list) == 'p')
			cmd_push_util(info);
	}
}
