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

typedef struct	s_point2{
	int x;
	int y;
}				t_point2;

typedef struct	s_point3{
	int x;
	int y;
	int z;
}				t_point3;

void	put_line(void *mlx_ptr, void *win_ptr, t_point2 st, t_point2 en, int color);
int		abs(int a);
void put_iso_line(void *mlx_ptr, void *win_ptr, t_point3 st, t_point3 en, int color);

#endif