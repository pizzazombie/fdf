/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/29 17:59:54 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_keys(t_all *all, double alpha, int key)
{
	if (key == 126)
		all->fdf->rotate_x -= alpha;
	else if (key == 97)
	{
		ft_default(all->fdf);
		all->fdf->rotate_x = 0.0174533 * 3 * 18;
		all->fdf->rotate_z = -0.0174533 * 3 * 15;
	}
	else if (key == 125)
		all->fdf->rotate_x += alpha;
	else if (key == 123)
		all->fdf->rotate_y -= alpha;
	else if (key == 124)
		all->fdf->rotate_y += alpha;
	else if (key == 43)
		all->fdf->rotate_z += alpha;
	else if (key == 47)
		all->fdf->rotate_z -= alpha;
	else
		color_keys(all, key);
}

void	ft_surprise(t_all *all)
{
	int		y;
	int		x;
	void	*mlx;
	void	*win;

	mlx = all->im->mlx_ptr;
	win = all->im->win_ptr;
	y = 0;
	while (y < all->fdf->high * 2 + 50)
	{
		x = 420;
		while (x < all->fdf->wind * 2 + 415)
		{
			mlx_string_put(mlx, win, x, y, 0xffffff, "YOU WIN!");
			x += 100;
		}
		y += 25;
	}
	mlx_string_put(mlx, win, 10, 520, 0xffff00,
		"You find key 42!!!");
}

void	color_keys(t_all *all, int key)
{
	if (key == 8)
	{
		all->fdf->top = 65535;
		all->fdf->bottom = 255;
	}
	else if (key == 9)
	{
		all->fdf->top = 16776960;
		all->fdf->bottom = 16711680;
	}
}

void	scale_keys(t_all *all, int key)
{
	if (key == 69)
	{
		all->fdf->scale += all->fdf->scale_default / 4.0;
		all->fdf->scale_z += all->fdf->scale_default / 4.0;
	}
	else if (key == 78)
	{
		if (all->fdf->scale > 1)
		{
			all->fdf->scale -= all->fdf->scale_default / 4.0;
			all->fdf->scale_z -= all->fdf->scale_default / 4.0;
		}
	}
	else if (key == 13)
		all->fdf->bias_yy -= 75;
	else if (key == 1)
		all->fdf->bias_yy += 75;
	else if (key == 0)
		all->fdf->bias_x -= 75;
	else if (key == 2)
		all->fdf->bias_x += 75;
}

int		deal_key(int key, void *param)
{
	t_all	*all;
	double	alpha;

	alpha = 0.0174533 * 3;
	all = (t_all*)param;
	if (key == 53)
	{
		ft_clean(all->fdf, all->fdf->line);
		exit(0);
	}
	else if (key == 96)
		ft_default(all->fdf);
	else if (key == 51)
	{
		mlx_clear_window(all->im->mlx_ptr, all->im->win_ptr);
		ft_put_text(all->im, all->fdf);
		return (0);
	}
	rotate_keys(all, alpha, key);
	scale_keys(all, key);
	mlx_clear_window(all->im->mlx_ptr, all->im->win_ptr);
	ft_show(all->im, all->fdf, all->fdf->rotate_x);
	if (key == 42)
		ft_surprise(all);
	return (0);
}
