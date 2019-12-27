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

void