/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_to_paint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/29 17:52:20 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_open_win(t_ptr *im, t_map *fdf)
{
	ft_default(fdf);
	fdf->top = 16776960;
	fdf->bottom = 16711680;
	fdf->wind = cos(fdf->alpha) * ((fdf->line) +
			fdf->max_collumn) * 10 * fdf->scale;
	fdf->high = (fdf->max_high_positive - fdf->max_high_negative) / 100 *
		fdf->scale_z + sin(fdf->alpha) *
		((fdf->line) + fdf->max_collumn) * 10 * fdf->scale;
	im->mlx_ptr = mlx_init();
	if (fdf->wind > 1500)
		fdf->wind = 1500;
	if (fdf->high > 1500)
		fdf->high = 1500;
	if (fdf->high < 223)
		fdf->high = 245;
	im->win_ptr = mlx_new_window(im->mlx_ptr, 451 + fdf->wind * 2,
			fdf->high * 2 + 50, "hello, my friend!!!");
}

void	ft_print(t_map *fdf)
{
	int ii;
	int jj;

	ii = 0;
	while (ii < fdf->line)
	{
		jj = 1;
		while (jj < fdf->mapi[ii][0].x)
		{
			ft_printf("%3d,", fdf->mapi[ii][(jj)].x / 1000);
			ft_printf("%3d,", fdf->mapi[ii][(jj)].y / 1000);
			ft_printf("%3d  || ", fdf->mapi[ii][(jj)].z / 1000);
			jj++;
		}
		ft_printf("\n");
		ii++;
	}
	ft_printf("scale_z = %f\n\n", fdf->scale_z);
}

void	ft_clean(t_map *fdf, int n)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		free(fdf->mapi[i]);
		i++;
	}
	free(fdf->mapi);
}
