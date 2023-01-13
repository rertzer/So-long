/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crab_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:05:21 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/05 10:24:37 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	crab_new(t_sldata *sldata)
{
	t_crab	*newbie;
	t_crab	*last;

	newbie = malloc(sizeof(t_crab));
	if (NULL == newbie)
		game_exit(sldata, MALL);
	newbie->pos.x = sldata->end_pos.x;
	newbie->pos.y = sldata->end_pos.y;
	newbie->prev.x = newbie->pos.x;
	newbie->prev.y = newbie->pos.y;
	newbie->next = NULL;
	last = crab_last(sldata);
	if (last != NULL)
		last->next = newbie;
	else
		sldata->crabs = newbie;
}

t_crab	*crab_last(t_sldata *sldata)
{
	t_crab	*last;

	last = sldata->crabs;
	if (last == NULL)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

void	crab_kill(t_sldata *sldata)
{
	t_crab	*tmp;

	tmp = sldata->crabs;
	while (tmp)
	{
		sldata->crabs = tmp->next;
		free(tmp);
		tmp = sldata->crabs;
	}
}

void	draw_crabs(t_sldata *sldata)
{
	t_crab	*krab;

	krab = sldata->crabs;
	while (krab != NULL)
	{
		if (crab_found(sldata, krab->prev) == 0)
		{
			sl_img_to_win(sldata, \
				img_from_ber_coord(sldata, krab->prev.y, krab->prev.x), \
				krab->prev.x, krab->prev.y);
		}
		sl_img_to_win(sldata, sldata->images[crab], \
			krab->pos.x, krab->pos.y);
		krab = krab->next;
	}
}
