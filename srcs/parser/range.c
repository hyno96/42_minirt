#include "parser.h"


t_float    *get_range(t_range_type range_type)
{
    static t_float range[6][2] = {
        {0.0, 1.0},
        {0, 255},
        {-1, 1},
        {0, FLOAT_MAX},
        {0, 180},
        {FLOAT_MIN, FLOAT_MAX},
    };

    return (range[range_type]);
}


t_bool  check_range(t_float *args, t_range_type range_type, size_t arg_num)
{
    t_float *range_from_to;
    size_t  idx;

    range_from_to = get_range(range_type);
    idx = 0;
    while (idx < arg_num)
    {
        if (!(range_from_to[0] <= args[idx] && args[idx] <= range_from_to[1]))
            return (FALSE);
        idx++;
    }
    return (TRUE);
}