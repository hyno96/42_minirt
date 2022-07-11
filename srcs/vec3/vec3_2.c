#include "vec3.h"

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
