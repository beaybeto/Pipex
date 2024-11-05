# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 20:07:36 by bruiz-ro          #+#    #+#              #
#    Updated: 2024/11/05 21:07:06 by bruiz-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	pipex
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR)

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all : $(LIBFT) $(NAME)

$(LIBFT) : 
		$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT_DIR) -lft

clean :
		rm -rf $(OBJ_DIR)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean : clean
		rm -f $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all clean fclean re