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

#include "fdf.h"
#include <math.h>
#include <stdio.h>

void x_rotate(t_point3 *point, int angle)
{
	float rad;
	t_point3 save;

	save = init_p3(point->x, point->y, point->z);
	rad = angle * 0.0174533;
	point->y = save.y * cos(rad) + save.z * sin(rad);
	point->z = save.z * cos(rad) - save.y * sin(rad);
}

void y_rotate(t_point3 *point, int angle)
{
	float rad;
	t_point3 save;

	save = init_p3(point->x, point->y, point->z);
	rad = angle * 0.0174533;
	point->x = save.x * cos(rad) + save.z * sin(rad);
	point->z = save.z * cos(rad) - save.x * sin(rad);
}

void z_rotate(t_point3 *point, int angle)
{
	float rad;
	t_point3 save;

	save = init_p3(point->x, point->y, point->z);
	rad = angle * 0.0174533;
	point->x = save.x * cos(rad) - save.y * sin(rad);
	point->y = save.y * cos(rad) + save.x * sin(rad);
	printf("%f\n",sqrt((point->x * point->x + point->y * point->y + point->z * point->z)));
}

void rotate_fig(t_point3 *arr,int angle, void f(t_point3*, int), int n)
{
	while(n)
	{
		f(arr, angle);
		arr++;
		n--;
	}
}