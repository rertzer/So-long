/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:11:07 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/05 10:04:52 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	positive(int x)
{
	if (x < 0)
		x = 0;
	return (x);
}

size_t	within(int x, size_t max)
{
	size_t	size;

	if (max == 0)
		return (0);
	size = positive(x);
	if (size >= max)
		size = max - 1;
	return (size);
}

int	normalize(int i)
{
	if (i < 0)
		return (-1);
	else if (i > 0)
		return (1);
	else
		return (0);
}

unsigned int	ft_random(unsigned int seed)
{
	static long long	x = 0;
	long long			a;
	long long			m;

	a = 16807;
	m = 2147483647;
	if (x == 0)
		x = seed;
	x = (a * x) % m;
	return ((unsigned int)x);
}
