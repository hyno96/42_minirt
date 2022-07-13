#ifndef STRUCTURE_H_
# define STRUCTURE_H_


# include "vec3.h"
# include "libft.h"
# include "t_float.h"

typedef struct s_window t_window;
typedef struct s_img    t_img;
typedef struct s_camera t_camera;
typedef enum e_bool     t_bool;
typedef struct s_data   t_data;



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

struct s_data
{
    t_window    window;
    t_color3    ambient;
    t_camera    camera;
    t_list      *dot_lights;
    t_list      *object_list;
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

#endif

