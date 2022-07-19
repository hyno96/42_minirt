#ifndef OBJECTS_F_H
# define OBJECTS_F_H

# include "objects.h"

t_sphere *conv_sp(t_list	*head);
t_plane *conv_pl(t_list	*head);
t_cylinder *conv_cy(t_list	*head);
t_dot_light *conv_li(t_list	*head);
t_float	hit_sphere(t_point3 center, t_float radius, t_ray r);
t_float	hit_plane(t_point3 coord, t_vec3 normal_vec, t_ray ray);
t_float	hit_cylinder(t_cylinder cylinder, t_ray ray);
t_point3	ray_at(t_ray ray, t_float t);
t_ray		ray(t_vec3 point, t_vec3 direction);
t_float	mypow(t_float val, int time);
t_float	find_quadratic_formula(t_float a, t_float b, t_float c);
t_float	find_small_solution(t_float sol1, t_float sol2);
t_cone	*conv_cn(t_list *head);
t_float	hit_cone(t_cone *cn, t_ray ray);

#endif