/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:52:23 by groka             #+#    #+#             */
/*   Updated: 2024/04/06 17:16:38 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/matrices.h"

// list of the functions of matrices_a.c
bool		is_equal_matrix(t_matrix a, t_matrix b);
t_matrix	multiply_matrix(t_matrix a, t_matrix b);
t_tuple		multiply_matrix_tuple(t_matrix a, t_tuple b);
t_matrix	identity_matrix(void);
t_matrix	transpose_matrix(t_matrix a);

bool	is_equal_matrix(t_matrix a, t_matrix b)
{
	int	i;
	int	j;

	if (a.size != b.size)
		return (false);
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			if (a.matrix[i][j] != b.matrix[i][j])
				return (false);
			++j;
		}
		++i;
	}
	return (true);
}

t_matrix	multiply_matrix(t_matrix a, t_matrix b)
{
	t_matrix	res;
	int			i;
	int			j;
	int			k;

	res.size = a.size;
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			k = 0;
			while (k < a.size)
			{
				res.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
				++k;
			}
			++j;
		}
		++i;
	}
	return (res);
}

t_tuple	multiply_matrix_tuple(t_matrix a, t_tuple b)
{
	double			res[4];
	const double	tmp[4] = {b.x, b.y, b.z, b.w};
	int				i;
	int				j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		res[i] = 0;
		while (j < 4)
		{
			res[i] += a.matrix[i][j] * tmp[j];
			++j;
		}
		++i;
	}
	return ((t_tuple){res[0], res[1], res[2], res[3]});
}

t_matrix	identity_matrix(void)
{
	const t_matrix	res = {4,
	{{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}}};

	return (res);
}

t_matrix	transpose_matrix(t_matrix a)
{
	t_matrix	res;
	int			i;
	int			j;

	res.size = a.size;
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			res.matrix[j][i] = a.matrix[i][j];
			++j;
		}
		++i;
	}
	return (res);
}
