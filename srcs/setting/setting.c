#include "setting.h"
#include "structure.h"

void	setting_default(t_data *data)
{
	t_setting	*myset;
	
	myset = malloc(sizeof(t_setting));
	myset->row_resolution_render = 1;
	myset->render_resolution_x = \
		data->window.resolution_x / myset->row_resolution_render;
	myset->render_resolution_y = \
		data->window.resolution_y / myset->row_resolution_render;
	myset->use_dot_light_rgb = 0;
	myset->use_dot_light_specular = 1;
	myset->use_dot_light_diffuse = 1;
	myset->use_ambient = 0;
	myset->switch_phong_path = 0;
	myset->ignore_complict_distance = 0.001;
	myset->dot_light_diffuse_ratio = 0.4;
	myset->dot_light_specular_ratio = 0.4;
	myset->ambient_ratio = 0.2;
	data->setting = myset;
}