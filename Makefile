# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktayabal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 15:42:44 by ktayabal          #+#    #+#              #
#    Updated: 2025/01/27 15:42:47 by ktayabal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CCFLAGS = -Werror -Wextra -Wall

MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

LIBFT_DIR = ./include/Libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = ./include/get_next_line
GNL = $(GNL_DIR)/get_next_line.a

SRCS = check_chars_in_map.c \
	check_input.c \
	check_map.c \
	checkpath.c \
	main.c \
	map.c \

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CCFLAGS) -c -o $@ $<

$(NAME): $(LIBFT) $(GNL) $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(MLX_FLAGS) $(LIBFT) $(GNL)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

all : $(NAME)

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean

fclean:	clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean

re:	fclean all

.PHONY:	all clean fclean re
