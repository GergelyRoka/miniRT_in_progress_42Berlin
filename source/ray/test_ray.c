/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:22:19 by groka             #+#    #+#             */
/*   Updated: 2024/05/09 15:34:23 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include "../../include/ray.h"
#include <stdio.h>

static void	print_tuple(t_tuple a)
{
	printf("%f %f %f %f\n", a.x, a.y, a.z, a.w);
}

/*
	Scenario: Computing a point from a distance
	Given r ← ray(point(2, 3, 4), vector(1, 0, 0))
	Then position(r, 0) = point(2, 3, 4)
	And position(r, 1) = point(3, 3, 4)
	And position(r, -1) = point(1, 3, 4)
	And position(r, 2.5) = point(4.5, 3, 4)
	To find the position, you multiply the ray’s direction by t to find the total
	distance traveled, and then add that to the ray’s origin. In pseudocode, it
	looks like this:
	function position(ray, t)
	return ray.origin + ray.direction * t
	end function
*/
int	main(void)
{
	t_ray	ray;
	ray.origin = do_point(2, 3, 4);
	ray.direction = do_vector(1, 0, 0);

	printf("test\n");
	t_ray	ray2;
	ray2 = do_ray(do_point(2, 3, 4), do_vector(1, 0, 0));

	print_tuple(position(ray2, 0.0));
	print_tuple(position(ray2, 1.0));
	print_tuple(position(ray2, -1.0));
	print_tuple(position(ray2, 2.5));

	{
		t_sphere	sphere;
		t_ray		ray;
		t_intersection	xs;

		sphere.coordinate = do_point(0, 0, 0);
		sphere.diameter = 1.0;
		ray.origin = do_point(0, 0, -5);
		ray.direction = do_vector(0, 0, 1);
		xs = intersect_sphere(sphere, ray);
		printf("%d %f %f\n", xs.count, xs.xs[0], xs.xs[1]);
	}
	{
		t_sphere	sphere;
		t_ray		ray;
		t_intersection	xs;

		sphere.coordinate = do_point(0, 0, 0);
		sphere.diameter = 1.0;
		ray.origin = do_point(0, 1, -5);
		ray.direction = do_vector(0, 0, 1);
		xs = intersect_sphere(sphere, ray);
		printf("%d %f %f\n", xs.count, xs.xs[0], xs.xs[1]);
	}
	{
		t_sphere	sphere;
		t_ray		ray;
		t_intersection	xs;

		sphere.coordinate = do_point(0, 0, 0);
		sphere.diameter = 1.0;
		ray.origin = do_point(0, 2, -5);
		ray.direction = do_vector(0, 0, 1);
		xs = intersect_sphere(sphere, ray);
		printf("%d %f %f\n", xs.count, xs.xs[0], xs.xs[1]);
	}
	{
		t_sphere	sphere;
		t_ray		ray;
		t_intersection	xs;

		sphere.coordinate = do_point(0, 0, 0);
		sphere.diameter = 1.0;
		ray.origin = do_point(0, 0, 0);
		ray.direction = do_vector(0, 0, 1);
		xs = intersect_sphere(sphere, ray);
		printf("%d %f %f\n", xs.count, xs.xs[0], xs.xs[1]);
	}
	{
		t_sphere	sphere;
		t_ray		ray;
		t_intersection	xs;

		sphere.coordinate = do_point(0, 0, 0);
		sphere.diameter = 1.0;
		ray.origin = do_point(0, 0, 5);
		ray.direction = do_vector(0, 0, 1);
		xs = intersect_sphere(sphere, ray);
		printf("%d %f %f\n", xs.count, xs.xs[0], xs.xs[1]);
	}
}
