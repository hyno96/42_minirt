#include "parser.h"


static t_float get_sign(char **arg)
{
    if (**arg == '-')
    {
        (*arg)++;
        return (-1.0);
    }
    return (1.0);
}

static t_float get_integer_place(char **arg)
{
    t_float num;

    num = 0.0;
    while (ft_isdigit(**arg))
    {
        num = num * 10 + **arg - '0';
        (*arg)++;
    }
    return (num);
}

static t_bool  check_end(char **arg)
{
    if (**arg == '\0' || **arg == '\n')
        return (TRUE);
    return (FALSE);
}

static t_float get_decimal_place(char **arg)
{
    t_float decimal_place;
    t_float denominator;

    decimal_place = 0.0;
    denominator = 1.0;
    while (ft_isdigit(**arg))
    {
        decimal_place = decimal_place * 10 + **arg - '0';
        denominator *= 10;
        (*arg)++;
    }
    return (decimal_place / denominator);
}


t_bool  str_to_float(char *arg, t_float *num)
{
    t_float sign;
    t_float decimal_place;

    sign = get_sign(&arg);
    *num = get_integer_place(&arg);
    if (check_end(&arg))
    {
        *num = *num * sign;
        return (TRUE);
    }
    if (*arg != '.')
        return (FALSE);
    arg++;
    decimal_place = get_decimal_place(&arg);
    if (*arg != '\0')
        return (FALSE);
    *num = sign * (*num + decimal_place);
    return (TRUE);
}
