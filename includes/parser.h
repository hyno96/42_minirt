#ifndef PARSER_H_
# define PARSER_H_


# include "structure.h"

typedef struct s_line_info  t_line_info;

enum e_check_dup
{
    DUP_CHECK_A = 1,
    DUP_CHECK_C = 2,
    DUP_CHECK_L = 4,
};

struct s_line_info
{
    char    *line;
    int     check_dup;
};

#include <stdio.h>

t_bool  parse_rt_file(char *file_name, t_data *data);
t_bool  parse_ambient(t_line_info *line_info, char **lines, t_data *data);
t_bool  parse_camera(t_line_info *line_info, char **lines, t_data *data);
t_bool  parse_cylinder(t_line_info *line_info, char **lines, t_data *data);
t_bool  parse_light(t_line_info *line_info, char **lines, t_data *data);
t_bool  parse_plane(t_line_info *line_info, char **lines, t_data *data);
t_bool  parse_sphere(t_line_info *line_info, char **lines, t_data *data);
int     open_rt_file(char *file_name);
void    free_lines(char **lines);


#endif