/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoisint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 21:01:51 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/21 21:01:55 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		atoi_clr(char **start)
{
	int		res;

	res = 0;
	if (**start < '0' || **start > '9')
		return (-1);
	while (**start >= '0' && **start <= '9')
	{
		res = **start - '0' + res * 10;
		(*start)++;
	}
	if (res > 255)
		return (-1);
	return (res);
}

float	nummaker(char **ptr)
{
	float	res;

	res = 0;
	while (**ptr >= '0' && **ptr <= '9')
	{
		res = **ptr - '0' + res * 10;
		(*ptr)++;
	}
	return (res);
}

float	atoi_rt(char **ptr)
{
	float	res;
	float	flag;

	res = 0;
	flag = 1;
	while (**ptr == ' ')
		(*ptr)++;
	if (**ptr == '-' && *(*ptr + 1) > '0' && *(*ptr + 1) <= '9')
	{
		flag = -1;
		(*ptr)++;
	}
	else if (**ptr == '-' && *(*ptr + 1) == '0')
	{
		(*ptr) += 2;
		return (FLT_MAX);
	}
	if (**ptr < '0' || **ptr > '9')
		return (FLT_MIN);
	return (flag * nummaker(ptr));
}
