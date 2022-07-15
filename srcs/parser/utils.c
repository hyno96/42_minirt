#include <stdlib.h>


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
