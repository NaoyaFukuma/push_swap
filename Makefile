# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 00:34:10 by nfukuma           #+#    #+#              #
#    Updated: 2022/08/28 21:53:01 by nfukuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker
PUSH_SWAP_DIR = ./push_swap_src
CHECKER_DIR = ./checker_src

all:
	make -C $(PUSH_SWAP_DIR)
	cp $(PUSH_SWAP_DIR)/$(PUSH_SWAP) ./

bonus:
	make -C $(CHECKER_DIR)
	cp $(CHECKER_DIR)/$(CHECKER) ./

clean:
	make -C $(CHECKER_DIR) clean;
	make -C $(PUSH_SWAP_DIR) clean;

fclean:
	make -C $(CHECKER_DIR) fclean;
	make -C $(PUSH_SWAP_DIR) fclean;
	rm -f $(PUSH_SWAP)
	rm -f $(CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus
