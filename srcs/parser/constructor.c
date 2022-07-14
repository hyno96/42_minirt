#include "parser.h"



t_dot_light dot_light(t_point3 origin, t_color3 color)
{
    t_dot_light light;

    light.origin = origin;
    light.color = color;
    
    return (light);
}

t_surf  surf(t_color3 color)
{
    t_surf  s;

    s.color = color;

    return (s);
}

t_sphere    sphere(t_point3 origin, t_float radius, t_surf surf)
{
    t_sphere    sp;

    sp.origin = origin;
    sp.radius =radius;
    sp.surf = surf;

    return (sp);
}

t_plane    plane(t_point3 origin, t_vec3 normal, t_surf surf)
{
    t_plane    pl;

    pl.origin = origin;
    pl.normal =normal;
    pl.surf = surf;

    return (pl);
}


t_cylinder    cylinder(t_point3 origin, t_vec3 normal, t_float radius, \
                        t_float height, t_surf surf)
{
    t_cylinder    cy;

    cy.origin = origin;
    cy.normal =normal;
    cy.radius = radius;
    cy.height = height;
    cy.surf = surf;

    return (cy);
}
