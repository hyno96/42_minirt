#ifndef VEC3_H_
# define VEC3_H_

# include "t_float.h"

typedef struct s_vec3   t_vec3;
typedef struct s_vec3   t_point3;
typedef struct s_vec3   t_color3;


struct s_vec3
{
    t_float x;
    t_float y;
    t_float z;
};

#endif