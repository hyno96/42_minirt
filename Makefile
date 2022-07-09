# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 13:40:45 by kangkim           #+#    #+#              #
#    Updated: 2022/07/09 15:14:59 by kangkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = minirt
INCLUDE_DIR = includes
SRC_DIR = srcs

SRCS = main.c mlx_window.c perror.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

INCLUDES = mlx.h libft.h minirt.h structure.h mlx_window.h perror.h
INCLUDES := $(addprefix $(INCLUDE_DIR)/, $(INCLUDES))


MLX_DIR = $(SRC_DIR)/minilibx
MLX = $(MLX_DIR)/libmlx.dylib
MLX_FRAMEWORK = -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

LIBFT_DIR = $(SRC_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME) : $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX_FRAMEWORK) -I$(INCLUDE_DIR) -o $@ $^
	install_name_tool -change libmlx.dylib $(MLX) $(NAME)

$(MLX) :
	@make -C $(MLX_DIR) all

$(LIBFT) :
	@make -C $(LIBFT_DIR) all

-include $(DEPS)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -MMD -c -o $@ $<

.PHONY : all
all : $(NAME)

.PHONY : clean
clean :
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean
	$(RM) $(DEPS)
	$(RM) $(OBJS)

.PHONY : fclean
fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

.PHONY : re
re : fclean all


	





