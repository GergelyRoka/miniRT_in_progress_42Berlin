/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:07:36 by groka             #+#    #+#             */
/*   Updated: 2024/05/09 16:24:30 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "minirt.h"
# include "minirt.h"
# include "tuples.h"

typedef struct s_sphere		t_sphere;

typedef struct s_ray
{
	t_point		origin;
	t_vector	direction;
}				t_ray;

typedef struct s_intersection
{
	int			count;
	double		xs[2];
}				t_intersection;

t_ray	do_ray(t_point origin, t_vector direction);
t_point	position(t_ray ray, float t);

t_intersection	intersect_sphere(t_sphere sphere, t_ray ray);


#endif
