#include "utils.h"

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

t_vec3  vec3_plus_scalar(t_vec3 vec, float x, float y, float z)
{
    vec.x += x;
    vec.y += y;
    vec.z += z;
    return (vec);
}

t_vec3  vec3_minus(t_vec3 vec, t_vec3 vec2)
{
    vec.x -= vec2.x;
    vec.y -= vec2.y;
    vec.z -= vec2.z;
    return (vec);
}

t_vec3  vec3_minus_scalar(t_vec3 vec, float x, float y, float z)
{
    vec.x -= x;
    vec.y -= y;
    vec.z -= z;
    return (vec);
}

t_vec3 vec3_mult(t_vec3 vec, t_vec3 vec2)
{
    vec.x *= vec2.x;
    vec.y *= vec2.y;
    vec.z *= vec2.z;
    return (vec);
}

t_vec3  vec3_mult_scalar(t_vec3 vec, float t)
{
    vec.x *= t;
    vec.y *= t;
    vec.z *= t;
    return (vec);
}

t_vec3  vec3_div(t_vec3 vec, float t)
{
    vec.x *= 1 / t;
    vec.y *= 1 / t;
    vec.z *= 1 / t;
    return (vec);
}

float  vec3_dot(t_vec3 vec, t_vec3 vec2)
{
    return (vec.x * vec2.x + vec.y * vec2.y + vec.z * vec2.z);
}

t_vec3  vec3_cross(t_vec3 vec, t_vec3 vec2)
{
    t_vec3  new;

    new.x = vec.y * vec2.z - vec.z * vec2.y;
    new.y = vec.z * vec2.x - vec.x * vec2.z;
    new.z = vec.x * vec2.y - vec.y * vec2.x;
    return (new);
}

t_vec3  vec3_unit(t_vec3 vec)
{
    float len;

    len = vec3_len(vec);
    if (len == 0)
    {
        printf("Error\n:vec3_unit");
        exit(1);
    }
    vec = vec3_div(vec, len);
    return (vec);
}

t_vec3  vec3_min(t_vec3 vec1, t_vec3 vec2)
{
    if (vec1.x > vec2.x)
        vec1.x = vec2.x;
    if (vec1.y > vec2.y)
        vec1.y = vec2.y;
    if (vec1.z > vec2.z)
        vec1.z = vec2.z;
    return (vec1);
}