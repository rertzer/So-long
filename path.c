/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:14:35 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/05 10:07:58 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(t_sldata *sldata)
{
	t_fifo		*fifo;
	t_coord		pos;
	t_bermap	*path_map;
	int			coll;

	fifo = NULL;
	path_map = copy_bermap(sldata);
	fifo_push(sldata, &fifo, sldata->pirate_pos);
	path_map->map[sldata->pirate_pos.y][sldata->pirate_pos.x] = 1;
	coll = sldata->collectible + 1;
	while (fifo != NULL)
	{
		pos = fifo_pop(&fifo);
		if (sldata->bermap.map[pos.y][pos.x] == 'C' \
				|| sldata->bermap.map[pos.y][pos.x] == 'E')
			coll--;
		fifo_feed(sldata, &fifo, path_map, pos);
	}
	clean_map(path_map->map, path_map->size_y);
	free(path_map);
	if (coll != 0)
		error_exit(sldata, I_PATH);
}

t_bermap	*copy_bermap(t_sldata *sldata)
{
	t_bermap	*copy;
	size_t		i;
	size_t		j;

	copy = malloc_bermap(sldata);
	i = -1;
	while (++i < copy->size_y)
	{
		j = -1;
		while (++j < copy->size_x)
			copy->map[i][j] = sldata->bermap.map[i][j];
	}
	return (copy);
}

t_bermap	*malloc_bermap(t_sldata *sldata)
{
	t_bermap	*copy;

	copy = malloc(sizeof(t_bermap));
	if (copy == NULL)
		error_exit(sldata, MALL);
	copy->size_x = sldata->bermap.size_x;
	copy->size_y = sldata->bermap.size_y;
	malloc_map(sldata, copy);
	return (copy);
}

void	malloc_map(t_sldata *sldata, t_bermap *copy)
{
	size_t	i;

	copy->map = malloc(sizeof(char *) * copy->size_y);
	if (copy->map == NULL)
	{
		free(copy);
		error_exit(sldata, MALL);
	}
	i = -1;
	while (++i < copy->size_y)
	{
		copy->map[i] = malloc(sizeof(char) * copy->size_x);
		if (copy->map[i] == NULL)
		{
			clean_map(copy->map, i);
			free(copy);
			error_exit(sldata, MALL);
		}
	}
}
