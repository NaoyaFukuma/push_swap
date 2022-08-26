/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_03.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:26:45 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/26 23:21:50 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	v_pa_ra(t_info *info, int count, int *tmp_min)
{
	int	tmp_count;

	tmp_count = count;
	while (tmp_count--)
		cmd_pa(info);
	tmp_count = count;
	while (tmp_count--)
		cmd_ra(info);
	tmp_count = count;
	while (tmp_count--)
		(*tmp_min)++;
}

void	sb_pa_ra_incre(t_info *info, int *tmp_min)
{
	cmd_sb(info);
	cmd_pa(info);
	cmd_ra(info);
	(*tmp_min)++;
}

void	ra_incre(t_info *info, int *tmp_min)
{
	cmd_ra(info);
	(*tmp_min)++;
}

void	sa_ra_incre(t_info *info, int *tmp_min)
{
	cmd_sa(info);
	cmd_ra(info);
	(*tmp_min)++;
}

void	vrrb_pa_ra_incre(t_info *info, int *tmp_min, int rrb_count)
{
	int	tmp_count;

	tmp_count = rrb_count;
	while (tmp_count--)
		cmd_rrb(info);
	tmp_count = rrb_count;
	while (tmp_count--)
	{
		cmd_pa(info);
		cmd_ra(info);
	}
	while (rrb_count--)
		(*tmp_min)++;
}
