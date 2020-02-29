#include "rtv1.h"

void    ft_parse_sphere(t_mx *v, char **token){
    t_object    object;
    int         len;
    
    ft_bzero(&object, sizeof(t_object));
    object.type = SPHERE;
    len = ft_strsplit_len(token);
    if (len > 2 && token[1])
        object.pos = string_to_vect(token[1]);
    if (len > 3 && token[2])
            object.radius = ft_atof(token[2]);
    if (len > 4 && token[3])
        object.color = vect_from_hexa(ft_special_atoi_base(token[3]));
    ft_object_push(&v->objects, ft_object_new(object));
}

void    ft_parse_plane(t_mx *v, char **token){
    t_object    object;
    int         len;
    
    ft_bzero(&object, sizeof(t_object));
    object.type = PLANE;
    len = ft_strsplit_len(token);
    if (len > 2 && token[1])
        object.pos = string_to_vect(token[1]);
    if (len > 3 && token[2])
        object.normal = string_to_vect(token[2]);
    if (len > 4 && token[3])
        object.color = vect_from_hexa(ft_special_atoi_base(token[3]));
    ft_object_push(&v->objects, ft_object_new(object));
}

void    ft_parse_cone(t_mx *v, char **token){
    t_object    object;
    int         len;
    
    ft_bzero(&object, sizeof(t_object));
    object.type = CONE;
    len = ft_strsplit_len(token);
    if (len > 2 && token[1])
        object.pos = string_to_vect(token[1]);
    if (len > 3 && token[2])
        object.angle = ft_atof(token[2]);
    if (len > 4 && token[3])
        object.axis = string_to_vect(token[3]);
    if (len > 5 && token[4])
        object.color = vect_from_hexa(ft_special_atoi_base(token[4]));
    ft_object_push(&v->objects, ft_object_new(object));
}

void    ft_parse_cylinder(t_mx *v, char **token){
    t_object    object;
    int         len;
    
    ft_bzero(&object, sizeof(t_object));
    object.type = CYLINDER;
    len = ft_strsplit_len(token);
    if (len > 2 && token[1])
        object.pos = string_to_vect(token[1]);
    if (len > 3 && token[2])
        object.radius = ft_atof(token[2]);
   if (len > 4 && token[3])
        object.axis = string_to_vect(token[3]);
    if (len > 5 && token[4])
        object.color = vect_from_hexa(ft_special_atoi_base(token[4]));
    ft_object_push(&v->objects, ft_object_new(object));
}
