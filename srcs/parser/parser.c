#include <fcntl.h>
#include <stdlib.h>

#include "perror.h"
#include "parser.h"
#include "get_next_line.h"


static t_bool   parse_line(t_line_info *line_info, t_data *data)
{
    char **lines;

    if (ft_strncmp(line_info->line, "\n", 1) == 0)
        return (TRUE);
    lines = ft_split(line_info->line, ' ');
    if (ft_strncmp(line_info->line, "A", 1) == 0)
        return (parse_ambient(line_info, lines, data));
    if (ft_strncmp(line_info->line, "C", 1) == 0)
        return (parse_camera(line_info, lines, data));
    if (ft_strncmp(line_info->line, "L", 1) == 0)
        return (parse_light(line_info, lines, data));
    if (ft_strncmp(line_info->line, "sp", 2) == 0)
        return (parse_sphere(line_info, lines, data));
    if (ft_strncmp(line_info->line, "pl", 2) == 0)
        return (parse_plane(line_info, lines, data));
    if (ft_strncmp(line_info->line, "cy", 2) == 0)
        return (parse_cylinder(line_info, lines, data));
    free_lines(lines);
    return (FALSE);
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