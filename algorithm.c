/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 18:21:07 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/28 18:33:36 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_paint2(t_tochca a, t_tochca b, t_ptr *im)
{
	t_brezenham br;
	int			k;

	ft_do_brezen(&br, &a, &b);
	ft_paint2_count(a, b, &br);
	k = -1;
	mlx_pixel_put(im->mlx_ptr, im->win_ptr,
			a.x, a.y, a.color + (++k * br.step));
	while (a.x != b.x || a.y != b.y)
		if (ABS(br.aa) < ABS(br.bb))
		{
			if (ft_do_paint(br.aa, br.bb, &br.f) == 1)
				a.y = a.y + br.signy;
			a.x = a.x - br.signx;
			mlx_pixel_put(im->mlx_ptr, im->win_ptr,
					a.x, a.y, a.color + (++k * br.step));
		}
		else
		{
			if (ft_do_paint(br.bb, br.aa, &br.f) == 1)
				a.x = a.x - br.signx;
			a.y = a.y + br.signy;
			mlx_pixel_put(im->mlx_ptr, im->win_ptr,
					a.x, a.y, a.color + (++k * br.step));
		}
}

void	ft_do_brezen(t_brezenham *br, t_tochca *a, t_tochca *b)
{
	br->bb = (a->x - b->x);
	br->aa = (b->y - a->y);
	br->signx = br->bb > 0 ? 1 : -1;
	br->signy = br->aa > 0 ? 1 : -1;
	br->f = 0;
}

void	ft_paint2_count(t_tochca a, t_tochca b, t_brezenham *br)
{
	int f;
	int count;

	f = 0;
	br->count = 1;
	if (ABS(br->aa) < ABS(br->bb))
		while (a.x != b.x || a.y != b.y)
		{
			if (ft_do_paint(br->aa, br->bb, &f) == 1)
				a.y = a.y + br->signy;
			a.x = a.x - br->signx;
			br->count++;
		}
	else
		while (a.x != b.x || a.y != b.y)
		{
			if (ft_do_paint(br->bb, br->aa, &f) == 1)
				a.x = a.x - br->signx;
			a.y = a.y + br->signy;
			br->count++;
		}
	br->step = (b.color - a.color) / br->count;
}

int		ft_do_paint(int l1, int l2, int *f)
{
	int sign2;
	int sign1;

	sign2 = l2 > 0 ? 1 : -1;
	sign1 = l1 > 0 ? 1 : -1;
	*f = *f + l1 * sign1;
	if (*f > 0)
	{
		*f = *f - l2 * sign2;
		return (1);
	}
	return (0);
}
