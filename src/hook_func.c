/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 14:27:17 by ppepperm          #+#    #+#             */
/*   Updated: 2020/01/04 14:27:19 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate1(t_fdf *fdf, int key)
{
	if (key == 12 || key == 1738)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		rotate_fdf(*fdf, 5, z_rotate);
		z_rotate(&(fdf->self_sys[0]), 5, *fdf);
		z_rotate(&(fdf->self_sys[1]), 5, *fdf);
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256 * 255);
	}
	if (key == 14 || key == 1749)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		rotate_fdf(*fdf, -5, z_rotate);
		z_rotate(&(fdf->self_sys[0]), -5, *fdf);
		z_rotate(&(fdf->self_sys[1]), -5, *fdf);
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256 * 255);
	}
	if (key == 1 || key == 1731)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		rotate_fdf(*fdf, 5, x_rotate);
		x_rotate(&(fdf->self_sys[1]), 5, *fdf);
		x_rotate(&(fdf->self_sys[2]), 5, *fdf);
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256 * 255);
	}
}

void	rotate2(t_fdf *fdf, int key)
{
	if (key == 13 || key == 1753)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		rotate_fdf(*fdf, -5, x_rotate);
		x_rotate(&(fdf->self_sys[1]), -5, *fdf);
		x_rotate(&(fdf->self_sys[2]), -5, *fdf);
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256 * 255);
	}
	if (key == 0 || key == 1734)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		rotate_fdf(*fdf, 5, y_rotate);
		y_rotate(&(fdf->self_sys[0]), 5, *fdf);
		y_rotate(&(fdf->self_sys[2]), 5, *fdf);
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256 * 255);
	}
	if (key == 2 || key == 1751)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		rotate_fdf(*fdf, -5, y_rotate);
		y_rotate(&(fdf->self_sys[0]), -5, *fdf);
		y_rotate(&(fdf->self_sys[2]), -5, *fdf);
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256 * 255);
	}
}

void	size_change(t_fdf *fdf, int key)
{
	if (key == 1739 || key == 15)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		mult_fdf(*fdf, 1.1);
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256 * 255);
	}
	if (key == 1729 || key == 3)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		mult_fdf(*fdf, 0.9);
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256 * 255);
	}
}

void	move(t_fdf *fdf, int key)
{
	if (key == 65362 || key == 126)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->offset_y -= 10;
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256 * 255);
	}
	if (key == 65364 || key == 125)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->offset_y += 10;
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256 * 255);
	}
	if (key == 65361 || key == 123)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->offset_x -= 10;
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256 * 255);
	}
	if (key == 65363 || key == 124)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->offset_x += 10;
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256 * 255);
	}
}

void	projection_change(t_fdf *fdf, int key)
{
	if (key == 40)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		if (fdf->iso == 1)
			fdf->iso = 0;
		else
			fdf->iso = 1;
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256 * 255);
	}
}
