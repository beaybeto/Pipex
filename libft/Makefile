# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:17:03 by bruiz-ro          #+#    #+#              #
#    Updated: 2024/05/09 15:49:11 by bruiz-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 

CFLAGS = -Wall -Wextra -Werror

HEADER = libft.h

SRC = ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_tolower.c \
ft_toupper.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c 

BONUS = ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c

OBJS = $(SRC:.c=.o) 
BONUS_OBJS = $(BONUS:.c=.o) 

all : $(NAME)

%.o : %.c
	cc $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $? 

bonus: $(OBJS) $(BONUS_OBJS)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS) 

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) $(BONUS_OBJS)

re : all fclean 

.PHONY : clean fclean re all bonus