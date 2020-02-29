void     ft_parse_sphere(char **ptr)
{
    t_sphere    sphere;
    char        **tab;

    tab = ft_strsplit(ptr[1], ' ');
    if (ft_str_is_numeric(tab[0]))
        sphere.center.x = ft_atof(tab[0]);
    else
        return ;
    if (ft_str_is_numeric(tab[1]))
        sphere.center.y = ft_atof(tab[1]);
    else
        return ;
    if (ft_str_is_numeric(tab[2]))
        sphere.center.z = ft_atof(tab[2]);
    else
        return ;
    if (ft_str_is_numeric(ptr[2]))
        sphere.radius = ft_atof(ptr[2]);
    else
        return ;
    printf("%f\n", sphere.radius);
    sphere.colour = ft_special_atoi_base(ptr[3]);
}

void     ft_parse_plane(char **ptr)
{
    t_plane     plane;
    char        **tab;

    tab = ft_strsplit(ptr[1], ' ');
    if (ft_str_is_numeric(tab[0]))
        plane.normal.x = ft_atof(tab[0]);
    else
        return ;
    if (ft_str_is_numeric(tab[1]))
        plane.normal.y = ft_atof(tab[1]);
    else
        return ;
    if (ft_str_is_numeric(tab[2]))
        plane.normal.z = ft_atof(tab[2]);
    else
        return ;
    if (ft_str_is_numeric(ptr[2]))
        plane.distance = ft_atof(ptr[2]);
    else
        return ;
    printf("%f\n", plane.distance);
    plane.colour = ft_special_atoi_base(ptr[3]);
}

void     ft_parse_cylinder(char **ptr)
{
    t_cylinder  cylinder;
    char        **c_tab;
    char        **d_tab;

    c_tab = ft_strsplit(ptr[1], ' ');
    if (ft_str_is_numeric(c_tab[0]))
        cylinder.center.x = ft_atof(c_tab[0]);
    else
        return ;
    if (ft_str_is_numeric(c_tab[1]))
        cylinder.center.y = ft_atof(c_tab[1]);
    else
        return ;
    if (ft_str_is_numeric(c_tab[2]))
        cylinder.center.z = ft_atof(c_tab[2]);
    else
        return ;
    d_tab = ft_strsplit(ptr[2], ' ');
    if (ft_str_is_numeric(d_tab[0]))
        cylinder.direction.x = ft_atof(d_tab[0]);
    else
        return ;
    if (ft_str_is_numeric(d_tab[1]))
        cylinder.direction.y = ft_atof(d_tab[1]);
    else
        return ;
    if (ft_str_is_numeric(d_tab[2]))
        cylinder.direction.z = ft_atof(d_tab[2]);
    else
        return ;
    if (ft_str_is_numeric(ptr[3]))
        cylinder.radius = ft_atof(ptr[3]);
    else
        return ;
    if (ft_str_is_numeric(ptr[4]))
        cylinder.height = ft_atof(ptr[4]);
    else
        return ;
    ft_putnbr(cylinder.height);
    cylinder.colour = ft_special_atoi_base(ptr[5]);
}

void     ft_parse_cone(char **ptr)
{
    t_cone      cone;
    char        **c_tab;
    char        **d_tab;

    c_tab = ft_strsplit(ptr[1], ' ');
    if (ft_str_is_numeric(c_tab[0]))
        cone.center.x = ft_atof(c_tab[0]);
    else
        return ;
    if (ft_str_is_numeric(c_tab[1]))
        cone.center.y = ft_atof(c_tab[1]);
    else
        return ;
    if (ft_str_is_numeric(c_tab[2]))
        cone.center.z = ft_atof(c_tab[2]);
    else
        return ;
    d_tab = ft_strsplit(ptr[2], ' ');
    if (ft_str_is_numeric(d_tab[0]))
        cone.direction.x = ft_atof(d_tab[0]);
    else
        return ;
    if (ft_str_is_numeric(d_tab[1]))
        cone.direction.y = ft_atof(d_tab[1]);
    else
        return ;
    if (ft_str_is_numeric(d_tab[2]))
        cone.direction.z = ft_atof(d_tab[2]);
    else
        return ;
    if (ft_str_is_numeric(ptr[3]))
        cone.radius = ft_atof(ptr[3]);
    else
        return ;
    if (ft_str_is_numeric(ptr[4]))
        cone.angle = ft_atof(ptr[4]);
    else
        return ;
    if (ft_str_is_numeric(ptr[5]))
        cone.height = ft_atof(ptr[5]);
    else
        return ;
    ft_putnbr(cone.height);
    cone.colour = ft_special_atoi_base(ptr[6]);
}

