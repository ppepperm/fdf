/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:58:46 by ppepperm          #+#    #+#             */
/*   Updated: 2019/12/09 16:59:06 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void global_to_self(t_fdf fdf)
{
	float k;
	t_point2 dot;
	t_point3 s;

	k = 1/(fdf.self_sys[0].x*(fdf.self_sys[1].y*fdf.self_sys[2].z - fdf.self_sys[1].z*fdf.self_sys[2].y)\
	+ fdf.self_sys[1].x*(fdf.self_sys[2].y*fdf.self_sys[0].z - fdf.self_sys[2].z*fdf.self_sys[0].y) +\
	fdf.self_sys[2].x*(fdf.self_sys[0].y*fdf.self_sys[1].z - fdf.self_sys[0].z*fdf.self_sys[1].y));
	dot.y = 0;
	while(dot.y < fdf.size.y)
	{
		dot.x = 0;
		while (dot.x < fdf.size.x)
		{
			s = fdf.points[dot.y][dot.x];
			fdf.points[dot.y][dot.x].x = (s.x*(fdf.self_sys[1].y*fdf.self_sys[2].z - fdf.self_sys[1].z*fdf.self_sys[2].y) + \
			s.y*(fdf.self_sys[2].x*fdf.self_sys[1].z - fdf.self_sys[1].x*fdf.self_sys[2].z) +\
			s.z*(fdf.self_sys[1].x*fdf.self_sys[2].y - fdf.self_sys[1].y*fdf.self_sys[2].x)) * k;
			fdf.points[dot.y][dot.x].y = (s.x*(fdf.self_sys[3].y*fdf.self_sys[0].z - fdf.self_sys[0].y*fdf.self_sys[2].z) + \
			s.y*(fdf.self_sys[0].x*fdf.self_sys[2].z - fdf.self_sys[2].x*fdf.self_sys[0].z) +\
			s.z*(fdf.self_sys[2].x*fdf.self_sys[0].y - fdf.self_sys[2].y*fdf.self_sys[0].x)) * k;
			fdf.points[dot.y][dot.x].z = (s.x*(fdf.self_sys[0].y*fdf.self_sys[1].z - fdf.self_sys[1].y*fdf.self_sys[0].z) + \
			s.y*(fdf.self_sys[1].x*fdf.self_sys[0].z - fdf.self_sys[0].x*fdf.self_sys[1].z) +\
			s.z*(fdf.self_sys[0].x*fdf.self_sys[1].y - fdf.self_sys[1].y*fdf.self_sys[0].x)) * k;
			dot.x++;
		}
		dot.y++;
	}
}

void self_to_global(t_fdf fdf)
{
	t_point2 dot;
	t_point3 s;

	dot.y = 0;
	while(dot.y < fdf.size.y)
	{
		dot.x = 0;
		while (dot.x < fdf.size.x)
		{
			s = fdf.points[dot.y][dot.x];
			fdf.points[dot.y][dot.x].x = s.x * fdf.self_sys[0].x + s.y * fdf.self_sys[1].x + s.z * fdf.self_sys[2].x;
			fdf.points[dot.y][dot.x].x = s.x * fdf.self_sys[0].y + s.y * fdf.self_sys[1].y + s.z * fdf.self_sys[2].y;
			fdf.points[dot.y][dot.x].x = s.x * fdf.self_sys[0].z + s.y * fdf.self_sys[1].z + s.z * fdf.self_sys[2].z;
			dot.x++;
		}
		dot.y++;
	}
}

void increase_z(t_fdf fdf)
{
	t_point2 dot;

	self_to_global(fdf);
	dot.y = 0;
	while(dot.y < fdf.size.y)
	{
		dot.x = 0;
		while (dot.x < fdf.size.x)
		{
			fdf.points[dot.y][dot.x].z *= 1.1;
			dot.x++;
		}
		dot.y++;
	}
	global_to_self(fdf);
}