/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                             :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:01:48 by ppepperm          #+#    #+#             */
/*   Updated: 2019/11/13 14:01:50 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"

int	get_size(char *filename, t_point2 *size)
{
	int		fd;
	char	*line;
	char 	**nums;

	if ((fd = open(filename, O_RDWR)) < 0)
		return (0);
	if (!get_next_line(fd, &line))
		return (0);
	size->y = 1;
	size->x = 0;
	nums = ft_strsplit(line, ' ');
	while(nums[size->x])
	{
		free(nums[size->x]);
		size->x++;
	}
	free(nums);
	while(get_next_line(fd, &line))
	{
		size->y++;
		free(line);
	}
	close(fd);
	return (1);
}

int	get_fdf(char *filename, t_point2 size, t_fdf *fdf)
{
	int			fd;
	char		*line;
	char		**nums;

	fdf->size = size;
	fd = open(filename, O_RDWR);
	fdf->points = init_table(size);
	fdf->center = init_p2((size.x - 1) * 5, (size.y - 1) * 5);
	fdf->offset_x = 0;
	fdf->offset_y = 0;
	size = init_p2(0,0);
	while (get_next_line(fd, &line))
	{
		nums = ft_strsplit(line, ' ');
		while(nums[size.x])
		{
			fdf->points[size.y][size.x] = init_p3(size.x * 10 - fdf->center.x,\
			size.y * 10  - fdf->center.y, ft_atoi(nums[size.x])  );
			free(nums[size.x]);
			size.x++;
		}
		free(nums);
		free(line);
		size.x = 0;
		size.y++;
	}
	close(fd);
	return (1);
}