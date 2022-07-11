#ifndef VEC3_H
# define VEC3_H

# include "float.h"

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;

struct s_vec3
{
	t_float	x;
	t_float	y;
	t_float	z;
};

t_vec3	vec3(float x, float y, float z);
void	vec3_set(t_vec3 *vec, float x, float y, float z);
float	vec3_square_len(t_vec3 vec);
float	vec3_len(t_vec3 vec);
t_vec3	vec3_plus(t_vec3 vec, t_vec3 vec2);
t_vec3	vec3_plus_scalar(t_vec3 vec, float x, float y, float z);
t_vec3	vec3_minus(t_vec3 vec, t_vec3 vec2);
t_vec3	vec3_minus_scalar(t_vec3 vec, float x, float y, float z);
t_vec3	vec3_mult(t_vec3 vec, t_vec3 vec2);
t_vec3	vec3_mult_scalar(t_vec3 vec, float t);
t_vec3	vec3_div(t_vec3 vec, float t);
float	vec3_dot(t_vec3 vec, t_vec3 vec2);
t_vec3	vec3_cross(t_vec3 vec, t_vec3 vec2);
t_vec3	vec3_unit(t_vec3 vec);
t_vec3	vec3_min(t_vec3 vec1, t_vec3 vec2);

#endif