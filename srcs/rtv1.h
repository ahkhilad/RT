/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 00:31:07 by ahkhilad          #+#    #+#             */
/*   Updated: 2019/11/29 00:31:12 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# define BUFF_SIZE 100000

# define WIN_W 1280
# define WIN_H 720

# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <time.h>
# include "../libft/libft.h"
# include "../linearlib/linear_alg.h"

typedef struct	s_base
{
	int			i;
	int			p;
	int			rt;
	int			n;
	int			somme;
}				t_base;

typedef struct          s_cam
{
    t_vec               position;
    t_vec               direction;
    // t_vec               cam_down;
    // t_vec               cam_right;
}                       t_cam;

typedef struct          s_ray
{
    t_vec               source;
    t_vec               direction;
}                       t_ray;


typedef enum e_type{
    NONE, SPHERE = 10, PLANE, CONE, CYLINDER
}           t_type;


typedef struct          s_object
{
    t_type              type;
    t_vec               pos;
    t_vec               trans;
    t_vec               rot;
    t_vec               color;

    float               radius;
    float               angle;
    t_vec               normal;
    t_vec               axis;

    struct s_object     *next;
}                       t_object;

typedef struct          s_light
{
    t_vec               pos;
    t_vec               color;

    float               intensity;
    struct s_light     *next;
}                       t_light;

typedef struct          s_mx
{
    void                *mptr;
    void                *wptr;
    void                *iptr;
    int                 *rt;
    int                 bpp;
    int                 size;
    int                 end;

    t_object            *objects;
    t_light             *lights;
    t_cam               cam;
}                       t_mx;

int     ft_open(char *str, t_mx *v);
void	ft_usage(void);
void	ft_destroy(t_mx *v);
int		key_press(int keycode, void *p);
int		red_button(void *p);
void    setup(t_mx *v);
void    update(t_mx *mx);
void    display(t_mx *mx);
void    run(t_mx *mx);

float   clamp(float value, float min, float max);
t_vec   clamp_vect(t_vec v);
int     rgb_to_int(t_vec v);

int 	shadow_cast(t_object *lst, t_ray *ray, float *tmin);

t_object        ft_sphere(t_vec pos, float radius, t_vec color);
t_object        ft_plane(t_vec pos, t_vec normal, t_vec color);
t_object        ft_cone(t_vec pos, t_vec axis, float angle, t_vec color);
t_object        ft_cylinder(t_vec pos, t_vec axis, float radius, t_vec color);

t_object        *ft_object_new(t_object o);
void            ft_object_push(t_object **lst, t_object *nw);
void            ft_object_clear(t_object **lst);

t_light        *ft_light_new(t_vec pos, t_vec color, float intensity);
void            ft_light_push(t_light **lst, t_light *nw);
void            ft_light_clear(t_light **lst);

// void        ft_object_push_front(t_object **lst, t_object *new){

//     if (lst == NULL || new == NULL)
//     return;
//     new->next = *lst;
//     *lst = new;
// }

void        ft_strsplit_free(char ***tab);
int         ft_strsplit_len(char **tab);
int         ft_strsplit_print(char **tab);
int		    ft_special_atoi_base(char *str);
t_vec       vect_from_hexa(int rgb);
t_vec       string_to_vect(char *str);

void        ft_parse_sphere(t_mx *v, char **token);
void        ft_parse_plane(t_mx *v, char **token);
void        ft_parse_cone(t_mx *v, char **token);
void        ft_parse_cylinder(t_mx *v, char **token);
void        ft_parse_light(t_mx *v, char **token);

# endif