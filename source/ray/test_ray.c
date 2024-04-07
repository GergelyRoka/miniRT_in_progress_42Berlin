/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:22:19 by groka             #+#    #+#             */
/*   Updated: 2024/04/07 21:23:15 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	print_tuple(position(ray, 0.0));
	print_tuple(position(ray, 1.0));
	print_tuple(position(ray, -1.0));
	print_tuple(position(ray, 2.5));
}
