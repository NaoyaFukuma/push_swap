/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:38:32 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/26 14:25:25 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	init_checker_info(t_info *info, int argc, char **argv);
static void	run_cmd(char *cmd, t_info *info);
static int	check_sorted(t_info *info);

int	main(int argc, char **argv)
{
	t_info	info;
	char	*line;

	init_checker_info(&info, argc, argv);
	error_check_and_fill_stack(&info);
	line = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		run_cmd(line, &info);
		free(line);
	}
	if (check_sorted(&info))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stk_and_cmdlist(&info);
	return (0);
}

static void	init_checker_info(t_info *info, int argc, char **argv)
{
	info->argc = argc;
	info->argv = argv;
	info->src_array = NULL;
	info->tmp_array = NULL;
	info->stk_a = NULL;
	info->stk_b = NULL;
	info->cmd_list = ft_calloc(1, 1);
	if (info->cmd_list == NULL)
		put_error_and_exit();
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

void	run_cmd(char *cmd, t_info *info)
{
	if (*cmd == 's')
		cmd_swap_util(cmd ,info);
	if (*cmd == 'r')
		cmd_rotate_util(cmd ,info);
	if (*cmd == 'p')
		cmd_push_util(cmd ,info);
}
