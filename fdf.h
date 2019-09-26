/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/30 14:47:33 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_tochka
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_tochca;

typedef struct	s_ptr
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_ptr;

typedef struct	s_brezenham
{
	int			aa;
	int			bb;
	int			signx;
	int			signy;
	int			f;
	double		step;
	int			count;
}				t_brezenham;

typedef struct	s_map
{
	char		***map;
	t_tochca	**mapi;
	int			max_collumn;
	int			line;
	int			max_high_positive;
	int			max_high_negative;
	double		scale;
	double		scale_default;
	double		scale_z;
	int			bias_x;
	int			bias_yy;
	double		alpha;
	double		rotate_x;
	double		rotate_y;
	double		rotate_z;
	int			wind;
	int			high;
	int			mouse_x;
	int			mouse_y;
	int			mouse_press;
	int			top;
	int			bottom;
}				t_map;

typedef struct	s_all
{
	t_map		*fdf;
	t_ptr		*im;
}				t_all;

void			ft_read_data(char *argv, t_map *fdf);
void			ft_change_center(t_map *fdf);
void			ft_print(t_map *fdf);
void			ft_paint2(t_tochca a, t_tochca b, t_ptr *im);
void			ft_clean(t_map *fdf, int n);
int				deal_key(int key, void *param);
void			ft_open_win(t_ptr *im, t_map *fdf);
int				mouse_press(int button, int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);
void			ft_paint_map(t_ptr *im, t_map *fdf);
void			ft_x_rotate(t_map *fdf);
void			ft_paint_line(t_tochca *a_m,
		t_tochca *b_m, t_map *fdf, t_ptr *im);
void			ft_paint2_count(t_tochca a, t_tochca b, t_brezenham *br);
void			ft_paint33(t_tochca a, t_tochca b, t_ptr *im, int color);
void			ft_change_map(t_ptr *im, t_map *fdf);
void			ft_change_point(t_map *fdf, t_tochca *a, t_tochca *new);
void			ft_do_brezen(t_brezenham *br, t_tochca *a, t_tochca *b);
int				ft_do_paint(int l1, int l2, int *f);
t_tochca		ft_do_tochka(t_map *fdf, int ii, int jj);
void			ft_put_text2(t_ptr *im, t_map *fdf, t_tochca *a, t_tochca *b);
void			ft_put_text(t_ptr *im, t_map *fdf);
void			ft_bias(t_map *fdf);
void			rotate_x(int *y, int *z, t_map *fdf);
void			rotate_y(int *x, int *z, t_map *fdf);
void			rotate_z(int *y, int *x, t_map *fdf);

void			ft_show(t_ptr *im, t_map *fdf, double alpha);
void			ft_default(t_map *fdf);
void			ft_error_message(void);
void			no_args(int i);
int				ft_str_dig_help(char *str, int *i, int *flag);
void			ft_check_valid(t_map *fdf);
void			ft_surprise(t_all *all);
void			color_keys(t_all *all, int key);
void			ft_spec(char *str, int *i, int *k);

#endif
