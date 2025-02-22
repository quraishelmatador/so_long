# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktayabal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 14:57:06 by ktayabal          #+#    #+#              #
#    Updated: 2024/04/28 14:57:10 by ktayabal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
SRC = ft_isalpha \
ft_atoi \
ft_bzero \
ft_calloc \
ft_isalnum \
ft_isalpha \
ft_isascii \
ft_isdigit \
ft_isprint \
ft_itoa \
ft_memchr \
ft_memcmp \
ft_memcpy \
ft_memmove \
ft_memset \
ft_perror \
ft_putchar_fd \
ft_putendl_fd \
ft_putnbr_fd \
ft_putstr_fd \
ft_split \
ft_strchr \
ft_strdup \
ft_striteri \
ft_strmapi \
ft_strjoin \
ft_strlcat \
ft_strlcpy \
ft_strlen \
ft_strncmp \
ft_strrchr \
ft_strnstr \
ft_strtrim \
ft_substr \
ft_tolower \
ft_toupper
BONUS_SRC = ft_lstadd_front \
ft_lstadd_back \
ft_lstclear \
ft_lstdelone \
ft_lstiter \
ft_lstlast \
ft_lstmap \
ft_lstnew \
ft_lstsize \

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))
BONUS_SRCS = $(addsuffix .c, $(BONUS_SRC))
BONUS_OBJS = $(addsuffix .o, $(BONUS_SRC))

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
