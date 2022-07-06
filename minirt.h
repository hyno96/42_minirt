#ifndef MINIRT_H
# define MINIRT_H

# include "mlx/mlx.h"

# include "libft/libft.h"

# include "vec3.h"

# include "object.h"

# include "ray.h"

# include "utils.h"

# include <unistd.h>

typedef struct s_viewport
{
	float	z_dist;
	float	interval_x;
	float	interval_y;
	int		resolution_x;
	int		resolution_y;
}t_viewport;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		resolution_x;
	int		resolution_y;
	int		pixelsize;
	char	*title_text;
}t_mlx_data;


typedef struct s_rootdata
{
	t_viewport *viewport;
	t_mlx_data	*mlx_data;
	t_list		*object_list;
}t_rootdata;

typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

#endif