void     ft_parse_camera(char **ptr)
{
    t_cam       camera;
    char        **c_tab;
    char        **d_tab;

    c_tab = ft_strsplit(ptr[1], ' ');
    if (ft_str_is_numeric(c_tab[0]))
        camera.position.x = ft_atof(c_tab[0]);
    else
        return ;
    if (ft_str_is_numeric(c_tab[1]))
        camera.position.y = ft_atof(c_tab[1]);
    else
        return ;
    if (ft_str_is_numeric(c_tab[2]))
        camera.position.z = ft_atof(c_tab[2]);
    else
        return ;
    d_tab = ft_strsplit(ptr[2], ' ');
    if (ft_str_is_numeric(d_tab[0]))
        camera.direction.x = ft_atof(d_tab[0]);
    else
        return ;
    if (ft_str_is_numeric(d_tab[1]))
        camera.direction.y = ft_atof(d_tab[1]);
    else
        return ;
    if (ft_str_is_numeric(d_tab[2]))
        camera.direction.z = ft_atof(d_tab[2]);
    else
        return ;
}

void     ft_parse_light(char **ptr)
{
    t_light     light;
    char        **c_tab;

    c_tab = ft_strsplit(ptr[1], ' ');
    if (ft_str_is_numeric(c_tab[0]))
        light.position.x = ft_atof(c_tab[0]);
    else
        return ;
    if (ft_str_is_numeric(c_tab[1]))
        light.position.y = ft_atof(c_tab[1]);
    else
        return ;
    if (ft_str_is_numeric(c_tab[2]))
        light.position.z = ft_atof(c_tab[2]);
    else
        return ;
    light.colour = ft_special_atoi_base(ptr[2]);
}

void     ft_parse_ray(char **ptr)
{
    t_ray       ray;
    char        **c_tab;
    char        **d_tab;

    c_tab = ft_strsplit(ptr[1], ' ');
    if (ft_str_is_numeric(c_tab[0]))
        ray.source.x = ft_atof(c_tab[0]);
    else
        return ;
    if (ft_str_is_numeric(c_tab[1]))
        ray.source.y = ft_atof(c_tab[1]);
    else
        return ;
    if (ft_str_is_numeric(c_tab[2]))
        ray.source.z = ft_atof(c_tab[2]);
    else
        return ;
    d_tab = ft_strsplit(ptr[2], ' ');
    if (ft_str_is_numeric(d_tab[0]))
        ray.direction.x = ft_atof(d_tab[0]);
    else
        return ;
    if (ft_str_is_numeric(d_tab[1]))
        ray.direction.y = ft_atof(d_tab[1]);
    else
        return ;
    if (ft_str_is_numeric(d_tab[2]))
        ray.direction.z = ft_atof(d_tab[2]);
    else
        return ;
    printf("%f\n", ray.direction.y);
}

int     ft_check_lines(char *str)
{
    int     i;
    int     c;

    i = 0;
    c = 0;
    while (str[i])
    {
        if (str[i] == '\n')
        {
            c++;
            i++;
        }
        if (str[i] == ';')
        {
            if (c >= 2 && c <= 7)
            {
                i++;
                if (str[i] == '\n')
                    i++;
                c = 0;
                continue;
            }
            else
                return (0);
        }
        i++;
    }   
    return (1);
}