#ifndef OBJECT_H
# define OBJECT_H

#include "minirt.h"

enum object_type
{
	LIGHT = 1,
	SPHERE,
	PLANE,
	MIRROR_SPHERE
};

// typedef struct s_sphere
// {
// 	enum object_type type;
// 	t_vec3	coord;
// 	float	radius;
// 	int	color;
// }t_sphere;

// typedef struct s_light
// {
// 	enum object_type type;
// 	t_vec3	coord;
// 	float	lux;
// 	float	color;

// 	float	radius;
// }t_light;

typedef struct s_object
{
	enum object_type type;
	t_vec3	coord;
	int		color;

	float	lux;
	float	radius;
}t_object;

t_object	*new_sphere(t_vec3 coord, float radius, int color);
t_object	*new_light(t_vec3 coord, float radius, float lux, int color);
t_object	*new_mirror_sphere(t_vec3 coord, float radius, int color);
// t_sphere	*conv_sp(t_list *sp);
// t_light		*conv_li(t_list *li);
t_object	*conv_ob(t_list *ob);

#endif