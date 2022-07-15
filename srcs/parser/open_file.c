#include <fcntl.h>
#include <stdlib.h>

#include "perror.h"
#include "parser.h"
#include "libft.h"


static t_bool check_file_extension(char *file_name)
{
    char    **args;
    size_t  last_idx;
    t_bool  result;

    result = TRUE;
    args = ft_split(file_name, '.');
    last_idx = 0;
    while (args[last_idx])
        last_idx++;
    if (ft_strcmp(args[last_idx - 1], "rt") != 0)
        result = FALSE;
    free_args(args);
    return (result);
}

int open_rt_file(char *file_name)
{
    int     fd;

    if (!check_file_extension(file_name))
    {
        ft_perror("doesn't .rt file extension");
        return (-1);
    }
    fd = open(file_name, O_RDONLY);
    if (fd < 0)
    {
        ft_perror("can't open file");
        return (-1);
    }
    return (fd);
}
