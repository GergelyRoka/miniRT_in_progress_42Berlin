/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:17:05 by groka             #+#    #+#             */
/*   Updated: 2024/04/06 16:29:19 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/matrices.h"
#include <stdio.h>

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
	{1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1}};

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

double	determinant_matrix(t_matrix a);
t_matrix	submatrix(t_matrix a, int row, int col);

double	minor_matrix(t_matrix a, int x, int y)
{
	return (determinant_matrix(submatrix(a, x, y)));
}

double	cofactor_matrix(t_matrix a, int x, int y)
{
	if ((x + y) % 2 == 0)
		return minor_matrix(a, x, y);
	else
		return ((-1) * minor_matrix(a, x, y));
	//return ((x + y) % 2 ? -1 : 1) * minor_matrix(a, x, y);
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

/// @brief //////////////////////
/// @param a 
void	print_matrix(t_matrix a)
{
	int	i;
	int	j;
	printf("matrix:\n");
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			printf("%f ", a.matrix[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
}

void	print_tuple(t_tuple a)
{
	printf("%f %f %f %f\n", a.x, a.y, a.z, a.w);
}



int main()
{
	t_matrix a = {4, {1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6, 4, 5, 6, 7}};
	t_matrix b = {4, {0, 1, 2, 4, 1, 2, 4, 8, 2, 4, 8, 16, 4, 8, 16, 32}};
	t_matrix c = {4, {1, 2, 3, 4, 2, 4, 4, 2, 8, 6, 4, 1, 0, 0, 0, 1}};
	t_matrix d = {4, {0, 9, 3, 0, 9, 8, 0, 8, 1, 8 , 5, 3, 0 , 0, 5, 8}};

	print_matrix(multiply_matrix(a, b));
	print_matrix(c);
	print_tuple(multiply_matrix_tuple(c, (t_tuple){1, 2, 3, 1}));
	print_matrix(a);
	print_matrix(multiply_matrix(a, identity_matrix()));
	print_matrix(d);
	print_matrix(transpose_matrix(d));
	print_matrix(d);
	print_matrix(submatrix(d, 0, 0));
	print_matrix(submatrix(submatrix(d, 0, 0), 0 ,0));

	t_matrix e = {3, {3, 5, 0, 0, 2, -1, -7, 0, 6, -1, 5, 0}};
	print_matrix(e);
	printf("minor:\t\t%f\n", minor_matrix(e, 1, 0));
	printf("cofator:\t%f\n", cofactor_matrix(e, 1, 0));
	printf("minor:\t\t%f\n", minor_matrix(e, 0, 0));
	printf("cofactor:\t%f\n", cofactor_matrix(e, 0, 0));
	t_matrix f = {3, {1, 2, 6, 0, -5, 8, -4, 0, 2, 6, 4, 0}};
	printf("determinant:\t%f\n", determinant_matrix(f));
	t_matrix g = {4, {-2, -8, 3, 5, -3, 1, 7, 3, 1, 2, -9, 6, -6, 7, 7, -9}};
	printf("determinant:\t%f\n", determinant_matrix(g));

	printf("%f, %f, %f, %f\n",
		determinant_matrix(submatrix(g, 0, 0)),
		determinant_matrix(submatrix(g, 0, 1)),
		determinant_matrix(submatrix(g, 0, 2)),
		determinant_matrix(submatrix(g, 0, 3)));
	print_matrix(submatrix(g, 0, 0));
	t_matrix h = {4, {6, 4, 4, 4, 5, 5, 7, 6, 4, -9, 3, -7, 9, 1, -3, -6}};
	t_matrix i = {4, {-4, 2, -2, -3, 9, 6, 2, 6, 0, -5, 1, -5, 0, 0, 0, 0}};
	printf("h: %s\ni: %s\n", (is_invertible_matrix(h) ? "true" : "false"), (is_invertible_matrix(i) ? "true" : "false"));

	//inverz test
	t_matrix j = {4, {-5, 2, 6, -8, 1, -5, 1, 8, 7, 7, -6, -7, 1, -3, 7, 4}};
	print_matrix(j);
	print_matrix(inverse_matrix(j));
	t_matrix k = {4, {8, -5, 9, 2, 7, 5, 6, 1, -6, 0, 9, 6, -3, 0, -9, -4}};
	print_matrix(inverse_matrix(k));
	t_matrix l = {4, {9, 3, 0, 9, -5, -2, -6, -3, -4, 9, 6, 4, -7, 6, 6, 2}};
	print_matrix(inverse_matrix(l));
	// test
	// m == (m * n) * (inverse(n))
	// there is a lil error because of representation of floats
	t_matrix m = {4, {3, -9, 7, 3, 3, -8, 2, -9, -4, 4, 4, 1, -6, 5, -1, 1}};
	t_matrix n = {4, {8, 2, 2, 2, 3, -1, 7, 0, 7, 0, 5, 4, 6, -2, 0, 5}};
	print_matrix(m);
	print_matrix(multiply_matrix(multiply_matrix(m, n), inverse_matrix(n)));
	//printf("m == (m * n) * (inverse(n)) is %s\n", is_equal_matrix(multiply_matrix(multiply_matrix(m, n), inverse_matrix(n)), m) ? "true" : "false");
}
