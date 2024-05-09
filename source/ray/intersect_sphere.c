/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:26:50 by groka             #+#    #+#             */
/*   Updated: 2024/05/09 16:27:03 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_intersection	intersect_sphere(t_sphere sphere, t_ray ray)
{
	t_intersection	xs;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	a = dot_product(ray.direction, ray.direction);
	b = 2 * dot_product(ray.direction,\
		subtract_point_point(ray.origin, sphere.coordinate));
	c = dot_product(subtract_point_point(ray.origin, sphere.coordinate),\
		subtract_point_point(ray.origin, sphere.coordinate)) - 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		xs.count = 0;
		return (xs);
	}
	xs.xs[0] = (-b - sqrt(discriminant)) / (2 * a);
	xs.xs[1] = (-b + sqrt(discriminant)) / (2 * a);
	if (xs.xs[0] == xs.xs[1])
		xs.count = 1;
	else
		xs.count = 2;
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
