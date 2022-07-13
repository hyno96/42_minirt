#include <math.h>

#include "parser.h"


static void    modify_camera_args(t_float points[3], t_float normals[3], \
                            t_float fov, t_data *data)
{
    t_vec3  vec_y;
    t_vec3  vec_z;
    t_vec3  temp;

    data->camera.origin = vec3(points[0], points[1], points[2]);
    data->camera.direction = vec3(normals[0], normals[1], normals[2]);
    
}

static t_bool  set_camera(char **args, t_data *data)
{
    t_float points[3];
    t_float normals[3];
    t_float fov;

    if (!str_to_vec3(args[1], points) || !check_range(points, RANGE_FLOAT, 3))
        return (FALSE);
    if (!str_to_vec3(args[2], normals) || !check_range(normals, RANGE_NORMAL, 3))
        return (FALSE);
    if (!str_to_float(args[3], &fov) || !check_range(&fov, RANGE_FOV, 1))
        return (FALSE);
    modify_camera_args(points, normals, fov, data);
    return (TRUE);
}

t_bool  parse_camera(t_line_info *line_info, char **args, t_data *data)
{
    size_t  arg_num;

    if (line_info->check_dup & DUP_CHECK_CAMERA)
        return (FALSE);
    line_info->check_dup |= DUP_CHECK_CAMERA;
    arg_num = get_arg_num(args);
    if (arg_num != CAMERA_ARG_NUM)
        return (FALSE);
    if (!set_camera(args, data))
        return (FALSE);
    (void)data;
    return (TRUE);    
}
