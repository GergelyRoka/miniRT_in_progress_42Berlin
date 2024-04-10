/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:12:44 by groka             #+#    #+#             */
/*   Updated: 2024/04/10 16:41:31 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ray.h"

t_point	position(t_ray ray, float t)
{
	return \
		(add_tuple_tuple(ray.origin, multiply_tuple_double(ray.direction, t)));
}

t_intersection	intersect(int s, t_ray ray)
{
	t_intersection	xs;

	return (xs);
}

/*
	# the vector from the sphere's center, to the ray origin
	# remember: the sphere is centered at the world origin
	sphere_to_ray ← ray.origin - point(0, 0, 0)
	a ← dot(ray.direction, ray.direction)
	b ← 2 * dot(ray.direction, sphere_to_ray)
	c ← dot(sphere_to_ray, sphere_to_ray) - 1
	discriminant ← b² - 4 * a * c
*/
double	discriminant(double a, double b, double c)
{
	return (b * b - 4 * a * c);
}
