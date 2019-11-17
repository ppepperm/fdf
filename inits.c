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

#include "fdf.h"

t_point2 init_p2(int x, int y)
{
	t_point2 tmp;

	tmp.x = x;
	tmp.y = y;
	return (tmp);
}

t_point3 init_p3(float x, float y, float z)
{
	t_point3 tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return (tmp);
}