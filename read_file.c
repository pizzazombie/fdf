/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/09/05 14:13:11 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_sun_spa(char *str)
{
	int i;
	int k;
	int check;

	i = 0;
	k = 0;
	check = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			ft_str_dig_help(str, &i, &k);
		else if (str[i] == '\0')
			return (k);
		else
		{
			ft_spec(str, &i, &k);
			ft_printf("\033[31;1;4mAttention!\033[0m");
			ft_printf(" Map doesn't consist only numbers and spaces.\n");
		}
	}
	return (k);
}

int		ft_file_size(int fd, char *str, char *argv, t_map *fdf)
{
	int i;
	int k;

	k = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error_message();
	while ((i = get_next_line(fd, &str)) > 0)
	{
		ft_strdel(&str);
		k++;
	}
	ft_strdel(&str);
	close(fd);
	if (i < 0)
		ft_error_message();
	fdf->max_collumn = 0;
	fdf->max_high_positive = 0;
	fdf->max_high_negative = 0;
	return (k);
}

void	ft_put_k_in_mapi(t_map *fdf, int i, int k, char *str)
{
	fdf->mapi[i] = (t_tochca*)malloc(sizeof(t_tochca) * (k + 1));
	fdf->mapi[i][0].x = (k + 1);
	fdf->mapi[i][0].y = (k + 1);
	fdf->mapi[i][0].z = (k + 1);
	fdf->mapi[i][1].z = 1000 * ft_atoi(str);
	fdf->mapi[i][1].y = 1000 * i;
	fdf->mapi[i][1].x = 0;
}

void	ft_mapi_cicle(t_map *fdf, char *str, int i)
{
	int buf;
	int n;
	int j;

	j = 2;
	n = 0;
	while (str[n] != '\0')
	{
		while (str[n] != ' ' && str[n] != '\0')
			n++;
		if (str[n] == '\0')
			break ;
		while (str[n] == ' ' && str[n] != '\0')
			n++;
		fdf->mapi[i][j].z = 1000 * ft_atoi(str + n);
		fdf->mapi[i][j].y = 1000 * i;
		fdf->mapi[i][j].x = 1000 * (j - 1);
		buf = fdf->mapi[i][j].z;
		if (buf > fdf->max_high_positive)
			fdf->max_high_positive = buf;
		if (buf < fdf->max_high_negative)
			fdf->max_high_negative = buf;
		j++;
	}
}

void	ft_read_data(char *argv, t_map *fdf)
{
	int		fd;
	char	*str;
	int		k;
	int		i;

	fdf->mapi = (t_tochca**)malloc(sizeof(t_tochca*)
		* (ft_file_size(fd, str, argv, fdf)));
	fd = open(argv, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &str) > 0)
	{
		k = ft_sun_spa(str);
		ft_put_k_in_mapi(fdf, i, k, str);
		ft_mapi_cicle(fdf, str, i);
		ft_strdel(&str);
		i++;
	}
	ft_strdel(&str);
	close(fd);
	fdf->line = i;
	fdf->max_collumn = k;
	ft_check_valid(fdf);
}
