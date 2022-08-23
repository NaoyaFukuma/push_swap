# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 01:05:33 by nfukuma           #+#    #+#              #
#    Updated: 2022/08/23 01:07:25 by nfukuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
SRCDIR = ./
SRCNAMES = $(shell echo *.c)
SRCS = $(addprefix $(SRCDIR), $(SRCNAMES))

OBJDIR = ./obj/
OBJS = $(SRCNAMES:%.c=$(OBJDIR)%.o)

LIBDIR = ../libft

UTILDIR = ../libutil

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
	$(CC) $(CFLAGS) -I../includes -L $(LIBDIR) -L $(UTILDIR) -lutil -lft -o $@ $^
clean:
			make clean -C $(LIBDIR)
			make clean -C $(UTILDIR)
			rm -f $(OBJS)

fclean:		clean
			make clean -C $(LIBDIR)
			make clean -C $(UTILDIR)
			rm -f $(OBJS)
			rm -rf obj
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
