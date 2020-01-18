/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_alg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhilad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:08:06 by ahkhilad          #+#    #+#             */
/*   Updated: 2020/01/18 20:10:01 by ahkhilad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEAR_ALG_H
# define LINEAR_ALG_H

# include <math.h>

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

double			ft_magnitude(t_vec v);
t_vec			ft_normalize(t_vec v);
t_vec			ft_negative(t_vec v);
double			ft_dotproduct(t_vec a, t_vec b);
t_vec			ft_crossproduct(t_vec a, t_vec b);
t_vec			ft_vectoradd(t_vec a, t_vec b);
t_vec			ft_vectormulti(double scalar);

#endif
