#include "vec3.h"

t_vec3  *ft_vec3_div_float(t_vec3 *target, float t, t_vec3 *v)
{
  return (ft_vec3_multi_float(target, (1 / t), v));
}

float   ft_vec3_dot(t_vec3 *u, t_vec3 *v)
{
  return (u->x * v->x + u->y * v->y + u->z * v->z);
}

float   ft_vec3_len(t_vec3 *target)
{
  return (sqrt(ft_vec3_len_sqr(target)));
}

float   ft_vec3_len_sqr(t_vec3 *target)
{
  float result;

  result = pow(target->x, 2.0)
          + pow(target->y, 2.0)
          + pow(target->z, 2.0);
  return (result);
}

t_vec3  *ft_vec3_unit_vec(t_vec3 *target, t_vec3 *v)
{
  return (ft_vec3_div_float(target, ft_vec3_len(v), v));
}
