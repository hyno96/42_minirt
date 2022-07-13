#ifndef IMAGE_H
# define IMAGE_H

struct s_img
{
	void    *img_ptr;
	char    *data_addr;
	int     bits_per_pixel;
	int     size_line;
	int     endian;
	int		x;
	int		y;
};

#endif