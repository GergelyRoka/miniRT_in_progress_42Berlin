/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_clock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:53:39 by groka             #+#    #+#             */
/*   Updated: 2024/04/07 19:38:58 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/matrices.h"
#include "../../include/tuples.h"
#include "../../include/colors.h"
#include "../../include/canvas.h"
#include <stdio.h>

void	canvas_to_ppm(t_color **canvas, int width, int height);

void	print_tuple(t_tuple a)
{
	printf("%f %f %f %f\n", a.x, a.y, a.z, a.w);
}

int main(void)
{
	t_color	**canvas;
	t_point	origin;
	t_point	point;

	canvas = create_canvas(500, 500);
	origin = do_point(250, 250, 0);
	point = do_point(0, -1, 0);
	t_matrix trans = translation_matrix(0, 100, 0);
	point = multiply_matrix_tuple(trans, point);
	point = add_tuple_tuple(origin, point);
	//point = multiply_matrix_tuple(rotation_z_matrix(PI / 6), point);
	canvas[(int)point.y][(int)point.x] = (t_color){255, 0, 0};

	for (int i = 0; i < 12; i++)
	{
		point = do_point(0, -1, 0);
		point = multiply_matrix_tuple(trans, point);
		point = multiply_matrix_tuple(rotation_z_matrix((2*PI/12 * i)), point);
		point.x += origin.x;
		point.y += origin.y;
		print_tuple(point);
		canvas[(int)point.x][(int)point.y] = (t_color){255, 0, 0};
		canvas[(int)point.x-1][(int)point.y] = (t_color){255, 0, 0};
		canvas[(int)point.x+1][(int)point.y] = (t_color){255, 0, 0};
		canvas[(int)point.x][(int)point.y-1] = (t_color){255, 0, 0};
		canvas[(int)point.x][(int)point.y+1] = (t_color){255, 0, 0};
	}


	canvas_to_ppm(canvas, 500, 500);


	free_canvas(canvas);
	return 0;
}
