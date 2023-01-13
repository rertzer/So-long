/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:12:41 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/08 18:12:58 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_counter(t_sldata *sldata)
{
	char	*counter;
	size_t	digits;
	size_t	i;

	counter = ft_itoa(sldata->moves);
	digits = ft_strlen(counter);
	i = -1;
	while (++i < digits)
	{
		if (sldata->bermap.size_x < digits + i)
			break ;
		mlx_put_image_to_window(sldata->mlx, sldata->win, \
				sldata->images[counter[i] - '0'], \
				TILE_SIZE * (sldata->bermap.size_x - digits + i), \
				0);
	}
	free(counter);
}
