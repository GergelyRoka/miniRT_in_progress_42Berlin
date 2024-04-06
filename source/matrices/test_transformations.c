/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_transformations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:10:47 by groka             #+#    #+#             */
/*   Updated: 2024/04/06 20:44:05 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/matrices.h"

#include <stdio.h>

void	print_matrix(t_matrix a);
void	print_tuple(t_tuple a);
t_point	multiply_by_translation(t_matrix transform, t_point p);
t_point	multiply_by_inv_translation(t_matrix transform, t_point p);

int main( void )
{
	// TEST Translation
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
	// TEST Scaling
	{
		/*
			Scenario: A scaling matrix applied to a point
			Given transform ← scaling(2, 3, 4)
			And p ← point(-4, 6, 8)
			Then transform * p = point(-8, 18, 32)
		*/
		print_tuple(multiply_matrix_tuple(scaling_matrix(2, 3, 4), do_point(-4, 6, 8)));
	}
	{
		/*
			Now, unlike translation, scaling applies to vectors as well, changing their
			length. Add the following test to show how vectors are affected by scaling.

			Scenario: A scaling matrix applied to a vector
			Given transform ← scaling(2, 3, 4)
			And v ← vector(-4, 6, 8)
			Then transform * v = vector(-8, 18, 32)
		*/
		print_tuple(multiply_matrix_tuple(scaling_matrix(2, 3, 4), do_vector(-4, 6, 8)));
	}
	{
		/*
			And as you might expect, multiplying a tuple by the inverse of a scaling matrix
			will scale the tuple in the opposite way (shrinking instead of growing, or vice
			versa). Add the following test to show that this is so.

			Scenario: Multiplying by the inverse of a scaling matrix
			Given transform ← scaling(2, 3, 4)
			And inv ← inverse(transform)
			And v ← vector(-4, 6, 8)
			Then inv * v = vector(-2, 2, 2)
		*/
		print_tuple(multiply_matrix_tuple(inverse_matrix(scaling_matrix(2, 3, 4)), do_vector(-4, 6, 8)));
	}
	{
		/*
			Reflection is essentially the same thing as scaling by a negative value.
			Implement the following test, which shows how a point can be reflected across
			the x axis by scaling the x component by -1.

			Scenario: Reflection is scaling by a negative value
			Given transform ← scaling(-1, 1, 1)
			And p ← point(2, 3, 4)
			Then transform * p = point(-2, 3, 4)

			Just like that, the point was moved from the positive side of the x axis, to the
			negative.
		*/
		print_tuple(multiply_matrix_tuple(scaling_matrix(-1, 1, 1), do_point(2, 3, 4)));
	}
	{
		/*
			Rotation Around the X Axis
			This first rotation matrix rotates a tuple some number of radians around the
			x axis, and will be created by introducing a new rotation_x(radians) function. Prove
			it works by adding the following test, which shows off rotating a point around
			the x axis.

			Scenario: Rotating a point around the x axis
			Given p ← point(0, 1, 0)
			And half_quarter ← rotation_x(π / 4)
			And full_quarter ← rotation_x(π / 2)
			Then half_quarter * p = point(0, √2/2, √2/2)
			And full_quarter * p = point(0, 0, 1)
		*/
		printf("TEST rotation around X axis, half and full quarter\n");
		print_tuple(multiply_matrix_tuple(rotation_x_matrix(PI / 4), do_point(0, 1, 0)));
		print_tuple(multiply_matrix_tuple(rotation_x_matrix(PI / 2), do_point(0, 1, 0)));
	}
	{
		/*
			Next, add another test showing that the inverse of this rotation matrix simply
			rotates in the opposite direction.

			Scenario: The inverse of an x-rotation rotates in the opposite direction
			Given p ← point(0, 1, 0)
			And half_quarter ← rotation_x(π / 4)
			And inv ← inverse(half_quarter)
			Then inv * p = point(0, √2/2, -√2/2)
		*/
		printf("TEST rotation around X axis, opposite direction\n");
		print_tuple(multiply_matrix_tuple(inverse_matrix(rotation_x_matrix(PI / 4)), do_point(0, 1, 0)));
	}
	{
		/*
			Rotation Around the Y Axis
			The y axis rotation works just like the x axis rotation, only changing the axis.
			Add the following test to demonstrate the difference.

			Scenario: Rotating a point around the y axis
			Given p ← point(0, 0, 1)
			And half_quarter ← rotation_y(π / 4)
			And full_quarter ← rotation_y(π / 2)
			Then half_quarter * p = point(√2/2, 0, √2/2)
			And full_quarter * p = point(1, 0, 0)
		*/
		printf("TEST rotation around Y axis, half and full quarter\n");
		print_tuple(multiply_matrix_tuple(rotation_y_matrix(PI / 4), do_point(0, 0, 1)));
		print_tuple(multiply_matrix_tuple(rotation_y_matrix(PI / 2), do_point(0, 0, 1)));
	}
	{
		/*
			Rotation Around the Z Axis
			And last, but not least: the z axis rotation. Show that it works just like the
			other rotations, by implementing the following test.

			Scenario: Rotating a point around the z axis
			Given p ← point(0, 1, 0)
			And half_quarter ← rotation_z(π / 4)
			And full_quarter ← rotation_z(π / 2)
			Then half_quarter * p = point(-√2/2, √2/2, 0)
			And full_quarter * p = point(-1, 0, 0)
		*/
		printf("TEST rotation around Z axis, half and full quarter\n");
		print_tuple(multiply_matrix_tuple(rotation_z_matrix(PI / 4), do_point(0, 1, 0)));
		print_tuple(multiply_matrix_tuple(rotation_z_matrix(PI / 2), do_point(0, 1, 0)));
	}
	return (0);
}

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

t_point	multiply_by_translation(t_matrix transform, t_point p)
{
	return (multiply_matrix_tuple(transform, p));
}

t_point	multiply_by_inv_translation(t_matrix transform, t_point p)
{
	return (multiply_matrix_tuple(inverse_matrix(transform), p));
}