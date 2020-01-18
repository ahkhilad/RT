/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectormulti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:53:24 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/01/18 20:07:55 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_alg.h"

t_vec		ft_vectormulti(double scalar)
{
	t_vec	c;

	c.x *= scalar;
	c.y *= scalar;
	c.z *= scalar;
	return (c);
}
