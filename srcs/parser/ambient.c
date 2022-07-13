#include "parser.h"

#include "t_float.h"

// del
t_vec3  vec3(t_float x, t_float y, t_float z)
{
    t_vec3  vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;

    return (vec);
}

// del
t_vec3  vec3_mult_scalar(t_vec3 vec, t_float t)
{
    vec.x *= t;
    vec.y *= t;
    vec.z *= t;

    return (vec);
}

t_bool  set_ambient(char **args, t_data *data)
{
    t_float ratio;
    t_float color_rgb[3];

    if (!str_to_float(args[1], &ratio) || !check_range(&ratio, RANGE_RATIO, 1))
        return (FALSE);
    if (!str_to_vec3(args[2], color_rgb) || !check_range(color_rgb, RANGE_COLOR, 3))
        return (FALSE);
    printf("ambient\n");
    printf("%f %f %f %f\n", ratio, color_rgb[0], color_rgb[1], color_rgb[2]);
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
