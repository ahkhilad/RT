/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:42:11 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/01/04 21:42:23 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define RAY_Z (2000)

t_ray camera_ray(int x, int y){
	t_ray ray;

	ray.source = (t_vec){x, y, RAY_Z};
	ray.direction = (t_vec){0, 0, -1};
	return (ray);
}

int sphere_intersect(t_object *sphere, t_ray *ray, float *tmin){
	t_vec x;
	float a, b, c, delta;
	float t1, t2;
	float t;

t = INFINITY;
	x = ft_vectorsub(ray->source, sphere->pos);
	a = ft_dotproduct(ray->direction, ray->direction);
	b = 2.0 * ft_dotproduct(ray->direction, x);
	c = ft_dotproduct(x, x) - sphere->radius * sphere->radius;
	delta = b * b - 4.0 * a * c;
	if (delta < 0){
		return (0);
	}
	delta = sqrt(delta);
	t1 = (-b + delta) / (2 * a);
	t2 = (-b - delta) / (2 * a);

	if (t1 < 1e-6 && t2 < 1e-6){
		*tmin = INFINITY;
		return (0);
	}
	if (t1 > t2){
		float tmp = t1;
		t1 = t2;
		t2 = tmp;
	}
	if (t1 > 1e-6f){
		t = t1;
	}else if (t2 > 1e-6f){
		t = t2;
	}
	*tmin = t;
	return (1);
}

int 	ft_shade_object(t_ray *ray, float t, t_light *lights, t_object *object){
	t_light 	*light;
	t_vec		color;
	t_vec		p;
	t_vec		n;
	t_vec		light_dir;
	float 		lambert;

	color = (t_vec){0.0f, 0.0f, 0.0f};
	p = ft_vectoradd(ray->source, ft_vectormulti(ray->direction, t));
	n = ft_normalize(ft_vectorsub(p, object->pos));
	light = lights;
	while (light){
		light_dir = ft_normalize(ft_vectorsub(light->pos, p));
		lambert = fmax(0.0f, ft_dotproduct(light_dir, n));
		color = ft_vectoradd(color, ft_vectormulti(object->color, lambert));
		light = light->next;
	}
	return (rgb_to_int(clamp_vect(color)));
}

t_object	*raycast(t_object *lst, t_ray *ray, float *tmin){
	t_object	*p;
	float		t;
	t_object	*hit;

	t = INFINITY;
	hit = NULL;
	p = lst;
	while (p){
		if (p->type == SPHERE){
			if (sphere_intersect(p, ray, &t))
			{
				if (*tmin > t){
					*tmin = t;
					hit = p;
				}
			}
		}
		p = p->next;
	}
	return (hit);
}

int 	shadow_cast(t_object *lst, t_ray *ray, float *tmin){
	t_object	*p;
	float		t;

	(void)tmin;
	t = INFINITY;
	p = lst;
	while (p){
		if (p->type == SPHERE){
			if (sphere_intersect(p, ray, &t))
			 return (1);
		}
		p = p->next;
	}
	return 0;
}


void update(t_mx *mx){

	t_ray 	ray;
	t_object *object;
	float	tmin;

	for(int y = 0; y < WIN_H; y++){
		for(int x = 0; x < WIN_W; x++){
			 ray = camera_ray(x - WIN_W / 2, y - WIN_H / 2);
			 tmin = INFINITY;
			if ((object = raycast(mx->objects, &ray, &tmin))){
				mx->rt[(WIN_H - 1 - y) *  WIN_W + x] = ft_shade_object(&ray, tmin, mx->lights, object);
			}
		}
	}
}


int     main(int ac, char **av)
{
    t_mx    v;

	//ft_bzero(&v, sizeof(t_object));
    if (ac == 2)
    {
        if (av[1])
        {
            if (!ft_open(av[1], &v)){
                ft_putstr("error! please try a valid configuration file.\n");
				exit(0);
            }
            else
			{
				run(&v);
			}
        }
    }
    else
        ft_usage();
    return (0);
}