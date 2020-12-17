/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magnitude.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <ahkhilad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:52:30 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/12/17 17:58:14 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_alg.h"

float		ft_magnitude(t_vec v)
{
	t_vec	c;

	c.x = v.x * v.x;
	c.y = v.y * v.y;
	c.z = v.z * v.z;
	return (sqrtf(c.x + c.y + c.z));
}
