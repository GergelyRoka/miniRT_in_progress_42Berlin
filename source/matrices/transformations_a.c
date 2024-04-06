/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:57:38 by groka             #+#    #+#             */
/*   Updated: 2024/04/06 20:42:45 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/matrices.h"

t_matrix	translation_matrix(double x, double y, double z);
t_matrix	scaling_matrix(double x, double y, double z);
t_matrix	rotation_x_matrix(double angle);
t_matrix	rotation_y_matrix(double angle);
t_matrix	rotation_z_matrix(double angle);

t_matrix	translation_matrix(double x, double y, double z)
{
	t_matrix	res;

	res = identity_matrix();
	res.matrix[0][3] = x;
	res.matrix[1][3] = y;
	res.matrix[2][3] = z;
	return (res);
}

t_matrix	scaling_matrix(double x, double y, double z)
{
	t_matrix	res;

	res = identity_matrix();
	res.matrix[0][0] = x;
	res.matrix[1][1] = y;
	res.matrix[2][2] = z;
	return (res);
}

t_matrix	rotation_x_matrix(double angle)
{
	t_matrix	res;

	res = identity_matrix();
	res.matrix[1][1] = cos(angle);
	res.matrix[2][2] = cos(angle);
	res.matrix[1][2] = -sin(angle);
	res.matrix[2][1] = sin(angle);
	return (res);
}

t_matrix	rotation_y_matrix(double angle)
{
	t_matrix	res;

	res = identity_matrix();
	res.matrix[0][0] = cos(angle);
	res.matrix[2][2] = cos(angle);
	res.matrix[0][2] = sin(angle);
	res.matrix[2][0] = -sin(angle);
	return (res);
}

t_matrix	rotation_z_matrix(double angle)
{
	t_matrix	res;

	res = identity_matrix();
	res.matrix[0][0] = cos(angle);
	res.matrix[1][1] = cos(angle);
	res.matrix[0][1] = -sin(angle);
	res.matrix[1][0] = sin(angle);
	return (res);
}
