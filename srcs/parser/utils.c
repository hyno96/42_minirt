#include <fcntl.h>
#include <stdlib.h>

#include "perror.h"


int open_rt_file(char *file_name)
{
    int fd;

    fd = open(file_name, O_RDONLY);
    if (fd < 0)
    {
        ft_perror("can't open file");
        return (-1);
    }
    return (fd);
}

void    free_lines(char **lines)
{
    char **temp;

    temp = lines;
    while (*temp)
    {
        free(*temp);
        temp++; 
    }
    free(lines);
}