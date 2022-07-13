#include "perror.h"


void ft_perror(char *err_msg)
{
    ft_putendl_fd("Error", STDERR_FILENO);
    ft_putendl_fd(err_msg, STDERR_FILENO);
}
