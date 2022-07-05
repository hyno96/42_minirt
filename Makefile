# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 13:40:45 by kangkim           #+#    #+#              #
#    Updated: 2022/07/05 15:21:28 by kangkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = minirt
INCLUDE_DIR = includes
SRC_DIR = srcs

SRCS = main.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS = $(SRCS:.c=.o)
INCLUDES = main.h
INCLUDES := $(addprefix $(INCLUDE_DIR)/, $(INCLUDES))

MLX_DIR = $(SRC_DIR)/minilibx
MLX = $(MLX_DIR)/libmlx.a
MLX_FRAMEWORK = -lmlx -framework OpenGL -framework AppKit -lz

$(NAME) : $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(MLX_FRAMEWORK) -I$(INCLUDE_DIR) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

$(MLX) :
	make -C $(MLX_DIR) all

.PHONY : all
all : $(NAME)

.PHONY : clean
clean :
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS)

.PHONY : fclean
fclean : clean
	$(RM) $(NAME)

.PHONY : re
re : fclean all


	





