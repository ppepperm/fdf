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
	t_fdf *fdf;

	fdf = (t_fdf*)param;
	if (key == 12 || key == 1738) {
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		rotate_fdf(*fdf, 10, z_rotate);
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256*255);
	}
	if (key == 14 || key == 1749) {
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		rotate_fdf(*fdf, -10, z_rotate);
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256*255);
	}
	if (key == 1 || key == 1731) {
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		rotate_fdf(*fdf, 10, x_rotate);
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256*255);
	}
	if (key == 13 || key == 1753) {
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		rotate_fdf(*fdf, -10, x_rotate);
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256*255);
	}
	if (key == 0 || key == 1734) {
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		rotate_fdf(*fdf, 10, y_rotate);
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256*255);
	}
	if (key == 2 || key == 1751) {
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		rotate_fdf(*fdf, -10, y_rotate);
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256*255);
	}
	if (key ==1739 || key == 15)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		mult_fdf(*fdf, 1.1);
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256*255);
	}
	if (key == 1729 || key == 3)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		mult_fdf(*fdf, 0.9);
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256*255);
	}
	if (key == 65362 || key == 126)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->offset_y -=10;
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256*255);
	}
	if (key == 65364 || key == 125)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->offset_y +=10;
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256*255);
	}
	if (key == 65361 || key == 123)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->offset_x -=10;
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256*255);
	}
	if (key == 65363 || key == 124)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->offset_x +=10;
		put_iso_fdf(*fdf, 255 * 256 * 256 + 256*255);
	}
	if (key == 53 || key == 65307)
		exit (0);
	//ft_putnbr(key);
	return 0;
}

int main(int ac, char **av)
{
	void *mlx_ptr;
	void *win_ptr;
	t_fdf fdf;
	t_point2 size;

	size = init_p2(0,0);
	if (ac)
	{
		get_size(av[1], &size);
		printf("%d %d\n", size.x, size.y);
		get_fdf(av[1], size, &fdf);
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1080, 720, "fdf 21");
	fdf.mlx_ptr = mlx_ptr;
	fdf.win_ptr = win_ptr;
	put_iso_fdf(fdf,255 * 256 * 256 + 255 *256 );
	mlx_hook(win_ptr,2,  1L<<0 ,deal_key, (void*)(&fdf));
	mlx_loop(mlx_ptr);
}

