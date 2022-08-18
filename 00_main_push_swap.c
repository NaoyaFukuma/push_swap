/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:41:33 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/11 11:21:52 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_info(t_info *info, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc <= 2)
		return (0);
	init_info(&info, argc, argv);
	error_check_and_fill_stack(&info);
	create_cmd_list(&info);
	return (0);
}

static void	init_info(t_info *info, int argc, char **argv)
{
	info->argc = argc;
	info->argv = argv;
	info->src_array = NULL;
	info->tmp_array = NULL;
	info->stk_a_top = NULL;
	info->stk_b_top = NULL;
	info->cmd_list = ft_calloc(1,1);
	if (info->cmd_list == NULL)
		put_error_and_exit();
	info->sorted_flag = 1;
}
