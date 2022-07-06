#include "object.h"

t_object	*new_sphere(t_vec3 coord, float radius, int color)
{
	t_object *new;

	new = malloc(sizeof(t_object));
	ft_vec3_copy(&(new->coord), &(coord));
	new->radius = radius;
	new->color = color;
	new->type = SPHERE;
	return (new);
}

t_object	*new_light(t_vec3 coord, float radius, float lux, int color)
{
	t_object *new;

	new = malloc(sizeof(t_object));
	ft_vec3_copy(&(new->coord), &(coord));
	new->radius = radius;
	new->color = color;
	new->lux = lux;
	new->type = LIGHT;
	return (new);
}

t_object	*new_mirror_sphere(t_vec3 coord, float radius, int color)
{
	t_object *new;

	new = malloc(sizeof(t_object));
	ft_vec3_copy(&(new->coord), &(coord));
	new->radius = radius;
	new->color = color;
	new->type = MIRROR_SPHERE;
	return (new);
}

// t_light	*new_light(t_vec3 coord, float lux, float color)
// {
// 	t_light *new;

// 	new = malloc(sizeof(t_sphere));
// 	ft_vec3_copy(&(new->coord), &(coord));
// 	new->lux = lux;
// 	new->color = color;
// 	new->radius = lux * 100;
// 	return (new);
// }

// t_sphere	*conv_sp(t_list *sp)
// {
// 	return ((t_sphere*)(sp->content));
// }

// t_light	*conv_li(t_list *li)
// {
// 	return ((t_light*)(li->content));
// }

t_object	*conv_ob(t_list *ob)
{
	return ((t_object*)(ob->content));
}