/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:01:48 by ppepperm          #+#    #+#             */
/*   Updated: 2019/11/13 14:01:50 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"

int	deal_key(int key, void *param)
{
	t_figure *axis;

	axis = (t_figure*)param;
	if (key == 124) {
		mlx_clear_window(axis->mlx_ptr, axis->win_ptr);
		z_rotate(&(axis->points[1]), -10);
		z_rotate(&(axis->points[2]), -10);
		z_rotate(&(axis->points[3]), -10);
		put_iso_line(axis->mlx_ptr, axis->win_ptr, axis->points[0], axis->points[1], 255);
		put_iso_line(axis->mlx_ptr, axis->win_ptr, axis->points[0], axis->points[2], 255 * 256);
		put_iso_line(axis->mlx_ptr, axis->win_ptr, axis->points[0], axis->points[3], 255 * 256 * 256);
	}
	if (key == 125) {
		mlx_clear_window(axis->mlx_ptr, axis->win_ptr);
		z_rotate(&(axis->points[1]), 10);
		z_rotate(&(axis->points[2]), 10);
		z_rotate(&(axis->points[3]), 10);
		put_iso_line(axis->mlx_ptr, axis->win_ptr, axis->points[0], axis->points[1], 255);
		put_iso_line(axis->mlx_ptr, axis->win_ptr, axis->points[0], axis->points[2], 255 * 256);
		put_iso_line(axis->mlx_ptr, axis->win_ptr, axis->points[0], axis->points[3], 255 * 256 * 256);
	}
	return 0;
}
int main()
{
	t_figure axis;
	void *mlx_ptr;
	void *win_ptr;
	t_point3 p[4];

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 620, 480, "fdf 21");
	p[0] = init_p3(0, 0, 0);
	p[2] = init_p3(0, 100, 0);
	p[1] = init_p3(100, 0, 0);
	p[3] = init_p3(0, 0, 100);
	//y_rotate(&p[1], -90);
	//y_rotate(&p[2], -90);
	//y_rotate(&p[3], -90);
	axis.points = p;
	axis.mlx_ptr = mlx_ptr;
	axis.win_ptr = win_ptr;
	put_iso_line(mlx_ptr, win_ptr, p[0], p[1], 255);
	put_iso_line(mlx_ptr, win_ptr, p[0], p[2], 255 * 256);
	put_iso_line(mlx_ptr, win_ptr, p[0], p[3], 255 * 256 *256);
	mlx_key_hook(win_ptr, deal_key, (void*)(&axis));
	mlx_loop(mlx_ptr);
}

