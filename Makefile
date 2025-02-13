# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adamarqu <adamarqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 19:29:56 by adamarqu          #+#    #+#              #
#    Updated: 2025/02/12 19:38:21 by adamarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes -I ft_printf -g

SRC_DIR = sources
SRC = $(SRC_DIR)/main.c \
       $(SRC_DIR)/list_utils.c \
       $(SRC_DIR)/validate.c \
       $(SRC_DIR)/sort.c \
       $(SRC_DIR)/swap.c \
       $(SRC_DIR)/push.c \
	   $(SRC_DIR)/rotate.c \
	   $(SRC_DIR)/rev_rotate.c \
	   $(SRC_DIR)/radixsort.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = $(LIBFT_DIR)/ft_printf
FT_PRINTF_A = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF_A):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(LIBFT_A) $(FT_PRINTF_A) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) $(FT_PRINTF_A) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re

