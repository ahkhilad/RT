/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:42:36 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/10/21 11:32:30 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    ft_token_handle(t_mx *v, char **token)
{
    if (token[0] && !ft_strcmp(token[0], "sphere"))
    {
        ft_parse_sphere(v, token);
    }
    else if (token[0] && !ft_strcmp(token[0], "plane"))
    {
        ft_parse_plane(v, token);
    }
    else if (token[0] && !ft_strcmp(token[0], "cone"))
    {
        ft_parse_cone(v, token);
    }
    else if (token[0] && !ft_strcmp(token[0], "cylinder"))
    {
        ft_parse_cylinder(v, token);
    }
    else if (token[0] && !ft_strcmp(token[0], "light"))
    {
        ft_parse_light(v, token);
    }
    else if (token[0] && !ft_strcmp(token[0], "camera"))
    {
        ft_parse_camera(v, token);  
    }
}

void    ft_blocks(t_mx *v, char *line)
{
    char    **blocks;
    char    **tokens;
    int     i;

    if (ft_split_check(line) == 0)
        return ;
    if (!(blocks = ft_strsplit(line, ';')))
        return ;
    i = -1;
    tokens = NULL;
    while (blocks[++i]){
        if (!(tokens = ft_strsplit(blocks[i], '\n')))
        {
            ft_strsplit_free(&blocks);
            return ;
        }
        ft_token_handle(v, tokens);
        ft_strsplit_free(&tokens);  
    }
    ft_strsplit_free(&blocks);
}

int		ft_open(char *str, t_mx *v)
{
	int		fd;
	int		rd;
	char	*tmp;
	char	*line;
	char	buff[BUFF_SIZE + 1];

	if (!(fd = open(str, O_RDONLY)) || (fd < 1  || fd > 4096))
    {
        close(fd);
        return (0);
    }
	line = ft_strnew(0);
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		tmp = line;
		line = ft_strjoin(line, buff);
		free(tmp);
	}
    //ft_putendl(line);
    ft_blocks(v, line);
    free(line);
    close(fd);
    if (!v->objects)
        return (0);
 	return (1);
}