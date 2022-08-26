/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:39:12 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/26 23:31:04 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../libget_next_line/libget_next_line.h"
# include "../libutil/libutil.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

void	cmd_swap_util(char *cmd, t_info *info);
void	cmd_rotate_util(char *cmd, t_info *info);
void	cmd_push_util(char *cmd, t_info *info);

#endif
