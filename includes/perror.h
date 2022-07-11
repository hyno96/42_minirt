#ifndef PERROR_H_
# define PERROR_H_


# include <stdlib.h>

# include "libft.h"


enum    e_errno
{
    ERR_ARGS = 1,
    ERR_MLX_WIN = 2,
    ERR_PARSING = 3,
};

void ft_perror(char *err_msg);

#endif