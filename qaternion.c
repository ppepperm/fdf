/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qaternion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 18:09:22 by ppepperm          #+#    #+#             */
/*   Updated: 2019/12/27 18:09:26 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

t_qatern init_qatern(float s, float i, float j, float k)
{
	t_qatern tmp;
	tmp.s = s;
	tmp.i = i;
	tmp.j = j;
	tmp.k = k;
	return tmp;
}

void	normalize(t_point3 *vec)
{
	float abs;

	abs = sqrt(vec->x*vec->x + vec->y*vec->y + vec->z*vec->z);
	vec->x /= abs;
	vec->y /= abs;
	vec->z /= abs;
}

t_qatern init_rotor(t_point3 axis, float angle)
{
	t_qatern rotor;

	angle = angle * 0.0174533;
	normalize(&axis);
	rotor.s = cos(angle);
	rotor.i = axis.x * sin(angle);
	rotor.j = axis.y * sin(angle);
	rotor.k = axis.z * sin(angle);
	return (rotor);
}

t_qatern inverse(t_qatern base)
{
	t_qatern inverse;

	inverse.s = base.s;
	inverse.i = -base.i;
	inverse.j = -base.j;
	inverse.k = -base.k;
	return (inverse);
}

t_qatern multiply(t_qatern q, t_qatern p)
{
	t_qatern result;

	result.s = q.s * p.s -q.i * p.i - q.j * p.j - q.k * p.k;
	result.i = q.s * p.i + q.i * p.s + q.j * p.k - q.k * p.j;
	result.j = q.s * p.j + q.j * p.s - q.i * p.k + q.k * p.i;
	result.k = q.s * p.k + q.k * p.s + q.i * p.j - q.j * p.i;
	return result;
}