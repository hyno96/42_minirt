#include "vec3.h"

t_vec3  *ft_vec3_add(t_vec3 *target, t_vec3 *u, t_vec3 *v)
{
  target->x = u->x + v->x;
  target->y = u->y + v->y;
  target->z = u->z + v->z;
  return (target);
}

t_vec3  *ft_vec3_sub(t_vec3 *target, t_vec3 *u, t_vec3 *v)
{
  target->x = u->x - v->x;
  target->y = u->y - v->y;
  target->z = u->z - v->z;
  return (target);
}

t_vec3  *ft_vec3_multi(t_vec3 *target, t_vec3 *u, t_vec3 *v)
{
  target->x = u->x * v->x;
  target->y = u->y * v->y;
  target->z = u->z * v->z;
  return (target);
}

t_vec3  *ft_vec3_div(t_vec3 *target, t_vec3 *u, t_vec3 *v)
{
  target->x = u->x / v->x;
  target->y = u->y / v->y;
  target->z = u->z / v->z;
  return (target);
}

t_vec3  *ft_vec3_multi_float(t_vec3 *target, float t, t_vec3 *v)
{
  target->x = v->x * t;
  target->y = v->y * t;
  target->z = v->z * t;
  return (target);
}