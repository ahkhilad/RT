#include "rtv1.h"

void    ft_parse_camera(t_mx *v, char **token)
{

    t_vec       pos;
    t_vec       at;
    float       vfov;
    int         len;
    
    len = ft_strsplit_len(token);
    if (len > 1 && token[1])
        pos = string_to_vect(token[1]);
    if (len > 2 && token[2])
        at = string_to_vect(token[2]);  
    if (len > 3 && token[3])
        vfov = ft_atof(token[3]);
    v->cam = ft_camera_create(pos, at, (t_vec){0, 1, 0}, vfov);
}