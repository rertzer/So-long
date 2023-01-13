/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crab_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:01:02 by rertzer           #+#    #+#             */
/*   Updated: 2022/12/26 16:16:40 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	crab_count(t_sldata *sldata)
{
	t_crab			*crab;
	unsigned int	nb;

	nb = 0;
	crab = sldata->crabs;
	while (crab)
	{
		nb++;
		crab = crab->next;
	}
	return (nb);
}

void	crab_catch(t_sldata *sldata)
{
	if (crab_found(sldata, sldata->pirate_pos))
		sldata->won = -1;
}

int	crab_found(t_sldata *sldata, t_coord pos)
{
	t_crab	*tmp;
	int		found;

	found = 0;
	tmp = sldata->crabs;
	while (tmp)
	{
		if (tmp->pos.x == pos.x && tmp->pos.y == pos.y)
		{
			found = 1;
			break ;
		}
		tmp = tmp->next;
	}
	return (found);
}
