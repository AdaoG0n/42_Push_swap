# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 19:29:56 by adamarqu          #+#    #+#              #
#    Updated: 2025/03/08 13:48:00 by adamarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = ./sources
SRCS = $(addprefix sources/, \
       main.c list_utils.c error_ctrl.c validations.c \
       push.c swap.c rotate.c rev_rotate.c \
       sort.c small_sort.c big_sort.c info_utils.c)
				
	
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
PRINTF_DIR = ./libft/ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

PURPLE = \033[0;35m
GREEN = \033[0;32m
RESET = \033[0m
BOLD = \033[1m
WHITE = \033[1;37m
RED = \033[0;31m
BLUE = \033[0;34m

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)
	@printf "$(GREEN)╔════════════════════════════════════════╗$(RESET)\n"
	@printf "$(GREEN)║$(BLUE)    Push_swap compiled successfully!    $(GREEN)║$(RESET)\n"
	@printf "$(GREEN)║$(GREEN)                        by$(BOLD) adamarqu     $(GREEN)║$(RESET)\n"
	@printf "$(GREEN)╚════════════════════════════════════════╝$(RESET)\n"

clean:
	@make clean -s -C $(LIBFT_DIR)
	@make clean -s -C $(PRINTF_DIR)
	@rm -f $(OBJS)
	@printf "$(BLUE)╔════════════════════════════════════════╗$(RESET)\n"
	@printf "$(BLUE)║$(GREEN)         Objects were $(BOLD)cleaned!          $(BLUE)║$(RESET)\n"
	@printf "$(BLUE)╚════════════════════════════════════════╝$(RESET)\n"

silent_clean:
	@make clean -s -C $(LIBFT_DIR)
	@make clean -s -C $(PRINTF_DIR)
	@rm -f $(OBJS)

fclean: silent_clean
	@make fclean -s -C $(LIBFT_DIR)
	@make fclean -s -C $(PRINTF_DIR)
	@rm -f $(NAME)
	@printf "$(BLUE)╔════════════════════════════════════════╗$(RESET)\n"
	@printf "$(BLUE)║$(GREEN)        Everything was $(BOLD)cleaned!         $(BLUE)║$(RESET)\n"
	@printf "$(BLUE)╚════════════════════════════════════════╝$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re silent_clean
