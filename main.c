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

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	t_point3 p[4];

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1080, 720, "fdf 21");
	p[0] = init_p3(0, 0, 0);
	p[1] = init_p3(0, 80, 0);
	p[2] = init_p3(80, 0, 0);
	p[3] = init_p3(0, 0, 80);
	rotate_fig(p, 90, z_rotate, 4);
	rotate_fig(p, 90, y_rotate, 4);
	put_iso_line(mlx_ptr, win_ptr, p[0], p[1], 255);
	put_iso_line(mlx_ptr, win_ptr, p[0], p[2], 255 * 256);
	put_iso_line(mlx_ptr, win_ptr, p[0], p[3], 255 * 256 *256);
	mlx_loop(mlx_ptr);
}

