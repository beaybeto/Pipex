# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 16:56:58 by bruiz-ro          #+#    #+#              #
#    Updated: 2024/06/28 12:16:53 by bruiz-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	libftprintf.a

INCLUDE = ft_printf.h

CFLAGS = -Wall -Wextra -Werror

SOURCE = ft_printf.c \
ft_print_direction.c \
ft_print_hexadecimal_lower.c \
ft_print_hexadecimal_upper.c \
ft_print_unsigned_decimal.c \
ft_putchar.c \
ft_putnbr.c \
ft_putstr.c \

OBJ = $(SOURCE:.c=.o)

all : $(NAME)

%.o : %.c
		gcc $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJ)
		ar -rcs $(NAME) $(OBJ)

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re