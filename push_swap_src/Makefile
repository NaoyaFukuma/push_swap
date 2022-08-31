# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 21:29:21 by nfukuma           #+#    #+#              #
#    Updated: 2022/09/01 01:45:23 by nfukuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
SRCDIR = ./
SRCNAMES = chunk_util.c create_cmdlist.c main.c optimization_cmdlst.c optimization_util.c put_cmd_util.c sort_util_00.c sort_util_01.c sort_util_02.c sort_util_03.c sort_util_04.c

OBJDIR = ./obj/
OBJS = $(SRCNAMES:%.c=$(OBJDIR)%.o)

LIBDIR = ../libft
UTILDIR = ../libutil
GET_NEXT_LINEDIR = ../libget_next_line

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all : $(OBJDIR) $(NAME)

$(OBJDIR) :
	mkdir -p obj

$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	make -C $(LIBDIR)
	make -C $(UTILDIR)
	make -C $(GET_NEXT_LINEDIR)
	$(CC) $(CFLAGS) -I../includes -L $(LIBDIR) -L $(UTILDIR) -L$(GET_NEXT_LINEDIR) -lutil -lft -lget_next_line -o $@ $^

clean:
			make clean -C $(LIBDIR)
			make clean -C $(UTILDIR)
			make clean -C $(GET_NEXT_LINEDIR)
			rm -rf obj

fclean:		clean
			make fclean -C $(LIBDIR)
			make fclean -C $(UTILDIR)
			make fclean -C $(GET_NEXT_LINEDIR)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
