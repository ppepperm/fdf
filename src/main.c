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
#include "../includes/fdf.h"
#include "../includes/libft.h"

int	deal_key(int key, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf*)param;
	rotate1(fdf, key);
	rotate2(fdf, key);
	size_change(fdf, key);
	move(fdf, key);
	projection_change(fdf, key);
	if (key == 53 || key == 65307)
	{
		free_fdf(*fdf);
		exit(0);
	}
	return (0);
}

int	cls(void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf*)param;
	free_fdf(*fdf);
	exit(0);
}

int	main(int ac, char **av)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_fdf		fdf;
	t_point2	size;

	size = init_p2(0, 0);
	if (ac)
	{
		if (!get_size(av[1], &size))
			return (0);
		printf("%d %d\n", size.x, size.y);
		if (!get_fdf(av[1], size, &fdf))
			return (0);
		printf("got_fdf\n");
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1080, 720, "fdf 21");
	fdf.mlx_ptr = mlx_ptr;
	fdf.win_ptr = win_ptr;
	put_iso_fdf(fdf, 255 * 256 * 256 + 255 * 256);
	mlx_hook(win_ptr, 2, 1L << 0, deal_key, (void*)(&fdf));
	mlx_hook(win_ptr, 17, 0L, cls, (void*)(&fdf));
	mlx_loop(mlx_ptr);
	return (0);
}
