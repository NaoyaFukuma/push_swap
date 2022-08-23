# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 21:29:21 by nfukuma           #+#    #+#              #
#    Updated: 2022/08/23 01:06:40 by nfukuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
SRCS		= $(shell echo *.c)

OBJSDIR	=	./obj/
OBJS		= $(SRCS:.c=$(OBJDIR).o)

LIBDIR = ../libft

UTILDIR = ../libutil

all : $(OBJDIR) $(NAME)

$(OBJDIR) :
	mkdir -p obj

$(NAME):	$(OBJS)
			make -C ../libft
			make -C ../libutil
			$(CC) $(CFLAGS) -I../includes $(SRCS) ../libft/libft.a ../libutil/libutil.a -o $(NAME)
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
