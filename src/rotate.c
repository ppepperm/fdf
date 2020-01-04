/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:04:55 by ppepperm          #+#    #+#             */
/*   Updated: 2019/11/13 17:05:10 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>
#include <stdio.h>

void	x_rotate(t_point3 *point, float angle, t_fdf fdf)
{
	t_qatern dot;
	t_qatern rotor;

	rotor = init_rotor(fdf.self_sys[0], angle / 2);
	dot = init_qatern(0, point->x, point->y, point->z);
	dot = multiply(rotor, dot);
	dot = multiply(dot, inverse(rotor));
	point->x = dot.i;
	point->y = dot.j;
	point->z = dot.k;
}

void	y_rotate(t_point3 *point, float angle, t_fdf fdf)
{
	t_qatern dot;
	t_qatern rotor;

	rotor = init_rotor(fdf.self_sys[1], angle / 2);
	dot = init_qatern(0, point->x, point->y, point->z);
	dot = multiply(rotor, dot);
	dot = multiply(dot, inverse(rotor));
	point->x = dot.i;
	point->y = dot.j;
	point->z = dot.k;
}

void	z_rotate(t_point3 *point, float angle, t_fdf fdf)
{
	t_qatern dot;
	t_qatern rotor;

	rotor = init_rotor(fdf.self_sys[2], angle / 2);
	dot = init_qatern(0, point->x, point->y, point->z);
	dot = multiply(rotor, dot);
	dot = multiply(dot, inverse(rotor));
	point->x = dot.i;
	point->y = dot.j;
	point->z = dot.k;
}

void	rotate_fdf(t_fdf fdf, int angle, void f(t_point3*, float, t_fdf))
{
	int i;
	int j;

	i = 0;
	while (i < fdf.size.y)
	{
		j = 0;
		while (j < fdf.size.x)
		{
			f(&(fdf.points[i][j]), angle, fdf);
			j++;
		}
		i++;
	}
}

void	mult_fdf(t_fdf fdf, float mult)
{
	int i;
	int j;

	i = 0;
	while (i < fdf.size.y)
	{
		j = 0;
		while (j < fdf.size.x)
		{
			fdf.points[i][j].x *= mult;
			fdf.points[i][j].y *= mult;
			fdf.points[i][j].z *= mult;
			j++;
		}
		i++;
	}
}
