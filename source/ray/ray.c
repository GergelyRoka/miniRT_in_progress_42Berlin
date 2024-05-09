/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:12:44 by groka             #+#    #+#             */
/*   Updated: 2024/05/09 16:16:28 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ray.h"


/*
	Scenario: Creating and querying a ray
	Given origin ← point(1, 2, 3)
	And direction ← vector(4, 5, 6)
	When r ← ray(origin, direction)
	Then r.origin = origin
	And r.direction = direction
*/
t_ray	do_ray(t_point origin, t_vector direction)
{
	return ((t_ray){.origin = origin, .direction = direction});
}

t_point	position(t_ray ray, float t)
{
	return \
		(add_tuple_tuple(ray.origin, multiply_tuple_double(ray.direction, t)));
}
