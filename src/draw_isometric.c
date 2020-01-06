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

#include "../includes/fdf.h"
#include <stdio.h>

t_point2	init_sign(t_point2 st, t_point2 en)
{
	t_point2 sign;

	if (st.x < en.x)
		sign.x = 1;
	else
		sign.x = -1;
	if (st.y < en.y)
		sign.y = 1;
	else
		sign.y = -1;
	return (sign);
}

void		put_line(t_fdf fdf, t_point2 st, t_point2 en, int color)
{
	int			deltax;
	int			deltay;
	t_point2	error;
	t_point2	sign;

	deltax = abs(en.x - st.x);
	deltay = abs(en.y - st.y);
	error.x = deltax - deltay;
	sign = init_sign(st, en);
	mlx_pixel_put(fdf.mlx_ptr, fdf.win_ptr, en.x, en.y, color);
	while (st.x != en.x || st.y != en.y)
	{
		mlx_pixel_put(fdf.mlx_ptr, fdf.win_ptr, st.x, st.y, color);
		error.y = error.x * 2;
		if (error.y > -deltay)
		{
			error.x -= deltay;
			st.x += sign.x;
		}
		if (error.y < deltax)
		{
			error.x += deltax;
			st.y += sign.y;
		}
	}
}

void		put_iso_line(t_fdf fdf, t_point3 st, t_point3 en, int color)
{
	t_point2 iso_st;
	t_point2 iso_en;

	iso_st.x = (st.x - st.y) * cos(0.5235990);
	iso_st.y = (st.x + st.y) * sin(0.5235990) - st.z;
	iso_en.x = (en.x - en.y) * cos(0.5235990);
	iso_en.y = (en.x + en.y) * sin(0.5235990) - en.z;
	iso_st.x += (540 + fdf.offset_x);
	iso_st.y += (360 + fdf.offset_y);
	iso_en.x += (540 + fdf.offset_x);
	iso_en.y += (360 + fdf.offset_y);
	put_line(fdf, iso_st, iso_en, color);
}

void		put_half_iso_line(t_fdf fdf, t_point3 st, t_point3 en, int color)
{
	t_point2 iso_st;
	t_point2 iso_en;

	iso_st.x = (st.x - st.y) * cos(0.1);
	iso_st.y = (st.x + st.y) * sin(0.1) - st.z;
	iso_en.x = (en.x - en.y) * cos(0.1);
	iso_en.y = (en.x + en.y) * sin(0.1) - en.z;
	iso_st.x += (540 + fdf.offset_x);
	iso_st.y += (360 + fdf.offset_y);
	iso_en.x += (540 + fdf.offset_x);
	iso_en.y += (360 + fdf.offset_y);
	put_line(fdf, iso_st, iso_en, color);
}

int			put_iso_fdf(t_fdf fdf, int color)
{
	t_point2	dot;
	t_draw		f;

	if (fdf.iso == 0)
		f = &put_iso_line;
	if (fdf.iso == 1)
		f = &put_half_iso_line;
	dot = init_p2(0, 0);
	while (dot.y < fdf.size.y)
	{
		while (dot.x < fdf.size.x)
		{
			if (dot.x + 1 < fdf.size.x)
				f(fdf, fdf.points[dot.y][dot.x],\
				fdf.points[dot.y][dot.x + 1], color);
			if (dot.y + 1 < fdf.size.y)
				f(fdf, fdf.points[dot.y][dot.x],\
				fdf.points[dot.y + 1][dot.x], color);
			dot.x++;
		}
		dot.x = 0;
		dot.y++;
	}
	return (1);
}
