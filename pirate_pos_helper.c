/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pirate_pos_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:33:06 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/05 10:09:57 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ppos_is_still(t_sldata *sldata)
{
	if (sldata->pirate_dir.x == 0 && sldata->pirate_dir.y == 0)
		return (1);
	return (0);
}

void	ppos_set(t_sldata *sldata, ssize_t x, ssize_t y)
{
	sldata->pirate_dir.x = x;
	sldata->pirate_dir.y = y;
}

int	ppos_direction(t_sldata *sldata)
{
	t_scoord	pdir;
	int			dir;

	pdir = sldata->pirate_dir;
	if (pdir.x == 0 && pdir.y == 1)
		dir = S;
	else if (pdir.x == 0 && pdir.y == -1)
		dir = W;
	else if (pdir.x == 1 && pdir.y == 0)
		dir = D;
	else if (pdir.x == -1 && pdir.y == 0)
		dir = A;
	else
		dir = 0;
	return (dir);
}
