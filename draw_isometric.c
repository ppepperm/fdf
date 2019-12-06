/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_izometric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:12:53 by ppepperm          #+#    #+#             */
/*   Updated: 2019/11/13 16:13:00 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int get_color_inc(t_point2 st, t_point2 en, int base)
{
	int delta = 4194303 - base;
	int inc;
	inc = delta/abs(en.x - st.y);
	return (inc);
}

void put_line(void *mlx_ptr, void *win_ptr, t_point2 st, t_point2 en, int color) {
	const int deltaX = abs(en.x - st.x);
	const int deltaY = abs(en.y - st.y);
	const int signX = st.x < en.x ? 1 : -1;
	const int signY = st.y < en.y ? 1 : -1;
	int error = deltaX - deltaY;
	//int inc;

	//inc = get_color_inc(st, en, color);
	mlx_pixel_put(mlx_ptr, win_ptr, en.x, en.y, color);
	while(st.x != en.x || st.y != en.y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, st.x, st.y, color);
		const int error2 = error * 2;
		//
		if(error2 > -deltaY)
		{
			error -= deltaY;
			st.x += signX;
		}
		if(error2 < deltaX)
		{
			error += deltaX;
			st.y += signY;
		}
	}

}

void put_iso_line(t_fdf fdf, t_point3 st, t_point3 en, int color)
{
	t_point2 iso_st;
	t_point2 iso_en;

	iso_st.x = (st.x - st.y)* cos(0.5235990);
	iso_st.y = (st.x + st.y)* sin(0.5235990) - st.z;
	iso_en.x = (en.x - en.y)* cos(0.5235990);
	iso_en.y = (en.x + en.y)* sin(0.5235990) - en.z;
	iso_st.x += (540 + fdf.offset_x);
	iso_st.y += (360 + fdf.offset_y);
	iso_en.x += (540 + fdf.offset_x);
	iso_en.y += (360 + fdf.offset_y);
	put_line(fdf.mlx_ptr,fdf.win_ptr, iso_st, iso_en, color);
}

int	put_iso_fdf(t_fdf fdf, int color)
{
	t_point2 dot;

	dot = init_p2(0,0);
	while(dot.y < fdf.size.y)
	{
		while (dot.x <fdf.size.x)
		{
			if (dot.x + 1 < fdf.size.x)
				put_iso_line(fdf, fdf.points[dot.y][dot.x],\
				fdf.points[dot.y][dot.x + 1], color);
			if (dot.y + 1 < fdf.size.y)
				put_iso_line(fdf,fdf.points[dot.y][dot.x],\
				fdf.points[dot.y + 1][dot.x], color);
			dot.x++;
		}
		dot.x = 0;
		dot.y ++;
	}
	return (1);
}

int abs(int a)
{
	if (a < 0)
		return (-1 * a);
	return (a);
}


