/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:57:38 by groka             #+#    #+#             */
/*   Updated: 2024/04/06 19:05:20 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/matrices.h"

t_matrix	translation(double x, double y, double z);

t_matrix	translation(double x, double y, double z)
{
	t_matrix	res;

	res = identity_matrix();
	res.matrix[0][3] = x;
	res.matrix[1][3] = y;
	res.matrix[2][3] = z;
	return (res);
}