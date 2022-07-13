#include <limits.h>

#include "parser.h"
#include "libft.h"


t_bool  str_to_vec3(char *arg, t_float vec3_args[3])
{
    char    **args;
    size_t     idx;
    t_bool  result;
    size_t  arg_num;

    result = TRUE;
    args = ft_split(arg, ',');
    if (args == NULL)
        return (FALSE);
    arg_num = get_arg_num(args);
    if (arg_num != 3)
        return (FALSE);
    idx = 0;
    while (idx < arg_num)
    {
        result &= str_to_float(args[idx], &(vec3_args[idx]));
        idx++;
    }
    free_args(args);
    return (result);
}

// t_bool  str_to_int(char *arg, t_float vec3_args[], int idx)
// {
//     unsigned int    num;

//     num = 0;
//     while (ft_isdigit(*arg))
//     {
//         num = num * 10 + *arg - '0';
//         arg++;
//         if (num > INT_MAX)
//             return (FALSE);
//     }
//     if (*arg != '\0' && *arg != '\n')
//         return (FALSE);
//     vec3_args[idx] = (int)num;
//     return (TRUE);
// }