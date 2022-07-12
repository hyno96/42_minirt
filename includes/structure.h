#ifndef STRUCTURE_H_
# define STRUCTURE_H_


# include "vec3.h"
# include "libft.h"
# include "float.h"

typedef struct s_window t_window;
typedef struct s_img    t_img;
typedef struct s_camera t_camera;
typedef enum e_bool     t_bool;
typedef struct s_data   t_data;
typedef struct s_setting	t_setting;



struct s_img
{
	void    *img_ptr;
	char    *data_addr;
	int     bits_per_pixel;
	int     size_line;
	int     endian;
};

struct s_window
{
	void    *mlx_ptr;
	void    *win_ptr;
	t_img   mlx_img;
	int     resolution_x;
	int     resolution_y;
};


enum e_bool
{
	FALSE,
	TRUE
};

struct s_setting
{
	int		row_resolution_render;
	int		render_resolution_x;
	int		render_resolution_y;
	int 	use_dot_light_rgb;
	int		use_dot_light_specular;
	int		use_dot_light_diffuse;
	int		use_ambient;
	int		switch_phong_path;
	t_float	ignore_complict_distance;

	t_float	dot_light_diffuse_ratio;
	t_float	dot_light_specular_ratio;
	t_float	ambient_ratio;
};

struct s_data
{
	t_window    window;
	t_color3    ambient;
	t_camera    *camera;
	t_list      *dot_lights;
	t_list      *object_list;
	t_setting	*setting;
};

struct s_camera
{
	t_point3    origin;
	t_vec3      direction;
	t_vec3      horizontal;
	t_vec3      vertical;
	t_float     focal_len;
	t_point3    left_bottom;
};

# include "setting.h"

void	setting_default(t_data *data);

#endif

