#include "rtv1.h"

t_object        ft_sphere(t_vec pos, float radius, t_vec color){
    t_object    o;

    ft_bzero(&o, sizeof(t_object));
    o.type = SPHERE;
    o.radius = radius;
    o.pos = pos;
    o.trans = (t_vec){0.0, 0.0, 0.0};
    o.rot = (t_vec){0.0, 0.0, 0.0};
    o.color = color;
    return (o);
}


t_object        ft_plane(t_vec pos, t_vec normal, t_vec color){
    t_object    o;

    ft_bzero(&o, sizeof(t_object));
    o.type = PLANE;
    o.normal = normal;
    o.pos = pos;
    o.trans = (t_vec){0.0, 0.0, 0.0};
    o.rot = (t_vec){0.0, 0.0, 0.0};
    o.color = color;
    return (o);
}

t_object        ft_cone(t_vec pos, t_vec axis, float angle, t_vec color){
    t_object    o;

    ft_bzero(&o, sizeof(t_object));
    o.type = CONE;
    o.axis = axis;
    o.angle = angle;
    o.pos = pos;
    o.trans = (t_vec){0.0, 0.0, 0.0};
    o.rot = (t_vec){0.0, 0.0, 0.0};
    o.color = color;
    return (o);
}

t_object        ft_cylinder(t_vec pos, t_vec axis, float radius, t_vec color){
    t_object    o;

    ft_bzero(&o, sizeof(t_object));
    o.type = CYLINDER;
    o.axis = axis;
    o.radius = radius;
    o.pos = pos;
    o.trans = (t_vec){0.0, 0.0, 0.0};
    o.rot = (t_vec){0.0, 0.0, 0.0};
    o.color = color;
    return (o);
}