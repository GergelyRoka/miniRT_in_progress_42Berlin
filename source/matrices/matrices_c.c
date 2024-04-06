/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:58:45 by groka             #+#    #+#             */
/*   Updated: 2024/04/06 17:07:24 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/matrices.h"

// list of the functions of matrices_c.c
bool		is_invertible_matrix(t_matrix a);
t_matrix	inverse_matrix(t_matrix a);

bool	is_invertible_matrix(t_matrix a)
{
	return (determinant_matrix(a) != 0);
}

t_matrix	inverse_matrix(t_matrix a)
{
	t_matrix	res;
	double		det;
	int			i;
	int			j;

	res.size = a.size;
	det = determinant_matrix(a);
	i = 0;
	while (i < res.size)
	{
		j = 0;
		while (j < res.size)
		{
			res.matrix[i][j] = cofactor_matrix(a, j, i) / det;
			++j;
		}
		++i;
	}
	return (res);
}
