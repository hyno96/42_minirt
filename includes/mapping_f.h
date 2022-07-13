#ifndef MAPPING_F_H
# define MAPPING_F_H

# include "vec3.h"
# include "image.h"
# include "t_float.h"
# include "objects.h"
# include "structure.h"

t_bool	load_image(char	*filename, t_img *image, t_data data);
void	get_xy_mapping_sphere(\
	t_float *x, t_float *y, t_vec3 normal_unit, t_sphere sp);
t_color3	get_color_in_texture(t_hit_record record);

#endif