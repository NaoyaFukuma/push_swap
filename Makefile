# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 21:29:21 by nfukuma           #+#    #+#              #
#    Updated: 2022/08/17 21:24:12 by nfukuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1		= push_swap
B_NAME		= checker
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
SRCS		= 00_main_push_swap.c 10_compress_utils.c 11_create_cmd_list.c 20_lst_utils.c 21_exit_utils.c 22_cmd_utils.c 12_cmd_optimization.c
OBJS		= $(SRCS:.c=.o)
all:		$(NAME1)
$(NAME1):	$(OBJS)
			make -C ./libft
			$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME1)
$(B_NAME):	$(B_OBJS)
			make -C ./libft
			$(CC) $(CFLAGS) $(B_SRCS) libft/libft.a -o $(B_NAME)
clean:
			make clean -C ./libft
			$(RM) $(OBJS) $(BONUS_OBJS)
fclean:		clean
			make fclean -C ./libft
			$(RM) $(NAME1)
re:			fclean $(NAME1)
bonus:	$(NAME) $(B_NAME)
.PHONY:		all clean fclean re
