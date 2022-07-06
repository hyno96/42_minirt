#include "vec3.h"

void	ft_vec3_copy(t_vec3 *target, t_vec3 *v)
{
	target->x = v->x;
	target->y = v->y;
	target->z = v->z;
}

t_vec3  *ft_vec3_set_xyz(t_vec3 *target, float x, float y, float z)
{
  target->x = x;
  target->y = y;
  target->z = z;
  return (target);
}