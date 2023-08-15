# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 12:19:35 by sbzizal           #+#    #+#              #
#    Updated: 2023/05/23 12:23:32 by sbzizal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PUSH_SWAP

FLAGS = -Wall -Westra -Werror

CC = cc

MFILES = push_swap.c utils.c ft_lstadd_back.c ft_lstadd_front.c ft_split.c \
instra.c instra2.c min_max.c ft_sort_big.c parsing.c \
parsing2.c ft_sort.c sort_next.c utils_sort.c utils_lst.c\

BFILES = get-next-line/get_next_line.c get-next-line/get_next_line_utils.c checker.c \
ft_lstadd_back.c ft_lstadd_front.c utils.c instra.c instra2.c parsing.c \
parsing2.c min_max.c ft_split.c sort_next.c utils_sort.c utils_lst.c\

MOFILES = $(MFILES:.c=.o)

BOFILES = $(BFILES:.c=.o)

all: banner_man $(NAME)

$(NAME) : $(MOFILES)
	@$(CC) $(MOFILES) -o push_swap

bonus: banner_bns $(BOFILES)
	@$(CC) $(BOFILES) -o checker

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MOFILES) $(BOFILES)

fclean: clean
	rm -f push_swap checker

re: fclean all bonus

PHONY: all clean fclean re

banner_man:
	@echo "\n"
	@echo " ██████╗░██╗░░░██╗░██████╗██╗░░██╗░░░░░░░██████╗░██╗░░░░░░░██╗░█████╗░██████╗░ "
	@echo " ██╔══██╗██║░░░██║██╔════╝██║░░██║░░░░░░██╔════╝░██║░░██╗░░██║██╔══██╗██╔══██╗ "
	@echo " ██████╔╝██║░░░██║╚█████╗░███████║█████╗╚█████╗░░╚██╗████╗██╔╝███████║██████╔╝ "
	@echo " ██╔═══╝░██║░░░██║░╚═══██╗██╔══██║╚════╝░╚═══██╗░░████╔═████║░██╔══██║██╔═══╝░ "
	@echo " ██║░░░░░╚██████╔╝██████╔╝██║░░██║░░░░░░██████╔╝░░╚██╔╝░╚██╔╝░██║░░██║██║░░░░░ "
	@echo " ╚═╝░░░░░░╚═════╝░╚═════╝░╚═╝░░╚═╝░░░░░░╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝╚═╝░░░░░ "
	@echo "\n"
	@echo "--------------------- Making Filles (Mandatory Part)... ----------------------"
	@echo "\n"

banner_bns:
	@echo "\n"
	@echo " ░█████╗░██╗░░██╗███████╗░█████╗░██╗░░██╗███████╗██████╗░ "
	@echo " ██╔══██╗██║░░██║██╔════╝██╔══██╗██║░██╔╝██╔════╝██╔══██╗ "
	@echo " ██║░░╚═╝███████║█████╗░░██║░░╚═╝█████═╝░█████╗░░██████╔╝ "
	@echo " ██║░░██╗██╔══██║██╔══╝░░██║░░██╗██╔═██╗░██╔══╝░░██╔══██╗ "
	@echo " ╚█████╔╝██║░░██║███████╗╚█████╔╝██║░╚██╗███████╗██║░░██║ "
	@echo " ░╚════╝░╚═╝░░╚═╝╚══════╝░╚════╝░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝ "
	@echo "\n"
	@echo "------------- Making Filles (Bonus Part)... ------------"
	@echo "\n"