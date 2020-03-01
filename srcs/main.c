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

static int		ft_min_ray(float t1, float t2, float *t)
{
	if (((t1 < t2 || t2 < 0.001) && t1 > 0.1) && (t1 < *t))
	{
		*t = t1;
		return (1);
	}
	else if (((t2 < t1 || t1 < 0.001) && t2 > 0.1) && (t2 < *t))
	{
		*t = t2;
		return (1);
	}
	else
		return (0);
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
	return (ft_min_ray(t1, t2, tmin));
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

void	ft_compute_normals(t_hit *hit, t_ray *ray)
{
	(void)ray;
	if (hit->object->type == SPHERE){
		hit->n = ft_normalize(ft_vectorsub(hit->p, hit->object->pos));
	}
	else if (hit->object->type == PLANE){
		hit->n = hit->object->normal;
	}
}

t_vec	ft_light_calc(t_light *light, t_vec light_dir, t_hit *hit, t_ray *ray)
{
	float 		lambert;
	t_vec		color;
		
	color = (t_vec){0.0f, 0.0f, 0.0f};
	lambert = fmax(0.0f, ft_dotproduct(light_dir, hit->n));
	color = ft_vectoradd(color, ft_vectormulti(hit->object->color, lambert));
	// add specular
//	printf("Intensity : %.2f\n", light->intensity);
	color.x = color.x * light->color.x * light->intensity;
	color.y = color.y * light->color.y * light->intensity;
	color.z = color.z * light->color.z * light->intensity;
	return (color);
}

int 	ft_shade_object(t_hit *hit, t_light *lights, t_object *lst, t_ray *ray){
	t_light 	*light;
	t_vec		color;
	t_vec		light_dir;
	t_ray		shadow_ray;

	float t;

	color = (t_vec){0.0f, 0.0f, 0.0f};
	shadow_ray.source = hit->p;
	light = lights;
	while (light){
		light_dir = ft_normalize(ft_vectorsub(light->pos, hit->p));
		shadow_ray.direction = light_dir;
		t = ft_magnitude(ft_vectorsub(light->pos, hit->p));
		if (!shadow_cast(lst, &shadow_ray, &t))
		 color = ft_vectoradd(color, ft_light_calc(light, light_dir, hit, ray));
		light = light->next;
	}
	return (rgb_to_int(clamp_vect(color)));
}

int	raycast(t_object *lst, t_ray *ray, t_hit *hit){
	t_object	*p;
	float		t;

	t = INFINITY;
	hit->object = NULL;
	p = lst;
	while (p){
		if (p->type == SPHERE){
			if (sphere_intersect(p, ray, &t))
			{
				if (hit->t > t){
					hit->t = t;
					hit->object = p;
				}
			}
		}
		p = p->next;
	}
	if (hit->object == NULL)
		return (0);
	hit->p = ft_vectoradd(ray->source, ft_vectormulti(ray->direction, t));
	ft_compute_normals(hit, ray);
	return (1);
}

int 	shadow_cast(t_object *lst, t_ray *ray, float *tmin){
	t_object	*p;
	float		t;

	t = INFINITY;
	p = lst;
	while (p){
		if (p->type == SPHERE){
			if (sphere_intersect(p, ray, &t))
			 {
				 if (t < *tmin)
				 	return (1);
			 }
		}
		p = p->next;
	}
	return 0;
}

void update(t_mx *mx){

	t_ray 	ray;
	t_hit	hit;

	for(int y = 0; y < WIN_H; y++){
		for(int x = 0; x < WIN_W; x++){
			 ray = camera_ray(x - WIN_W / 2, y - WIN_H / 2);
			 hit.t = INFINITY;
			if (raycast(mx->objects, &ray, &hit)){
				mx->rt[(WIN_H - 1 - y) *  WIN_W + x] = ft_shade_object(&hit, mx->lights, mx->objects, &ray);
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