/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/28 20:17:58 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_press(int button, int x, int y, void *param)
{
	t_all *all;

	all = (t_all*)param;
	if (button == 1)
		all->fdf->mouse_press = 1;
	if (button == 5)
	{
		all->fdf->scale += all->fdf->scale_default / 4.0;
		all->fdf->scale_z += all->fdf->scale_default / 4.0;
		mlx_clear_window(all->im->mlx_ptr, all->im->win_ptr);
		ft_show(all->im, all->fdf, all->fdf->rotate_x);
	}
	if (button == 4)
	{
		if (all->fdf->scale > 1)
		{
			all->fdf->scale -= all->fdf->scale_default / 4.0;
			all->fdf->scale_z -= all->fdf->scale_default / 4.0;
		}
		mlx_clear_window(all->im->mlx_ptr, all->im->win_ptr);
		ft_show(all->im, all->fdf, all->fdf->rotate_x);
	}
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_all *all;

	all = (t_all*)param;
	if (button == 1)
		all->fdf->mouse_press = 0;
	return (0);
}

void	ft_mouse_rotate(int x, int y, t_all *all, double alpha)
{
	if (x - all->fdf->mouse_x > 5)
	{
		all->fdf->rotate_z -= alpha;
		all->fdf->rotate_x -= alpha;
	}
	if (x - all->fdf->mouse_x < -5)
	{
		all->fdf->rotate_z += alpha;
		all->fdf->rotate_x += alpha;
	}
	if (y - all->fdf->mouse_y < -5)
		all->fdf->rotate_y -= alpha;
	if (y - all->fdf->mouse_y > 5)
		all->fdf->rotate_y += alpha;
}

int		mouse_move(int x, int y, void *param)
{
	t_all	*all;
	double	alpha;
	int		i;

	i = 0;
	alpha = 0.0174533 * 1.0;
	all = (t_all*)param;
	if (all->fdf->mouse_press == 1)
	{
		ft_mouse_rotate(x, y, all, alpha);
		mlx_clear_window(all->im->mlx_ptr, all->im->win_ptr);
		ft_show(all->im, all->fdf, all->fdf->rotate_x);
		all->fdf->mouse_x = x;
		all->fdf->mouse_y = y;
	}
	return (0);
}
