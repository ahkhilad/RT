#include "rtv1.h"

char  *strcmptable(const char *str, char **tab)
{
    while(*tab && !ft_strequ(str,*tab))
    {
        tab++;
    }
    return (*tab);
}

void ft_strsplit_free(char ***tab)
{
    int     i;

    i = -1;
    while ((*tab)[i++])
        free((*tab)[i]);
    free((*tab));
}

int      ft_strsplit_len(char **tab)
{
    int     i;

    i = -1;
    while (tab[++i])
        ;
    return (i);
}

void      ft_strsplit_print(char **tab)
{
    int     i;

    i = -1;
    while (tab[++i])
        ft_putendl(tab[i]);
}

int     ft_check_empty_lines(char *line)
{
    int     i;

    if (line[0] == '\n')
        return (0);
    i = -1;
    while (line[++i])
    {
        if (line[i] && line[i] == '\n')
        {
            if (!line[i + 1] || line[i + 1] == '\n')
                return (0);
        }
    }
    return (1);
}

int     ft_split_check(char *line)
{
    char    **tab;
    int     i;
    
    //ft_putstr(line);
    //ft_putnbr(ft_check_empty_lines(line));
    //ft_putchar('\n');
    //exit (0);
    if (!ft_check_empty_lines(line))
        return (0);
    tab = ft_strsplit(line, '\n');
    if (!strcmptable(tab[0],(char *[]){ELEMENTS, NULL}))
    {
        return (0);
    } 
    i = -1;
    while (tab[++i])
    {
        if (tab[i] && ft_strequ(tab[i], ";"))
        {
            if (!tab[i+1] || !strcmptable(tab[i + 1],(char *[]){ELEMENTS, NULL}))
            {
                return (0);
            }   
            else
                continue ;
        }
    }
    return (1);
}

static void	converting_base(char *str, t_base *v)
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

t_vec   vect_from_hexa(int rgb)
{
    t_vec v;

    int red = (rgb >> 16) & 0xFF;
    int green = (rgb >> 8) & 0xFF;
    int blue = rgb & 0xFF;

    v.x = (float)red / 255.0f;
    v.y = (float)green / 255.0f;
    v.z = (float)blue / 255.0f;
    return (v);
}

t_vec   string_to_vect(char *str)
{
    t_vec   v;
    char    **split;

    ft_bzero(&v, sizeof(t_vec));
    if ((split = ft_strsplit(str, ' ')) && ft_strsplit_len(split) == 3)
    {
        v.x = ft_atof(split[0]);
        v.y = ft_atof(split[1]);
        v.z = ft_atof(split[2]);
        ft_strsplit_free(&split);
    }
    return v;
}