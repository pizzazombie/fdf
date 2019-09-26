/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/30 14:52:33 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	no_args(int i)
{
	if (i == 1)
		ft_printf("\033[33;1;4mUsage\033[0m : ./fdf <filename>\n");
	else if (i == 3)
	{
		ft_printf("\033[31;1;4mAn error occurred\033[0m : wrong map!\n");
		ft_printf("\033[31;1;4mAttention\033[0m :");
		ft_printf("need the same number of data in each line.\n");
	}
	exit(1);
}

void	ft_error_message(void)
{
	perror("\033[31;1;4mAn error occurred\033[0m ");
	ft_printf("\033[33;1;4mUsage\033[0m : ./fdf <filename>\n");
	exit(1);
}

void	ft_put_text(t_ptr *im, t_map *fdf)
{
	int			y;
	void		*mlx;
	void		*win;
	t_tochca	a;
	t_tochca	b;

	y = -10;
	mlx = im->mlx_ptr;
	win = im->win_ptr;
	mlx_string_put(mlx, win, 10, y += 25, 0xffffff, "Hello!");
	mlx_string_put(mlx, win, 10, y += 25, 0xffffff, "This is instruction");
	mlx_string_put(mlx, win, 10, y += 25,
			0xffffff, "how to use this awesome FdF:");
	mlx_string_put(mlx, win, 10, y += 30, 0xffffff, "key:");
	mlx_string_put(mlx, win, 50, y += 30, 0xffffff, "BACKSPACE - clean window");
	mlx_string_put(mlx, win, 50, y += 25, 0xffffff, "F5 - iso projection");
	mlx_string_put(mlx, win, 50, y += 25, 0xffffff, "F6 - parallel projection");
	mlx_string_put(mlx, win, 50, y += 25,
			0xffffff, "left / right - Y-axis rotation");
	mlx_string_put(mlx, win, 50, y += 25,
			0xffffff, "up / down - X-axis rotation");
	a.x = 415;
	a.y = 0;
	a.color = 0xffffff;
	ft_put_text2(im, fdf, &a, &b);
}

void	ft_put_text2(t_ptr *im, t_map *fdf, t_tochca *a, t_tochca *b)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 225;
	mlx = im->mlx_ptr;
	win = im->win_ptr;
	mlx_string_put(mlx, win, 50, y += 25, 0xffffff, "< / > - Z-axis rotation");
	mlx_string_put(mlx, win, 50, y += 25,
			0xffffff, "+ / - IN RIGHT PANEL - zoom in / out");
	mlx_string_put(mlx, win, 50, y += 25, 0xffffff, "C - another color");
	mlx_string_put(mlx, win, 50, y += 25,
			0xffffff, "V - back to original color");
	mlx_string_put(mlx, win, 10, y += 30, 0xffffff, "mouse:");
	mlx_string_put(mlx, win, 50, y += 25,
			0xffffff, "hold left-button - axis rotation");
	mlx_string_put(mlx, win, 50, y += 25, 0xffffff, "mouse wheel up - zoom in");
	mlx_string_put(mlx, win, 50, y += 25,
			0xffffff, "mouse wheel down - zoom out");
	mlx_string_put(mlx, win, 10, y += 30, 0xffffff, "Enjoy it!");
	mlx_string_put(mlx, win, 10, y += 30, 0xffffff, "P.S. try to find key 42");
	b->x = 415;
	b->y = fdf->high * 2 + 50;
	b->color = a->color;
	ft_paint2(*a, *b, im);
}

int		ft_str_dig_help(char *str, int *i, int *flag)
{
	while (str[*i] >= '0' && str[*i] <= '9')
		*i = *i + 1;
	*flag = *flag + 1;
	return (0);
}
