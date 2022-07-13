#include <fcntl.h>
#include <stdlib.h>

#include "perror.h"
#include "parser.h"


int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			index;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	index = 0;
	while (us1[index] && us2[index])
	{
		if (us1[index] != us2[index])
			return (us1[index] - us2[index]);
		index++;
	}
	return (us1[index] - us2[index]);
}

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

void    free_args(char **args)
{
    char **temp;

    temp = args;
    while (*temp)
    {
        free(*temp);
        temp++; 
    }
    free(args);
}

size_t  get_arg_num(char **args)
{
    size_t  arg_num;

    arg_num = 0;
    while (args[arg_num])
        arg_num++;
    return (arg_num);
}
