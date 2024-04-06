/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:15:08 by groka             #+#    #+#             */
/*   Updated: 2024/04/06 17:02:05 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include <stdbool.h>
# include "tuples.h"

typedef struct s_matrix
{
	int		size;
	double	matrix[4][4];
}	t_matrix;

//matrices_a.c
bool		is_equal_matrix(t_matrix a, t_matrix b);
t_matrix	multiply_matrix(t_matrix a, t_matrix b);
t_tuple		multiply_matrix_tuple(t_matrix a, t_tuple b);
t_matrix	identity_matrix(void);
t_matrix	transpose_matrix(t_matrix a);

// matrices_b.c
double		minor_matrix(t_matrix a, int x, int y);
double		cofactor_matrix(t_matrix a, int x, int y);
double		determinant_matrix(t_matrix a);
t_matrix	submatrix(t_matrix a, int row, int col);

// matrices_c.c
bool		is_invertible_matrix(t_matrix a);
t_matrix	inverse_matrix(t_matrix a);

#endif
