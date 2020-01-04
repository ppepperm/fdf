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

int check_line(char *line)
{
	while (*line)
	{
		if ((*line > '9' || *line < '0') && *line != '-')
			return (0);
		line++;
	}
	return (1);
}

int	get_size(char *filename, t_point2 *size)
{
	int		fd;
	int		x;
	char	*line;
	char 	**nums;

	if ((fd = open(filename, O_RDWR)) < 0)
		return (0);
	if (!get_next_line(fd, &line))
		return (0);
	*size = init_p2(0, 1);
	nums = ft_strsplit(line, ' ');
	while(nums[size->x])
	{
		free(nums[size->x]);
		size->x++;
	}
	free(nums);
	free(line);
	while(get_next_line(fd, &line))
	{
		x = 0;
		size->y++;
		nums = ft_strsplit(line, ' ');
		while(nums[x])
		{
			free(nums[x]);
			x++;
		}
		free(line);
		free(nums);
		if (x != size->x)
			return (0);
	}
	close(fd);
	return (1);
}

int symbol_check(t_fdf *fdf, char **nums, int x, char *line)
{
	if (!check_line(nums[x]))
	{
		while (nums[x]) {
			free(nums[x]);
			x++;
		}
		free(nums);
		free(line);
		while (fdf->size.y)
			free(fdf->points[--fdf->size.y]);
		free(fdf->points);
		return (0);
	}
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
	fdf->self_sys[0] = init_p3(1,0,0);
	fdf->self_sys[1] = init_p3(0,1,0);
	fdf->self_sys[2] = init_p3(0,0,1);
	fdf->iso = 0;
	fdf->offset_x = 0;
	fdf->offset_y = 0;
	size = init_p2(0,0);
	while (get_next_line(fd, &line))
	{
		nums = ft_strsplit(line, ' ');
		while(nums[size.x])
		{
			if (!symbol_check(fdf,nums, size.x, line))
				return (0);
			fdf->points[size.y][size.x] = init_p3(size.x * 10 - fdf->center.x,\
			size.y * 10  - fdf->center.y, ft_atoi(nums[size.x]) * 2);
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