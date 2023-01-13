/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:58:54 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/05 10:02:10 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fifo_push(t_sldata *sldata, t_fifo **fifo, t_coord coord)
{
	t_fifo	*new;
	t_fifo	*last;

	new = malloc(sizeof(t_fifo));
	if (new == NULL)
		error_exit(sldata, MALL);
	new->coord.x = coord.x;
	new->coord.y = coord.y;
	new->next = NULL;
	if (*fifo == NULL)
	{
		*fifo = new;
		return ;
	}
	last = *fifo;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

t_coord	fifo_pop(t_fifo **fifo)
{
	t_coord	coord;
	t_fifo	*first;

	first = *fifo;
	coord.x = first->coord.x;
	coord.y = first->coord.y;
	*fifo = first->next;
	free(first);
	return (coord);
}

void	fifo_feed(t_sldata *sldata, t_fifo **fifo, t_bermap *path_map, \
		t_coord pos)
{
	t_coord		coord;

	coord.y = positive(pos.y - 2);
	coord.x = pos.x;
	while (++(coord.y) < pos.y + 2 && coord.y < path_map->size_y)
		fifo_add_neighbor(sldata, fifo, path_map, coord);
	coord.x = positive(pos.x - 2);
	coord.y = pos.y;
	while (++(coord.x) < pos.x + 2 && coord.x < path_map->size_x)
		fifo_add_neighbor(sldata, fifo, path_map, coord);
}

void	fifo_add_neighbor(t_sldata *sldata, t_fifo **fifo, t_bermap *path_map, \
		t_coord coord)
{
	if (path_map->map[coord.y][coord.x] != '1')
	{
		fifo_push(sldata, fifo, coord);
		path_map->map[coord.y][coord.x] = '1';
	}
}
