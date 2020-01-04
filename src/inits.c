/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:34:27 by ppepperm          #+#    #+#             */
/*   Updated: 2019/11/13 16:34:29 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point2	init_p2(int x, int y)
{
	t_point2 tmp;

	tmp.x = x;
	tmp.y = y;
	return (tmp);
}

t_point3	init_p3(float x, float y, float z)
{
	t_point3 tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return (tmp);
}

t_point3	**init_table(t_point2 size)
{
	int			i;
	t_point3	**table;

	i = 0;
	table = (t_point3**)malloc(sizeof(t_point3*) * size.y);
	while (i < size.y)
	{
		table[i] = (t_point3*)malloc(sizeof(t_point3) * size.x);
		i++;
	}
	return (table);
}

int			free_fdf(t_fdf fdf)
{
	mlx_destroy_window(fdf.mlx_ptr,fdf.win_ptr);
	free(fdf.mlx_ptr);
	while (fdf.size.y)
		free(fdf.points[--fdf.size.y]);
	free(fdf.points);
	return (1);
}

void		init_fdf(t_fdf *fdf, t_point2 size)
{
	fdf->size = size;
	fdf->points = init_table(size);
	fdf->center = init_p2((size.x - 1) * 5, (size.y - 1) * 5);
	fdf->self_sys[0] = init_p3(1, 0, 0);
	fdf->self_sys[1] = init_p3(0, 1, 0);
	fdf->self_sys[2] = init_p3(0, 0, 1);
	fdf->iso = 0;
	fdf->offset_x = 0;
	fdf->offset_y = 0;
}
