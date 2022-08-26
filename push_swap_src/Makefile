# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 21:29:21 by nfukuma           #+#    #+#              #
#    Updated: 2022/08/25 10:44:24 by nfukuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
SRCDIR = ./
SRCNAMES = $(shell echo *.c)
SRCS = $(addprefix $(SRCDIR), $(SRCNAMES))

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
			rm -f $(OBJS)

fclean:		clean
			make clean -C $(LIBDIR)
			make clean -C $(UTILDIR)
			make clean -C $(GET_NEXT_LINEDIR)
			rm -f $(OBJS)
			rm -rf obj
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
