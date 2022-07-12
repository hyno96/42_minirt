#include "parser.h"

t_bool  set_camera(char **args, t_data *data)
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
    (void)data;
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
