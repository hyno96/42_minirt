# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 13:40:45 by kangkim           #+#    #+#              #
#    Updated: 2022/07/12 17:11:44 by hyno             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = minirt
INCLUDE_DIR = includes
SRC_DIR = srcs

RENDER_DIR = $(SRC_DIR)/render
RENDER_SRCS = complict.c draw.c phong.c render.c trace_dot_light.c

OBJECT_DIR = $(SRC_DIR)/object
OBJECT_SRCS = hit_object.c object_conv.c ray.c

SETTING_DIR = $(SRC_DIR)/setting
SETTING_SRCS = setting.c

VEC3_DIR = $(SRC_DIR)/setting
VEC3_SRCS = vec3_1.c vec3_2.c vec3_3.c

SRCS = main.c mlx_window.c perror.c get_next_line.c hyno_test_main.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
SRCS += $(addprefix $(RENDER_DIR)/, $(RENDER_SRCS))
SRCS += $(addprefix $(OBJECT_DIR)/, $(OBJECT_SRCS))
SRCS += $(addprefix $(SETTING_DIR)/, $(SETTING_SRCS))
SRCS += $(addprefix $(VEC3_DIR)/, $(VEC3_SRCS))

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

INCLUDES = mlx.h libft.h structure.h mlx_window.h perror.h \
			float.h objects.h vec3.h parser.h get_next_line.h \
			ray.h render.h setting.h vec.h
			
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


	




