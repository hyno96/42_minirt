#include "vec3.h"

t_vec3  vec3(float x, float y, float z)
{
    t_vec3  vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;
    return (vec);
}

void    vec3_set(t_vec3 *vec, float x, float y, float z)
{
    vec->x = x;
    vec->y = y;
    vec->z = z;
}

float  vec3_square_len(t_vec3 vec)
{
    return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

float  vec3_len(t_vec3 vec)
{
    return (sqrt(vec3_square_len(vec)));
}

t_vec3  vec3_plus(t_vec3 vec, t_vec3 vec2)
{
    vec.x += vec2.x;
    vec.y += vec2.y;
    vec.z += vec2.z;
    return (vec);
}