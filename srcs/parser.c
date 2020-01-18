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
	char	*tmp;
	char	*line;
	char	**blocks;
    char    ***all;
	char	buff[BUFF_SIZE + 1];
    int     b;
    int     n;
    int     vec1;
    int     vec2;

    t_sphere    s;
    char        **s_center;
    int         s_color;

    t_plane     p;
    char        **p_normal;
    int         p_color;

    t_cylinder  cy;
    char        **cy_center;
    char        **cy_direction;
    int         cy_color;

    t_cone      co;
    char        **co_center;
    char        **co_direction;
    int         co_color;

    t_cam       ca;
    char        **ca_position;
    char        **ca_direction;

    t_light     li;
    char        **l_position;
    int         l_color;

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
        j = k;
        i++;
    }
    sphere = "sphere";
    plane = "plane";
    cylinder = "cylinder";
    cone = "cone";
    camera = "camera";
    light = "light";
    b = 0;
    i = 0;
    while (b < x_size && all[b])
    {
        n = 0;
        while (n < j && all[b][n])
        {
            // ft_putendl(all[b][n]);   
            if (ft_strstr(all[b][n], sphere))
            {
                if (ft_strcmp(all[b][n], sphere) == 0)
                {
                    s_center = ft_strsplit(all[b][++n], ' ');
                    vec1 = 0;
                    while (s_center[vec1])
                        vec1++;
                    if (vec1 > 3)
                        return (0);
                    if (ft_str_is_numeric(s_center[0]))
                        s.center.x = ft_atof(s_center[0]);
                    else
                        return (0);
                    if (ft_str_is_numeric(s_center[1]))
                        s.center.y = ft_atof(s_center[1]);
                    else
                        return (0);
                    if (ft_str_is_numeric(s_center[2]))
                        s.center.z = ft_atof(s_center[2]);
                    else
                        return (0);
                    ++n;
                    if (ft_str_is_numeric(all[b][n]))
                        s.radius = ft_atof(all[b][n]);
                    else
                        return (0);
                    s_color = ft_special_atoi_base(all[b][++n]);
                }
                else
                    return (0);
            }
            else if (ft_strstr(all[b][n], plane))
            {
                if (ft_strcmp(all[b][n], plane) == 0)
                {
                    p_normal = ft_strsplit(all[b][++n], ' ');
                    vec1 = 0;
                    while (p_normal[vec1])
                        vec1++;
                    if (vec1 > 3)
                        return (0);
                    if (ft_str_is_numeric(p_normal[0]))
                        p.normal.x = ft_atof(p_normal[0]);
                    else
                        return (0);
                    if (ft_str_is_numeric(p_normal[1]))
                        p.normal.y = ft_atof(p_normal[1]);
                    else
                        return (0);
                    if (ft_str_is_numeric(p_normal[2]))
                        p.normal.z = ft_atof(p_normal[2]);
                    else
                        return (0);
                    ++n;
                    if (ft_str_is_numeric(all[b][n]))
                        p.distance = ft_atof(all[b][n]);
                    else
                        return (0);
                    p_color = ft_special_atoi_base(all[b][++n]);
                }
                else
                    return (0);
            }
            else if (ft_strstr(all[b][n], cylinder))
            {
                if (ft_strcmp(all[b][n], cylinder) == 0)
                {
                    cy_center = ft_strsplit(all[b][++n], ' ');
                    vec1 = 0;
                    while (cy_center[vec1])
                        vec1++;
                    if (vec1 > 3)
                        return (0);
                    if (ft_str_is_numeric(cy_center[0]))
                        cy.center.x = ft_atof(cy_center[0]);
                    else
                        return (0);
                    if (ft_str_is_numeric(cy_center[1]))
                        cy.center.y = ft_atof(cy_center[1]);
                    else
                        return (0);
                    if (ft_str_is_numeric(cy_center[2]))
                        cy.center.z = ft_atof(cy_center[2]);
                    else
                        return (0);
                    cy_direction = ft_strsplit(all[b][++n], ' ');
                    vec2 = 0;
                    while (cy_direction[vec2])
                        vec2++;
                    if (vec2 > 3)
                        return (0);
                    if (ft_str_is_numeric(cy_direction[0]))
                        cy.direction.x = ft_atof(cy_direction[0]);
                    else
                        return (0);
                    if (ft_str_is_numeric(cy_direction[1]))
                        cy.direction.y = ft_atof(cy_direction[1]);
                    else
                        return (0);
                    if (ft_str_is_numeric(cy_direction[2]))
                        cy.direction.z = ft_atof(cy_direction[2]);
                    else
                        return (0);
                    ++n;
                    if (ft_str_is_numeric(all[b][n]))
                        cy.radius = ft_atof(all[b][n]);
                    else
                        return (0);
                    ++n;
                    if (ft_str_is_numeric(all[b][n]))
                        cy.height = ft_atof(all[b][n]);
                    else
                        return (0);
                    cy_color = ft_special_atoi_base(all[b][++n]);
                }
                else
                    return (0);
            }
            else if (ft_strstr(all[b][n], cone))
            {
                if (ft_strcmp(all[b][n], cone) == 0)
                {
                    co_center = ft_strsplit(all[b][++n], ' ');
                    vec1 = 0;
                    while (co_center[vec1])
                        vec1++;
                    if (vec1 > 3)
                        return (0);
                    if (ft_str_is_numeric(co_center[0]))
                        co.center.x = ft_atof(co_center[0]);
                    else
                        return (0);
                    if (ft_str_is_numeric(co_center[1]))
                        co.center.y = ft_atof(co_center[1]);
                    else
                        return (0);
                    if (ft_str_is_numeric(co_center[2]))
                        co.center.z = ft_atof(co_center[2]);
                    else
                        return (0);
                    co_direction = ft_strsplit(all[b][++n], ' ');
                    vec2 = 0;
                    while (co_direction[vec2])
                        vec2++;
                    if (vec2 > 3)
                        return (0);
                    if (ft_str_is_numeric(co_direction[0]))
                        co.direction.x = ft_atof(co_direction[0]);
                    else
                        return (0);
                    if (ft_str_is_numeric(co_direction[1]))
                        co.direction.y = ft_atof(co_direction[1]);
                    else
                        return (0);
                    if (ft_str_is_numeric(co_direction[2]))
                        co.direction.z = ft_atof(co_direction[2]);
                    else
                        return (0);
                    ++n;
                    if (ft_str_is_numeric(all[b][n]))
                        co.radius = ft_atof(all[b][n]);
                    else
                        return (0);
                    ++n;
                    if (ft_str_is_numeric(all[b][n]))
                        co.angle = ft_atof(all[b][n]);
                    else
                        return (0);
                    ++n;
                    if (ft_str_is_numeric(all[b][n]))
                        co.height = ft_atof(all[b][n]);
                    else
                        return (0);
                    co_color = ft_special_atoi_base(all[b][++n]);
                    // printf("%f", co.center.y);
                    // printf("\n");
                    // printf("%f", co.direction.y);
                    // printf("\n");
                    // ft_putnbr(co_color);
                }
                else
                    return (0);
            }
            else if (ft_strstr(all[b][n], camera))
            {
                if (ft_strcmp(all[b][n], camera) == 0)
                {
                    ca_position = ft_strsplit(all[b][++n], ' ');
                    vec1 = 0;
                    while (ca_position[vec1])
                        vec1++;
                    if (vec1 > 3)
                        return (0);
                    if (ft_str_is_numeric(ca_position[0]))
                        ca.position.x = ft_atof(ca_position[0]);
                    else
                        return (0);
                    if (ft_str_is_numeric(ca_position[1]))
                        ca.position.y = ft_atof(ca_position[1]);
                    else
                        return (0);
                    if (ft_str_is_numeric(ca_position[2]))
                        ca.position.z = ft_atof(ca_position[2]);
                    else
                        return (0);
                    ca_direction = ft_strsplit(all[b][++n], ' ');
                    vec2 = 0;
                    while (ca_direction[vec2])
                        vec2++;
                    if (vec2 > 3)
                        return (0);
                    if (ft_str_is_numeric(ca_direction[0]))
                        ca.direction.x = ft_atof(ca_direction[0]);
                    else
                        return (0);
                    if (ft_str_is_numeric(ca_direction[1]))
                        ca.direction.y = ft_atof(ca_direction[1]);
                    else
                        return (0);
                    if (ft_str_is_numeric(ca_direction[2]))
                        ca.direction.z = ft_atof(ca_direction[2]);
                    else
                        return (0);
                }
                else
                    return (0);
            }
            else if (ft_strstr(all[b][n], light))
            {
                if (ft_strcmp(all[b][n], light) == 0)
                {
                    l_position = ft_strsplit(all[b][++n], ' ');
                    vec1 = 0;
                    while (l_position[vec1])
                        vec1++;
                    if (vec1 > 3)
                        return (0);
                    if (ft_str_is_numeric(l_position[0]))
                        li.position.x = ft_atof(l_position[0]);
                    else
                        return (0);
                    if (ft_str_is_numeric(l_position[1]))
                        li.position.y = ft_atof(l_position[1]);
                    else
                        return (0);
                    if (ft_str_is_numeric(l_position[2]))
                        li.position.z = ft_atof(l_position[2]);
                    else
                        return (0);
                    l_color = ft_special_atoi_base(all[b][++n]);
                }
                else
                    return (0);
            }
            else
                return (0);
            n++;
        }
        b++;
    }
	return (1);
}
