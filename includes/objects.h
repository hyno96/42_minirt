#ifndef OBJECTS_H
# define OBJECTS_H

# include "libft.h"
# include "vec3.h"
# include "structure.h"
# include "ray.h"
# include "image.h"
# include "checkerboard.h"

typedef struct s_dot_light	t_dot_light;
typedef struct s_surf		t_surf;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_ray		t_ray;
typedef struct s_cone		t_cone;
typedef enum e_ctc_type		t_ctc_type;

enum e_ctc_type
{
	CTC_COLOR,
	CTC_TEXTURE,
	CTC_CHECKER,
};

struct s_dot_light
{
	t_point3	origin;
	t_color3	color;
};

struct s_surf
{
	int				use_ctc;
	t_color3		color;
	t_img			texture;
	t_checkerboard	checker;
	t_bool			use_bump_map;
	t_img			bump_map;
};

struct s_sphere
{
	t_point3	origin;
	t_float		radius;
	t_surf		surf;
};

struct s_plane
{
	t_point3	origin;
	t_vec3		normal;
	t_surf		surf;
};

struct s_cylinder
{
	t_point3	origin;
	t_vec3		normal;
	t_float		radius;
	t_float		height;
	t_surf		surf;
};

struct s_cone
{
	t_point3	origin;
	t_vec3		normal;
	t_float		radius;
	t_float		height;
	t_surf		surf;
};


struct s_ray
{
	t_point3	point;
	t_vec3		direction;
	t_float		refractive;
};

#endif