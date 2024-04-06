/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_transformations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:10:47 by groka             #+#    #+#             */
/*   Updated: 2024/04/06 19:29:59 by groka            ###   ########.fr       */
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

int main( void )
{
	{
		/*
			Scenario: Multiplying by a translation matrix
			Given transform ← translation(5, -3, 2)
			And p ← point(-3, 4, 5)
			Then transform * p = point(2, 1, 7)
		*/
		print_tuple(multiply_by_translation(translation_matrix(5, -3, 2), do_point(-3, 4, 5)));
	}
	{
		/*
			Scenario: Multiplying by the inverse of a translation matrix
			Given transform ← translation(5, -3, 2)
			And inv ← inverse(transform)
			And p ← point(-3, 4, 5)
			Then inv * p = point(-8, 7, 3)
		*/
		print_tuple(multiply_by_inv_translation(translation_matrix(5, -3, 2), do_point(-3, 4, 5)));
	}
	{
		/*
			Scenario: Translation does not affect vectors
			Given transform ← translation(5, -3, 2)
			And v ← vector(-3, 4, 5)
			Then transform * v = v
		*/
		print_tuple(multiply_by_translation(translation_matrix(5, -3, 2), do_vector(-3, 4, 5)));
	}
	return (0);
}