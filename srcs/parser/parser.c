#include <fcntl.h>
#include <stdlib.h>

#include "perror.h"
#include "parser.h"
#include "get_next_line.h"


static t_bool   parse_line(t_line_info *line_info, t_data *data)
{
    char **args;
    t_bool  result;

    if (ft_strncmp(line_info->line, "\n", 1) == 0)
        return (TRUE);
    args = ft_split(line_info->line, ' ');
    if (args == NULL)
        return (FALSE);
    result = FALSE;
    if (ft_strcmp(args[0], "A") == 0)
        result = parse_ambient(line_info, args, data);
    else if (ft_strcmp(args[0], "C") == 0)
        result = parse_camera(line_info, args, data);
    else if (ft_strcmp(args[0], "L") == 0)
        result = parse_dot_light(args, data);
    else if (ft_strcmp(args[0], "sp") == 0)
        result = parse_sphere(args, data);
    else if (ft_strcmp(args[0], "pl") == 0)
        result = parse_plane(args, data);
    else if (ft_strcmp(args[0], "cy") == 0)
        result = parse_cylinder(args, data);
    free_args(args);
    return (result);
}

static t_bool   parse_lines(int fd, t_data *data)
{
    t_line_info line_info;
    
    ft_memset(&line_info, 0, sizeof(t_line_info));
    while (1)
    {
        line_info.line = get_next_line(fd);
        if (line_info.line == NULL)
            break;
        if (!parse_line(&line_info, data))
        {
            free(line_info.line);
            return (FALSE);
        }
        free(line_info.line);
    }
    return (TRUE);
}

t_bool  parse_rt_file(char *file_name, t_data *data)
{
    int fd;

    fd = open_rt_file(file_name);
    if (fd < 0)
        return (FALSE);

    if (!parse_lines(fd, data))
    {
        ft_perror("parsing error");
        return (FALSE);
    }
    close(fd);
    return (TRUE);
}