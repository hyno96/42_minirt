#include "../includes/objects_f.h"
#include "../includes/mlx_window.h"
#include "../includes/vec3.h"

static t_vec3	get_plane_orivec(t_point3 point, t_vec3 normal)
{
	t_vec3	rtn;

	if (normal.x == 0)
		return (vec3(1, 0, 0));
	if (normal.y == 0)
		return (vec3(0, 1, 0));
	if (normal.z == 0)
		return (vec3(0, 0, -1));
	rtn.z = -1;
	rtn.x = 0;
	rtn.y = normal.z / normal.y;
	rtn = vec3_unit(rtn);
	return (rtn);
}

static void	set_orivec_2(t_list *head)
{
	t_vec3	plz;
	t_vec3	ori;

	if (head->type == PL)
	{
		ori = (conv_pl(head))->origin;
		plz = (conv_pl(head))->normal;
		(conv_pl(head))->orivec_top = get_plane_orivec(ori, plz);
		(conv_pl(head))->orivec_right = \
			vec3_unit(vec3_cross((conv_pl(head))->orivec_top, plz));
	}
}

void	set_orivec(t_list *head)
{
	t_vec3	plz;
	t_vec3	ori;

	while (head)
	{
		set_orivec_2(head);
		if (head->type == CY)
		{
			ori = (conv_cy(head))->origin;
			plz = (conv_cy(head))->normal;
			(conv_cy(head))->orivec_top = get_plane_orivec(ori, plz);
			(conv_cy(head))->orivec_right = \
				vec3_unit(vec3_cross((conv_cy(head))->orivec_top, plz));
		}
		if (head->type == CN)
		{
			ori = (conv_cn(head))->origin;
			plz = (conv_cn(head))->normal;
			(conv_cn(head))->orivec_top = get_plane_orivec(ori, plz);
			(conv_cn(head))->orivec_right = \
				vec3_unit(vec3_cross((conv_cn(head))->orivec_top, plz));
		}
		head = head->next;
	}
}

void	free_myarr(t_ray **ray_arr, t_color3 **screen)
{
	int	i;

	i = 0;
	while (i < HEIGHT)
	{
		free(ray_arr[i]);
		free(screen[i]);
		i++;
	}
	free(ray_arr);
	free(screen);
}
