/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrices.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:02:17 by groka             #+#    #+#             */
/*   Updated: 2024/04/06 17:15:41 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/matrices.h"
#include <stdio.h>

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
	t_matrix a = {4, {
		{1, 2, 3, 4},
		{2, 3, 4, 5},
		{3, 4, 5, 6},
		{4, 5, 6, 7}
	}};
	t_matrix b = {4, {
		{0, 1, 2, 4},
		{1, 2, 4, 8},
		{2, 4, 8, 16},
		{4, 8, 16, 32}
	}};
	t_matrix c = {4, {
		{1, 2, 3, 4},
		{2, 4, 4, 2},
		{8, 6, 4, 1},
		{0, 0, 0, 1}
	}};
	t_matrix d = {4, {
		{0, 9, 3, 0},
		{9, 8, 0, 8},
		{1, 8 , 5, 3},
		{0 , 0, 5, 8}
	}};

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

	t_matrix e = {3, {
		{3, 5, 0},
		{0, 2, -1},
		{-7, 0, 6},
		{-1, 5, 0}
	}};
	print_matrix(e);
	printf("minor:\t\t%f\n", minor_matrix(e, 1, 0));
	printf("cofator:\t%f\n", cofactor_matrix(e, 1, 0));
	printf("minor:\t\t%f\n", minor_matrix(e, 0, 0));
	printf("cofactor:\t%f\n", cofactor_matrix(e, 0, 0));
	t_matrix f = {3, {
		{1, 2, 6},
		{0, -5, 8},
		{-4, 0, 2},
		{6, 4, 0}
	}};
	printf("determinant:\t%f\n", determinant_matrix(f));
	t_matrix g = {4, {
		{-2, -8, 3, 5},
		{-3, 1, 7, 3},
		{1, 2, -9, 6},
		{-6, 7, 7, -9}
	}};
	printf("determinant:\t%f\n", determinant_matrix(g));

	printf("%f, %f, %f, %f\n",
		determinant_matrix(submatrix(g, 0, 0)),
		determinant_matrix(submatrix(g, 0, 1)),
		determinant_matrix(submatrix(g, 0, 2)),
		determinant_matrix(submatrix(g, 0, 3)));
	print_matrix(submatrix(g, 0, 0));
	t_matrix h = {4, {
		{6, 4, 4, 4},
		{5, 5, 7, 6},
		{4, -9, 3, -7},
		{9, 1, -3, -6}
	}};
	t_matrix i = {4, {
		{-4, 2, -2, -3},
		{9, 6, 2, 6},
		{0, -5, 1, -5},
		{0, 0, 0, 0}
	}};
	printf("h: %s\ni: %s\n", (is_invertible_matrix(h) ? "true" : "false"), (is_invertible_matrix(i) ? "true" : "false"));

	// Inverse test
	t_matrix j = {4, {
		{-5, 2, 6, -8},
		{1, -5, 1, 8},
		{7, 7, -6, -7},
		{1, -3, 7, 4}
	}};
	print_matrix(j);
	print_matrix(inverse_matrix(j));
	t_matrix k = {4, {
		{8, -5, 9, 2},
		{7, 5, 6, 1},
		{-6, 0, 9, 6},
		{-3, 0, -9, -4}
	}};
	print_matrix(inverse_matrix(k));
	t_matrix l = {4, {
		{9, 3, 0, 9},
		{-5, -2, -6, -3},
		{-4, 9, 6, 4},
		{-7, 6, 6, 2}
	}};
	print_matrix(inverse_matrix(l));

	// Test
	// m == (m * n) * (inverse(n))
	// There is a small error because of representation of floats
	t_matrix m = {4, {
		{3, -9, 7, 3},
		{3, -8, 2, -9},
		{-4, 4, 4, 1},
		{-6, 5, -1, 1}
	}};
	t_matrix n = {4, {
		{8, 2, 2, 2},
		{3, -1, 7, 0},
		{7, 0, 5, 4},
		{6, -2, 0, 5}
	}};
	print_matrix(m);
	print_matrix(multiply_matrix(multiply_matrix(m, n), inverse_matrix(n)));
	// printf("m == (m * n) * (inverse(n)) is %s\n", is_equal_matrix(multiply_matrix(multiply_matrix(m, n),
}