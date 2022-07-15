/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:29:36 by kangkim           #+#    #+#             */
/*   Updated: 2022/07/15 20:35:54 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_BONUS_H
# define PARSER_BONUS_H

# include "structure.h"
# include "objects.h"

typedef struct s_line_info				t_line_info;
typedef enum e_range_type				t_range_type;
typedef struct s_sphere_tmp_content		t_sphere_tmp_content;
typedef struct s_plane_tmp_content		t_plane_tmp_content;
typedef struct s_cylinder_tmp_content	t_cylinder_tmp_content;
typedef enum e_element					t_element;
typedef enum e_arg_num					t_arg_num;

enum e_arg_num
{
	AMBIENT_ARG_NUM = 3,
	CAMERA_ARG_NUM = 4,
	LIGHT_ARG_NUM = 4,
	SPHERE_ARG_NUM = 4,
	BONUS_SPHERE_ARG_NUM = 5,
	PLANE_ARG_NUM = 4,
	BONUS_PLANE_ARG_NUM = 5,
	CYLINDER_ARG_NUM = 6,
	BONUS_CYLINDER_ARG_NUM = 7,
};

enum e_range_type
{
	RANGE_RATIO,
	RANGE_COLOR,
	RANGE_NORMAL,
	RANGE_LENGTH,
	RANGE_FOV,
	RANGE_FLOAT,
};

enum e_element
{
	DUP_CHECK_AMBIENT = 1,
	DUP_CHECK_CAMERA = 2,
	DUP_CHECK_LIGHT = 4,
};

struct s_line_info
{
	char	*line;
	int		check_dup;
};

struct s_sphere_tmp_content
{
	t_float	*points;
	t_float	diameter;
	t_float	*colors;
};

struct s_plane_tmp_content
{
	t_float	*points;
	t_float	*normals;
	t_float	*colors;
};

struct s_cylinder_tmp_content
{
	t_float	*points;
	t_float	*normals;
	t_float	diameter;
	t_float	height;
	t_float	*colors;
};

t_bool		parse_rt_file(char *file_name, t_data *data);
t_bool		parse_ambient(t_line_info *line_info, char **args, t_data *data);
t_bool		parse_camera(t_line_info *line_info, char **args, t_data *data);
t_bool		parse_dot_light(t_line_info *line_info, char **args, t_data *data);
t_bool		parse_sphere(char **args, t_data *data);
t_bool		parse_plane(char **args, t_data *data);
t_bool		parse_cylinder(char **args, t_data *data);
int			open_rt_file(char *file_name);
void		free_args(char **args);
int			ft_strcmp(const char *s1, const char *s2);
size_t		get_arg_num(char **args);
t_float		*get_range(t_range_type range_type);
t_bool		str_to_float(char *arg, t_float *num);
t_bool		str_to_vec3(char *arg, t_float vec3_args[3]);
t_bool		check_range(t_float *args, t_range_type range_type, size_t arg_num);
t_bool		load_image(char	*filename, t_img *image, t_data *data);
t_bool		set_checker_board(char **args, t_surf *surf);
t_bool		set_bump_mapping(t_data *data, char **args, t_surf *surf);
t_bool		set_texture(t_data *data, char *arg, t_surf *surf);
t_bool		set_bonus_surf(char **args, t_surf *surf, t_data *data, \
						t_arg_num bonus_arg_num);

#endif