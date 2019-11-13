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
#include <math.h>

void put_line(void *mlx_ptr, void *win_ptr, t_point2 st, t_point2 en, int color) {
	const int deltaX = abs(en.x - st.x);
	const int deltaY = abs(en.y - st.y);
	const int signX = st.x < en.x ? 1 : -1;
	const int signY = st.y < en.y ? 1 : -1;
	//
	int error = deltaX - deltaY;
	//
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
			xt.y += signY;
		}
	}

}

void put_iso_line(void *mlx_ptr, void *win_ptr, t_point3 st, t_point3 en, int color)
{
	t_point2 iso_st;
	t_point2 iso_en;

	iso_st.x = (st.x - st.y)* cos(0.5235990);
	iso_st.y = (st.x + st.y)* sin(0.5235990) - st.z;
	iso_en.x = (en.x - en.y)* cos(0.5235990);
	iso_en.y = (en.x + en.y)* sin(0.5235990) - st.z;
	put_line(mlx_ptr, win_ptr, iso_st, iso_en, color);
}

int abs(int a)
{
	if (a < 0)
		return (-1 * a);
	return (a);
}


