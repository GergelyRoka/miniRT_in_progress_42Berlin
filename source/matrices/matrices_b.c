/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:55:55 by groka             #+#    #+#             */
/*   Updated: 2024/04/06 17:16:59 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/matrices.h"

// list of the functions of matrices_b.c
double		minor_matrix(t_matrix a, int x, int y);
double		cofactor_matrix(t_matrix a, int x, int y);
double		determinant_matrix(t_matrix a);
t_matrix	submatrix(t_matrix a, int row, int col);

double	minor_matrix(t_matrix a, int x, int y)
{
	return (determinant_matrix(submatrix(a, x, y)));
}

double	cofactor_matrix(t_matrix a, int x, int y)
{
	if ((x + y) % 2 == 0)
		return (minor_matrix(a, x, y));
	else
		return ((-1) * minor_matrix(a, x, y));
}

double	determinant_matrix(t_matrix a)
{
	if (a.size == 2)
		return (a.matrix[0][0] * a.matrix[1][1]
			- a.matrix[0][1] * a.matrix[1][0]);
	if (a.size == 3)
		return (a.matrix[0][0] * cofactor_matrix(a, 0, 0)
			+ a.matrix[0][1] * cofactor_matrix(a, 0, 1)
			+ a.matrix[0][2] * cofactor_matrix(a, 0, 2));
	if (a.size == 4)
		return (a.matrix[0][0] * determinant_matrix(submatrix(a, 0, 0))
			+ a.matrix[0][1] * (-1) * determinant_matrix(submatrix(a, 0, 1))
			+ a.matrix[0][2] * determinant_matrix(submatrix(a, 0, 2))
			+ a.matrix[0][3] * (-1) * determinant_matrix(submatrix(a, 0, 3))
			);
	return (0);
}

t_matrix	submatrix(t_matrix a, int row, int col)
{
	t_matrix	res;
	int			i;
	int			j;

	res.size = a.size - 1;
	i = 0;
	while (i < res.size)
	{
		j = 0;
		while (j < res.size)
		{
			if (i < row && j < col)
				res.matrix[i][j] = a.matrix[i][j];
			else if (i < row && j >= col)
				res.matrix[i][j] = a.matrix[i][j + 1];
			else if (i >= row && j < col)
				res.matrix[i][j] = a.matrix[i + 1][j];
			else if (i >= row && j >= col)
				res.matrix[i][j] = a.matrix[i + 1][j + 1];
			++j;
		}
		++i;
	}
	return (res);
}
