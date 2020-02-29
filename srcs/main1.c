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

int sphere_intersect(t_object *sphere, t_ray *ray){
	t_vec x;
	float a, b, c, delta;
	
	x = ft_vectorsub(ray->source, sphere->pos);
	a = ft_dotproduct(ray->direction, ray->direction);
	b = 2.0 * ft_dotproduct(ray->direction, x);
	c = ft_dotproduct(x, x) - sphere->radius * sphere->radius;
	delta = b * b - 4.0 * a * c;
	if (delta < 0){
		return (0);
	}else{
		return (1);
	}
}

int		raycast(t_object *lst, t_ray *ray){
	t_object	*p;

	p = lst;
	while (p){
		if (p->type == SPHERE){
			if (sphere_intersect(p, ray))
				return (1);
		}
		p = p->next;
	}
	return (0);
}

void update(t_mx *mx){

	t_ray ray;

	
	for(int y = 0; y < WIN_H; y++){
		for(int x = 0; x < WIN_W; x++){
			 ray = camera_ray(x - WIN_W / 2, y - WIN_H / 2);
			if (raycast(mx->objects, &ray)){
				mx->rt[y * WIN_W + x] = 0xFFFF00;
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
                ft_putstr("error! please try a valid map.\n");
				exit(0);
            }
            else{
				run(&v);
			}
        }
    }
    else
        ft_usage();
    return (0);
}
