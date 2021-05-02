/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoisfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 21:01:19 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/21 21:01:24 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float		atoi_f_divider(char **ptr)
{
	float res;

	res = 0;
	(*ptr)++;
	if (**ptr < '0' || **ptr > '9')
		return (-1);
	while (**ptr >= '0' && **ptr <= '9')
	{
		res = **ptr - '0' + res * 10;
		(*ptr)++;
	}
	if (res > LLONG_MAX)
		return (-1);
	return (res);
}

double		atoif_result(char **start, float flag, float res)
{
	char	*tmp;
	double	res2;

	tmp = *start + 1;
	if ((res2 = atoi_f_divider(start)) == -1)
		return (FLT_MIN);
	return (flag * (res + (res2 / pow(10, (*start - tmp)))));
}

double		atof_rt(char **start)
{
	float	res1;
	float	flag;

	flag = 1.0;
	if ((res1 = atoi_rt(start)) == FLT_MIN)
		return (FLT_MIN);
	if (res1 < 0)
	{
		res1 = -res1;
		flag = -1.0;
	}
	else if (res1 == FLT_MAX)
	{
		res1 = 0;
		flag = -1.0;
	}
	if (**start == ',' || **start == ' ')
		return (res1 * flag);
	else if (**start != '.')
		return (FLT_MIN);
	return (atoif_result(start, flag, res1));
}
