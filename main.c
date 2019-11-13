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

int abs(int a)
{
	if (a < 0)
		return (-1 * a);
	return (a);
}

void put_line(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2, int color) {
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;
	//
	int error = deltaX - deltaY;
	//
	mlx_pixel_put(mlx_ptr, win_ptr, x2, y2, color);
	while(x1 != x2 || y1 != y2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, color);
		const int error2 = error * 2;
		//
		if(error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if(error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}

}

int main()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1080, 720, "fdf 21");
	mlx_string_put(mlx_ptr, win_ptr, 400, 400, 0b100000000000000010000000, "SHUE PPSH");
	put_line(mlx_ptr, win_ptr, 40, 50, 75, 105, 0b100000000000000010000000);
	put_line(mlx_ptr, win_ptr, 75, 105, 110, 50, 0b100000000000000010000000);
	put_line(mlx_ptr, win_ptr, 40, 50, 110, 50, 0b100000000000000010000000);
	put_line(mlx_ptr, win_ptr, 40, 90, 75, 35, 0b100000000000000010000000);
	put_line(mlx_ptr, win_ptr, 75, 35, 110, 90, 0b100000000000000010000000);
	put_line(mlx_ptr, win_ptr, 40, 90, 110, 90, 0b100000000000000010000000);

	mlx_loop(mlx_ptr);
}

