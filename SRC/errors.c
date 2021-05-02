/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:44:48 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 11:44:54 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_error(void)
{
	write(1, "Error\n", 6);
	write(1, "wrong .rt file\n", 15);
	exit(1);
}

void	malloc_error(void)
{
	write(1, "Error\n", 6);
	write(1, "malloc error\n", 13);
	exit(1);
}

void	com_error(void)
{
	write(1, "Error\n", 6);
	write(1, "command or argument error\n", 26);
	exit(1);
}

void	mlx_error(void)
{
	write(1, "Error\n", 6);
	write(1, "mlx initial or image creating error\n", 36);
	exit(1);
}

void	oc_error(void)
{
	write(1, "Error\n", 6);
	write(1, "an error while the file is opening/closing\n", 44);
	exit(1);
}
