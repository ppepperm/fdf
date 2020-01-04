/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:20:04 by ppepperm          #+#    #+#             */
/*   Updated: 2020/01/04 16:20:11 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../includes/fdf.h"
#include "../includes/libft.h"

int		check_line(char *line)
{
	while (*line)
	{
		if ((*line > '9' || *line < '0') && *line != '-')
			return (0);
		line++;
	}
	return (1);
}

int		go_through_file(int fd, char *line, t_point2 *size)
{
	int		x;
	char	**nums;

	while (get_next_line(fd, &line))
	{
		x = 0;
		size->y++;
		nums = ft_strsplit(line, ' ');
		while (nums[x])
		{
			free(nums[x]);
			x++;
		}
		free(line);
		free(nums);
		if (x != size->x)
		{
			close(fd);
			return (0);
		}
	}
	return (1);
}

int		get_size(char *filename, t_point2 *size)
{
	int		fd;
	char	*line;
	char	**nums;

	if ((fd = open(filename, O_RDWR)) < 0)
		return (0);
	if (!get_next_line(fd, &line))
		return (0);
	*size = init_p2(0, 1);
	nums = ft_strsplit(line, ' ');
	while (nums[size->x])
	{
		free(nums[size->x]);
		size->x++;
	}
	free(nums);
	free(line);
	if (!go_through_file(fd, line, size))
		return (0);
	close(fd);
	return (1);
}

int		symbol_check(t_fdf *fdf, char **nums, int x, char *line)
{
	if (!check_line(nums[x]))
	{
		while (nums[x])
		{
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

int		get_fdf(char *filename, t_point2 size, t_fdf *fdf)
{
	int			fd;
	char		*line;
	char		**nums;

	fd = open(filename, O_RDWR);
	init_fdf(fdf, size);
	size = init_p2(0, 0);
	while (get_next_line(fd, &line))
	{
		nums = ft_strsplit(line, ' ');
		while (nums[size.x])
		{
			if (!symbol_check(fdf, nums, size.x, line))
				return (0);
			fdf->points[size.y][size.x] = init_p3(size.x * 10 - fdf->center.x,\
			size.y * 10 - fdf->center.y, ft_atoi(nums[size.x]) * 2);
			free(nums[size.x++]);
		}
		free(nums);
		free(line);
		size.x = 0;
		size.y++;
	}
	close(fd);
	return (1);
}
