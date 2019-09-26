/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/30 14:48:45 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_spec(char *str, int *i, int *k)
{
	if (*i == 0)
		str[*i] = '0';
	else
	{
		if (str[*i - 1] != ' ')
		{
			while (str[*i] != ' ' && str[*i] != '\0')
			{
				str[*i] = ' ';
				*i = *i + 1;
			}
		}
		else
		{
			str[*i] = '0';
			*i = *i + 1;
			while (str[*i] != ' ' && str[*i] != '\0')
			{
				str[*i] = ' ';
				*i = *i + 1;
			}
			*k = *k + 1;
		}
	}
}

void	ft_change_point(t_map *fdf, t_tochca *a, t_tochca *new)
{
	int previous_x;
	int previous_y;
	int ar;

	previous_x = a->x * fdf->scale / 100;
	previous_y = a->y * fdf->scale / 100;
	new->x = (previous_x - previous_y) * cos(fdf->alpha) + fdf->bias_x;
	new->y = -a->z / 100 * fdf->scale_z +
			(previous_x + previous_y) * sin(fdf->alpha) + fdf->bias_yy;
}
