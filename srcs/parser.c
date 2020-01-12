/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:42:36 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/01/04 21:42:44 by ahkhilad         ###   ########.fr       */
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

    char    **s_center;
    double  s_radius;
    int     s_color;

    char    **p_normal;
    double  p_distance;
    int     p_color;

    char    **cy_center;
    char    **cy_direction;
    double  cy_radius;
    double  cy_height;
    int     cy_color;

    char    **co_center;
    char    **co_direction;
    double  co_radius;
    double  co_angle;
    double  co_height;
    int     co_color;

    char    **ca_position;
    char    **ca_direction;

    char    **l_position;
    int     l_color;

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
		return 0;
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
    while (b < x_size && all[b])
    {
        n = 0;
        while (n < j && all[b][n])
        {
            // ft_putendl(all[b][n]);   
            if (ft_strstr(all[b][n], sphere))
            {
                s_center = ft_strsplit(all[b][++n], ' ');
                s_radius = ft_atoi(all[b][++n]);
                s_color = ft_special_atoi_base(all[b][++n]);
                ft_putnbr(s_radius);
                // printf("\n");
                // ft_putnbr(s_color);
            }
            else if (ft_strstr(all[b][n], plane))
            {
                p_normal = ft_strsplit(all[b][++n], ' ');
                p_distance = ft_atoi(all[b][++n]);
                p_color = ft_special_atoi_base(all[b][++n]);
            }
            else if (ft_strstr(all[b][n], cylinder))
            {
                cy_center = ft_strsplit(all[b][++n], ' ');
                cy_direction = ft_strsplit(all[b][++n], ' ');
                cy_radius = ft_atoi(all[b][++n]);
                cy_height = ft_atoi(all[b][++n]);
                cy_color = ft_special_atoi_base(all[b][++n]);
            }
            else if (ft_strstr(all[b][n], cone))
            {
                co_center = ft_strsplit(all[b][++n], ' ');
                co_direction = ft_strsplit(all[b][++n], ' ');
                co_radius = ft_atoi(all[b][++n]);
                co_angle = ft_atoi(all[b][++n]);
                co_height = ft_atoi(all[b][++n]);
                co_color = ft_special_atoi_base(all[b][++n]);
                
            }
            else if (ft_strstr(all[b][n], camera))
            {
                ca_position = ft_strsplit(all[b][++n], ' ');
                ca_direction = ft_strsplit(all[b][++n], ' ');
            }
            else if (ft_strstr(all[b][n], light))
            {
                l_position = ft_strsplit(all[b][++n], ' ');
                l_color = ft_special_atoi_base(all[b][++n]);
            }
            else
                return (0);
            n++;
        }
        b++;
    }
	return (1);
}