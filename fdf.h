/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:08:48 by ppepperm          #+#    #+#             */
/*   Updated: 2019/11/13 16:08:51 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include "libft.h"
# include <fcntl.h>

typedef struct	s_point2{
	int			x;
	int			y;
}				t_point2;

typedef struct	s_point3{
	float		x;
	float		y;
	float		z;
}				t_point3;

typedef struct	s_figure{
	void		*mlx_ptr;
	void		*win_ptr;
	t_point3	*points;

}				t_figure;

typedef struct	s_fdf{
	void		*mlx_ptr;
	void		*win_ptr;
	t_point3	**points;
	t_point2	center;
	t_point2	size;
	int 		offset_x;
	int 		offset_y;
}				t_fdf;

void	put_line(void *mlx_ptr, void *win_ptr, t_point2 st, t_point2 en, int color);
int		abs(int a);
void	put_iso_line(t_fdf, t_point3 st, t_point3 en, int color);
int		put_iso_fdf(t_fdf fdf, int color);

t_point2 init_p2(int x, int y);
t_point3 init_p3(float x, float y, float z);
t_point3 **init_table(t_point2 size);

void x_rotate(t_point3 *point, int angle);
void y_rotate(t_point3 *point, int angle);
void z_rotate(t_point3 *point, int angle);
void rotate_fig(t_point3 *arr,int angle, void f(t_point3*, int), int n);
void rotate_fdf(t_fdf fdf,int angle, void f(t_point3*, int));
void	mult_fdf(t_fdf fdf, float mult);

int	get_size(char *filename, t_point2 *size);
int	get_fdf(char *filename, t_point2 size, t_fdf *fdf);

#endif