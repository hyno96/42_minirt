#ifndef STRUCTURE_H_
# define STRUCTURE_H_


typedef struct s_window t_window;
typedef struct s_img    t_img;
typedef enum e_bool     t_bool;


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
};


enum e_bool
{
    FALSE,
    TRUE
};


#endif