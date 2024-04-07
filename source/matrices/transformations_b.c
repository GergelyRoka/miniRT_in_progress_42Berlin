/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:03:27 by groka             #+#    #+#             */
/*   Updated: 2024/04/07 17:09:51 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/matrices.h"

t_matrix	shearing_matrix(t_tuple x, t_tuple y, t_tuple z);

// maybe the params are not the best here

t_matrix	shearing_matrix(t_tuple x, t_tuple y, t_tuple z)
{
	t_matrix	res;

	res = identity_matrix();
	res.matrix[0][1] = x.y;
	res.matrix[0][2] = x.z;
	res.matrix[1][0] = y.x;
	res.matrix[1][2] = y.z;
	res.matrix[2][0] = z.x;
	res.matrix[2][1] = z.y;
	return (res);
}
