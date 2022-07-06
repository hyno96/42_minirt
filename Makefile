# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 15:07:00 by suhshin           #+#    #+#              #
#    Updated: 2022/07/06 14:48:35 by hyno             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	a.out

#
# SRCS and OBJS
#

SRCS	=	\
			minirt.c \
			expose.c \
			vec3_1.c \
			vec3_2.c \
			vec3_3.c \
			object.c \
			utils.c \
			ray.c

OBJS = $(SRCS:%.c=%.o)

#
# Compiler and flags
#

CC		=	clang
CFLAGS	=	-g #-Wall -Werror -Wextra 
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

LIBFT	=	libft/libft.a

#
# Rules
#

all		: $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME) $(LIBFT)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all