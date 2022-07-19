CC = cc
CFLAGS = -g #-Wall -Wextra -Werror

NAME = minirt

INCLUDE_DIR = includes
SRC_DIR = srcs

PARSER_DIR = $(SRC_DIR)/parser
PARSER_SRCS = ambient.c camera.c cylinder.c light.c parser.c \
				plane.c sphere.c utils.c str_to_x.c range.c \
				str_to_float.c open_file.c

RENDER_DIR = $(SRC_DIR)/render
RENDER_SRCS = complict.c draw.c phong.c render.c trace_dot_light.c \
				mapping.c checkerboard.c get_pixel_in_map.c\

OBJECTS_DIR = $(SRC_DIR)/objects
OBJECTS_SRCS = hit_object.c object_conv.c ray.c hit_cone.c hit_cylinder.c mymath.c

SETTING_DIR = $(SRC_DIR)/setting
SETTING_SRCS = setting.c

VEC3_DIR = $(SRC_DIR)/vec3
VEC3_SRCS = vec3_1.c vec3_2.c vec3_3.c

SRCS = main.c mlx_window.c perror.c get_next_line.c hyno_test_main.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
SRCS += $(addprefix $(PARSER_DIR)/, $(PARSER_SRCS))
SRCS += $(addprefix $(RENDER_DIR)/, $(RENDER_SRCS))
SRCS += $(addprefix $(OBJECTS_DIR)/, $(OBJECTS_SRCS))
SRCS += $(addprefix $(SETTING_DIR)/, $(SETTING_SRCS))
SRCS += $(addprefix $(VEC3_DIR)/, $(VEC3_SRCS))

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)


BONUS_NAME = minirt_bonus

BONUS_PARSER_DIR = $(SRC_DIR)/parser_bonus
BONUS_PARSER_SRCS = ambient.c camera.c cylinder.c light.c parser.c \
				plane.c sphere.c utils.c str_to_x.c range.c \
				str_to_float.c open_file.c set_surf.c cone.c

BONUS_SRCS = main.c mlx_window.c perror.c get_next_line.c hyno_test_main.c
BONUS_SRCS := $(addprefix $(SRC_DIR)/, $(BONUS_SRCS))
BONUS_SRCS += $(addprefix $(BONUS_PARSER_DIR)/, $(BONUS_PARSER_SRCS))
BONUS_SRCS += $(addprefix $(RENDER_DIR)/, $(RENDER_SRCS))
BONUS_SRCS += $(addprefix $(OBJECTS_DIR)/, $(OBJECTS_SRCS))
BONUS_SRCS += $(addprefix $(SETTING_DIR)/, $(SETTING_SRCS))
BONUS_SRCS += $(addprefix $(VEC3_DIR)/, $(VEC3_SRCS))

BONUS_OBJS = $(BONUS_SRCS:.c=.o)
BONUS_DEPS = $(BONUS_SRCS:.c=.d)

INCLUDES = mlx.h libft.h structure.h mlx_window.h perror.h \
			t_float.h objects.h object_f.h vec3.h parser.h get_next_line.h \
			ray.h render.h setting.h setting_f.h vec.h mapping_f.h \
			
INCLUDES := $(addprefix $(INCLUDE_DIR)/, $(INCLUDES))


MLX_DIR = $(SRC_DIR)/minilibx
MLX = $(MLX_DIR)/libmlx.dylib
MLX_FRAMEWORK = -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

LIBFT_DIR = $(SRC_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME) : $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX_FRAMEWORK) -I$(INCLUDE_DIR) -o $@ $^
	install_name_tool -change libmlx.dylib $(MLX) $(NAME)

$(BONUS_NAME) : $(BONUS_OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX_FRAMEWORK) -I$(INCLUDE_DIR) -o $(BONUS_NAME) $^
	install_name_tool -change libmlx.dylib $(MLX) $(BONUS_NAME)

$(MLX) :
	@make -C $(MLX_DIR) all

$(LIBFT) :
	@make -C $(LIBFT_DIR) all

-include $(DEPS)
-include $(BONUS_DEPS)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -MMD -c -o $@ $<

.PHONY : all
all : $(NAME)

.PHONY : bonus
bonus :  $(BONUS_NAME)

.PHONY : clean
clean :
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean
	$(RM) $(DEPS)
	$(RM) $(OBJS)
	$(RM) $(BONUS_DEPS)
	$(RM) $(BONUS_OBJS)

.PHONY : fclean
fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

.PHONY : re
re : fclean all


	




