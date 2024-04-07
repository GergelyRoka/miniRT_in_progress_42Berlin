/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:12:44 by groka             #+#    #+#             */
/*   Updated: 2024/04/07 21:24:15 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ray.h"

t_point	position(t_ray ray, float t)
{
	return \
		(add_tuple_tuple(ray.origin, multiply_tuple_double(ray.direction, t)));
}
