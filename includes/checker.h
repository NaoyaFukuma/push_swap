/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:39:12 by nfukuma           #+#    #+#             */
/*   Updated: 2022/08/23 12:56:37 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../libutil/libutil.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

void			cmd_swap_util(t_info *info);
void			cmd_rotate_util(t_info *info);
void			cmd_push_util(t_info *info);

#endif
