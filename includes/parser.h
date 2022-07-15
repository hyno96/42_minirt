#ifndef PARSER_H_
# define PARSER_H_


# include "structure.h"
# include "objects.h"

typedef struct s_line_info              t_line_info;
typedef enum e_range_type               t_range_type;
typedef struct s_cylinder_tmp_content   t_cylinder_tmp_content;

enum e_arg_num
{
    AMBIENT_ARG_NUM = 3,
    CAMERA_ARG_NUM = 4,
    LIGHT_ARG_NUM = 4,
    SPHERE_ARG_NUM = 4,
    PLANE_ARG_NUM = 4,
    CYLINDER_ARG_NUM = 6,
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

enum e_check_dup
{
    DUP_CHECK_AMBIENT = 1,
    DUP_CHECK_CAMERA = 2,
};

struct s_line_info
{
    char    *line;
    int     check_dup;
};

struct s_cylinder_tmp_content
{
    t_float *points;
    t_float *normals;
    t_float diameter;
    t_float height;
    t_float *colors;
};


t_bool      parse_rt_file(char *file_name, t_data *data);
t_bool      parse_ambient(t_line_info *line_info, char **args, t_data *data);
t_bool      parse_camera(t_line_info *line_info, char **args, t_data *data);
t_bool      parse_dot_light(char **args, t_data *data);
t_bool      parse_sphere(char **args, t_data *data);
t_bool      parse_plane(char **args, t_data *data);
t_bool      parse_cylinder(char **args, t_data *data);
int         open_rt_file(char *file_name);
void        free_args(char **args);
int	        ft_strcmp(const char *s1, const char *s2);
size_t      get_arg_num(char **args);
t_float    *get_range(t_range_type range_type);
t_bool      str_to_float(char *arg, t_float *num);
t_bool      str_to_vec3(char *arg, t_float vec3_args[3]);
// t_bool      str_to_int(char *arg, t_float color_rgb[], int idx);
t_bool      check_range(t_float *args, t_range_type range_type, size_t arg_num);
t_dot_light dot_light(t_point3 origin, t_color3 color);
t_sphere    sphere(t_point3 origin, t_float radius, t_surf surf);
t_plane     plane(t_point3 origin, t_vec3 normal, t_surf surf);
t_cylinder  cylinder(t_point3 origin, t_vec3 normal, t_float radius, \
                        t_float height, t_surf surf);




#endif