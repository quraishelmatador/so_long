# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktayabal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 19:51:29 by ktayabal          #+#    #+#              #
#    Updated: 2025/01/31 19:51:31 by ktayabal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = cc

CCFLAGS = -Werror -Wextra -Wall

AR = ar rcs

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CCFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all : $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
