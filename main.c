/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/30 16:39:27 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_map fdf;
	t_all all;
	t_ptr im;

	if (argc != 2)
		no_args(1);
	ft_read_data(argv[1], &fdf);
	ft_open_win(&im, &fdf);
	ft_change_center(&fdf);
	all.fdf = &fdf;
	all.im = &im;
	all.fdf->mouse_x = 0;
	all.fdf->mouse_y = 0;
	ft_bias(&fdf);
	ft_show(all.im, all.fdf, all.fdf->rotate_x);
	mlx_key_hook(im.win_ptr, deal_key, &all);
	mlx_hook(im.win_ptr, 4, 0, mouse_press, &all);
	mlx_hook(im.win_ptr, 5, 0, mouse_release, &all);
	mlx_hook(im.win_ptr, 6, 0, mouse_move, &all);
	mlx_loop(im.mlx_ptr);
	return (0);
}

/*
** set default parameters, top is yellow, bottom is red
*/

void	ft_default(t_map *fdf)
{
	fdf->alpha = 0.523599;
	fdf->mouse_press = 0;
	fdf->rotate_x = 0.0;
	fdf->rotate_y = 0.0;
	fdf->rotate_z = 0.0;
	if ((fdf->line) * fdf->max_collumn < 1000)
		fdf->scale_default = 2;
	else if ((fdf->line) * fdf->max_collumn < 10000)
		fdf->scale_default = 0.7;
	else if ((fdf->line) * fdf->max_collumn < 100000)
		fdf->scale_default = 0.5;
	else
		fdf->scale_default = 0.2;
	fdf->scale_z = fdf->scale_default;
	fdf->scale = fdf->scale_default;
}

void	ft_bias(t_map *fdf)
{
	fdf->bias_x = fdf->wind + 415;
	fdf->bias_yy = fdf->high;
}

/*
** change coordinates for rotate about center of map
*/

void	ft_change_center(t_map *fdf)
{
	int ii;
	int jj;

	ii = 0;
	while (ii < fdf->line)
	{
		jj = 1;
		while (jj < fdf->mapi[ii][0].x)
		{
			fdf->mapi[ii][jj].x -= fdf->max_collumn * 1000 / 2;
			fdf->mapi[ii][jj].y -= fdf->line * 1000 / 2;
			jj++;
		}
		ii++;
	}
}

void	ft_check_valid(t_map *fdf)
{
	int ii;

	ii = 1;
	while (ii < fdf->line)
	{
		if (fdf->mapi[0][0].x != fdf->mapi[ii][0].x)
		{
			ft_clean(fdf, fdf->line);
			no_args(3);
		}
		ii++;
	}
}
