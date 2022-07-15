#include "parser.h"

#include "t_float.h"


t_bool  set_ambient(char **args, t_data *data)
{
    t_float ratio;
    t_float color_rgb[3];

    if (!str_to_float(args[1], &ratio) || !check_range(&ratio, RANGE_RATIO, 1))
        return (FALSE);
    if (!str_to_vec3(args[2], color_rgb) || !check_range(color_rgb, RANGE_COLOR, 3))
        return (FALSE);
    data->ambient = vec3_mult_scalar(vec3(color_rgb[0], color_rgb[1], color_rgb[2]), ratio);
    return (TRUE);
}

t_bool  parse_ambient(t_line_info *line_info, char **args, t_data *data)
{
    size_t  arg_num;

    if (line_info->check_dup & DUP_CHECK_AMBIENT)
        return (FALSE);
    line_info->check_dup |= DUP_CHECK_AMBIENT;
    arg_num = get_arg_num(args);
    if (arg_num != AMBIENT_ARG_NUM)
        return (FALSE);
    if (!set_ambient(args, data))
        return (FALSE);
    return (TRUE);
}
