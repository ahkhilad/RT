/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:42:36 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/01/18 20:19:29 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	converting_base(char *str, t_base *v)
{
	if (str[v->i + 1] >= 48 && str[v->i + 1] <= 57)
		v->somme = v->somme + (str[v->i + 1] - 48) * pow(16, v->n);
	else if (str[v->i + 1] >= 97 && str[v->i + 1] <= 102)
		v->somme = v->somme + (str[v->i + 1] - 87) * pow(16, v->n);
	else if (str[v->i + 1] >= 65 && str[v->i + 1] <= 70)
		v->somme = v->somme + (str[v->i + 1] - 55) * pow(16, v->n);
}

int		ft_special_atoi_base(char *str)
{
	t_base		v;

	v.i = 0;
	v.n = 0;
	v.somme = 0;
	v.p = 0;
	v.rt = 0;
	while (str[v.i] != 'x' && str[v.i])
		v.i++;
	if (str[v.i] != '\0')
		v.rt = ft_strlen(str);
	while (str[v.rt - 1] != 'x' && str[v.rt - 1])
	{
		v.p++;
		v.rt--;
	}
	v.n = v.p - 1;
	while (str[v.i + 1] != '\0' && v.n >= 0)
	{
		converting_base(str, &v);
		v.i++;
		v.n--;
	}
	return (v.somme);
}

// int     ft_check_semicolon(char *str)
// {
//     int     i;
//     int     c1;
//     int     c2;

//     i = 0;
//     c1 = 0;
//     c2 = 0;
//     while (str[i])
//     {
//         if (str[i] == ';')
//         {
//             c1++;
//             i++;
//         }
//         while (str[i] != ';' && str[i])
//         {
//             i++;
//             if (str[i + 1] == ';')
//                 c2++;
//         }
//     }
//     ft_putnbr(c2);
//     printf("\n");
//     ft_putnbr(c1);
//     if (c2 != c1)
//         return (0);
//     return (1);
// }

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
            if (c >= 3 && c <= 7)
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

int		ft_open(char *str, t_mx *v)
{
	int		fd;
	int		i;
    int     j;
	int		k;
	int		rd;
	int		x_size;
	int		y_size;
    char    *sphere;
    char    *plane;
    char    *cone;
    char    *cylinder;
    char    *light;
    char    *camera;
    char    *ray;
	char	*tmp;
	char	*line;
	char	**blocks;
    char    ***all;
	char	buff[BUFF_SIZE + 1];

	fd = open(str, O_RDONLY);
	if (read(fd, buff, 0) < 0)
		return (0);
	line = ft_strnew(0);
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		tmp = line;
		line = ft_strjoin(line, buff);
		free(tmp);
	}
	if (ft_strlen(line) == 0)
		return (0);
    if (!(ft_check_lines(line)))
        return (0);
	tmp = line;
	blocks = ft_strsplit(line, ';');
	free(tmp);
	x_size = 0;
	while (blocks[x_size] != NULL)
		x_size++;
    i = 0;
    all = (char ***)malloc(sizeof(char**) * x_size);
    while (i < x_size && blocks[i])
    {
        k = 0;
        while (blocks[i][k] && blocks[i][k] != ';')
        {
            all[i] = ft_strsplit(blocks[i], '\n');
            k++;
        }
        i++;
    }
    sphere = "sphere";
    plane = "plane";
    cylinder = "cylinder";
    cone = "cone";
    camera = "camera";
    light = "light";
    ray = "ray";
    i = 0;
    while(all[i])
    {
        if (ft_strequ(all[i][0], sphere))
        {
            ft_parse_sphere(all[i]);
            printf("wlahta sphere\n");
        }
        if (ft_strequ(all[i][0], plane))
        {
            ft_parse_plane(all[i]);
            printf("wlahta plane\n");
        }
        if (ft_strequ(all[i][0], cylinder))
        {
            ft_parse_cylinder(all[i]);
            printf("wlahta cylinder\n");
        }
        if (ft_strequ(all[i][0], cone))
        {
            ft_parse_cone(all[i]);
            printf("wlahta cone\n");
        }
        if (ft_strequ(all[i][0], camera))
        {
            ft_parse_camera(all[i]);
            printf("wlahta camera\n");
        }
        if (ft_strequ(all[i][0], light))
        {
            ft_parse_light(all[i]);
            printf("wlahta light\n");
        }
        if (ft_strequ(all[i][0], ray))
        {
            ft_parse_ray(all[i]);
            printf("wlahta ray\n");
        }
        i++;
    }  
 	return (1);
}
