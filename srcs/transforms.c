#include "rtv1.h"

t_vec   translation(t_vec a, t_vec b)
{
    return (ft_vectoradd(a, b));
}

static double  deg_to_rad(double angle)
{
    return ((angle * PI) / 180);
}

t_vec   x_rotation(t_vec v, double theta)
{
    theta = deg_to_rad(theta);
    v.y = v.y * cos(theta) + v.z * -sin(theta);
    v.z = v.y * sin(theta) + v.z * cos(theta);
    return (v);
}

t_vec   y_rotation(t_vec v, double theta)
{
    theta = deg_to_rad(theta);
    v.x = v.x * cos(theta) + v.z * sin(theta);
    v.z = v.x * -sin(theta) + v.z * cos(theta);
    return (v);
}

t_vec   z_rotation(t_vec v, double theta)
{
    theta = deg_to_rad(theta);
    v.x = v.x * cos(theta) + v.y * -sin(theta);
    v.y = v.x * sin(theta) + v.y * cos(theta);
    return (v);
}