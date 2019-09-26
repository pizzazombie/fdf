/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 18:55:53 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/29 16:01:20 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_show(t_ptr *im, t_map *fdf, double alpha)
{
	t_tochca	a;
	t_tochca	b;
	int			ii;
	int			jj;

	ft_put_text(im, fdf);
	ii = -1;
	while (++ii < fdf->line)
	{
		jj = 0;
		while (++jj < fdf->mapi[ii][0].x)
		{
			a = ft_do_tochka(fdf, ii, jj);
			if (ii != fdf->line - 1)
			{
				b = ft_do_tochka(fdf, ii + 1, jj);
				ft_paint2(a, b, im);
			}
			if (jj != fdf->mapi[ii][0].x - 1)
			{
				b = ft_do_tochka(fdf, ii, jj + 1);
				ft_paint2(a, b, im);
			}
		}
	}
}

t_tochca	ft_do_tochka(t_map *fdf, int ii, int jj)
{
	t_tochca a;

	a.x = fdf->mapi[ii][(jj)].x;
	a.y = fdf->mapi[ii][(jj)].y;
	a.z = fdf->mapi[ii][(jj)].z;
	if (a.z == fdf->max_high_negative)
		a.color = fdf->bottom;
	else if (a.z == fdf->max_high_positive)
		a.color = fdf->top;
	else
	{
		a.color = fdf->bottom + ((fdf->top - fdf->bottom) * a.z) /
			(fdf->max_high_positive - fdf->max_high_negative);
	}
	rotate_x(&a.y, &a.z, fdf);
	rotate_y(&a.x, &a.z, fdf);
	rotate_z(&a.y, &a.x, fdf);
	ft_change_point(fdf, &a, &a);
	return (a);
}

/*
** rotate X-axis
*/

void		rotate_x(int *y, int *z, t_map *fdf)
{
	int previous_y;
	int previous_z;

	previous_y = *y;
	if (fdf->scale_z == 0)
		previous_z = 0;
	else
		previous_z = *z;
	*y = ((double)previous_y * (100.0 * cos(fdf->rotate_x)) + previous_z *
			(100.0 * (sin(fdf->rotate_x)))) / 100.0;
	*z = (-previous_y * (100.0 * sin(fdf->rotate_x)) + previous_z *
			(100.0 * cos(fdf->rotate_x))) / 100.0;
}

/*
** rotate Y-axis
*/

void		rotate_y(int *x, int *z, t_map *fdf)
{
	int previous_x;
	int previous_z;

	previous_x = *x;
	previous_z = *z;
	*x = ((double)previous_x * (100.0 * cos(fdf->rotate_y)) + previous_z *
			(100.0 * (sin(fdf->rotate_y)))) / 100.0;
	*z = (-previous_x * (100.0 * sin(fdf->rotate_y)) + previous_z *
			(100.0 * cos(fdf->rotate_y))) / 100.0;
}

/*
** rotate Z-axis
*/

void		rotate_z(int *y, int *x, t_map *fdf)
{
	int previous_y;
	int previous_x;

	previous_y = *y;
	previous_x = *x;
	*x = ((double)previous_x * (100.0 * cos(fdf->rotate_z)) - previous_y *
			(100.0 * (sin(fdf->rotate_z)))) / 100.0;
	*y = (previous_x * (100.0 * sin(fdf->rotate_z)) + previous_y *
			(100.0 * cos(fdf->rotate_z))) / 100.0;
}
