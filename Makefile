# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaa-s <jaa-s@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/22 12:19:11 by jaa-s             #+#    #+#              #
#    Updated: 2025/12/22 12:19:14 by jaa-s            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	push_swap.c \
		ft_split.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_substr.c \
		push.c \
		rotate.c \
		swap.c \
		chunk_sort.c \
		small_sort.c \
		helper.c \
		normalize.c \
		utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
