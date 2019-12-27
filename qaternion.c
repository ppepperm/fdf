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

t_qatern inverse(t_qatern base)
{
	float abs;
	t_qatern inverse;

	abs = base.s * base.s + base.i * base.i + base.j * base.j + base.k * base.k;
	inverse.s = base.s/abs;
	inverse.i = -base.i/abs;
	inverse.j = -base.j/abs;
	inverse.k = -base.k/abs;
	return inverse;
}

void	normalize(t_qatern *base)
{
	float abs;
	t_qatern inverse;

	abs = sqtr(base->s * base->s + base->i * base->i + base->j * base->j + base->k * base->k);
	base->s = base->s/abs;
	inverse->i = -base->i/abs;
	inverse->j = -base->j/abs;
	inverse->k = -base->k/abs;
}

void	do_rotor(t_qatern *base, float angle)
{
	angle = angle * 0.0174533;
	base->s *= sin(angle);
	inverse->i *= cos(angle);
	inverse->j *= cos(angle);
	inverse->k *= cos(angle);
}

t_qatern multiply(t_qatern p, t_qatern q)
{
	t_qatern result;

	result.s = p.s * q.s - (p.i*q.i + p.j*q.j + p.k*q.k);
	result.i = p.s*q.i + q.s*p.i + p.j*q.k - p.k*q.j;
	result.j = p.s*q.j + q.s*p.j + p.k*q.i - p.i*q.k;
	result.i = p.s*q.k + q.s*p.k + p.j*q.k - p.k*q.j;
	return (result);
}