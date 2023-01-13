/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crab_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:58:22 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/05 10:00:54 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	crabs_move(t_sldata *sldata)
{
	t_crab	*crab;

	crab = sldata->crabs;
	while (crab)
	{
		crab_move(sldata, crab);
		crab = crab->next;
	}
}

t_coord	crab_next_pos(t_sldata *sldata, t_crab *crab)
{
	t_coord			vect;
	unsigned int	random;

	vect.x = crab->pos.x;
	vect.y = crab->pos.y;
	random = ft_random(sldata->seed);
	if (random % 100 < 20)
	{
		if (random % 2)
			vect.x += (int)(random % 3) - 1;
		else
			vect.y += (int)(random % 3) - 1;
	}
	else if (random % 100 < 80)
		vect = crab_towards_pirate(sldata, crab, random);
	else
	{
		vect.x += crab->pos.x - crab->prev.x;
		vect.y += crab->pos.y - crab->prev.y;
	}
	if (sldata->bermap.map[vect.y][vect.x] == '1')
		vect = crab_next_pos(sldata, crab);
	return (vect);
}

t_coord	crab_towards_pirate(t_sldata *sldata, t_crab *crab, unsigned int random)
{
	t_coord	vect;

	vect.x = crab->pos.x;
	vect.y = crab->pos.y;
	if (random % 2 == 0)
		vect.x += normalize(sldata->pirate_pos.x - crab->pos.x);
	else
		vect.y += normalize(sldata->pirate_pos.y - crab->pos.y);
	return (vect);
}

void	crab_move(t_sldata *sldata, t_crab *crab)
{
	t_coord	vect;
	char	land;

	vect = crab_next_pos(sldata, crab);
	crab->prev.x = crab->pos.x;
	crab->prev.y = crab->pos.y;
	land = sldata->bermap.map[vect.y][vect.x];
	if (land == '1' || crab_found(sldata, vect))
		return ;
	crab->pos.x = vect.x;
	crab->pos.y = vect.y;
}
