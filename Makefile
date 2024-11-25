# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 20:07:36 by bruiz-ro          #+#    #+#              #
#    Updated: 2024/11/25 13:43:41 by bruiz-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	pipex
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
SRC_DIR = src
OBJ_DIR = obj
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(SRC_DIR) -I$(PRINTF_DIR)

SRCS = $(SRC_DIR)/pipex.c $(SRC_DIR)/utils.c
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all : $(LIBFT_LIB) $(PRINTF_LIB) $(NAME)

$(LIBFT_LIB) : 
		$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_LIB) :
		$(MAKE) -C $(PRINTF_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB)
		$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

clean :
		rm -rf $(OBJ_DIR)
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(PRINTF_DIR) clean

fclean : clean
		rm -f $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(MAKE) -C $(PRINTF_DIR) fclean

re : fclean all

.PHONY : all clean fclean re