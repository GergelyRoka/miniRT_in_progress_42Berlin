/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:15:02 by groka             #+#    #+#             */
/*   Updated: 2024/04/07 19:11:27 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/canvas.h"
#include <stdlib.h>

# define HEIGHT 500

t_color	**create_canvas(int width, int height)
{
	int		i;
	int		j;
	t_color	**canvas;

	canvas = (t_color **)malloc(sizeof(t_color *) * height);
	if (!canvas)
		return (NULL);
	i = 0;
	while (i < height)
	{
		canvas[i] = (t_color *)malloc(sizeof(t_color) * width);
		if (!canvas[i])
			return (NULL);
		j = 0;
		while (j < width)
		{
			canvas[i][j] = (t_color){0.0, 0.0, 0.0};
			j++;
		}
		i++;
	}
	return (canvas);
}

void	write_pixel(t_color **canvas, int x, int y, t_color color)
{
	canvas[y][x] = color;
}

void	free_canvas(t_color **canvas)
{
	int	i;

	i = 0;
	while (i < HEIGHT)
	{
		free(canvas[i]);
		i++;
	}
	free(canvas);
}
