/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pirate_animate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:32:23 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/05 10:20:46 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pirate_move(t_sldata *sldata)
{
	char		c;
	t_coord		pos;

	pos = sldata->pirate_pos;
	pos.x += sldata->pirate_dir.x;
	pos.y += sldata->pirate_dir.y;
	c = sldata->bermap.map[pos.y][pos.x];
	if (c == '0' || c == 'P')
		pirate_simple_move(sldata);
	if (c == 'C')
	{
		sldata->collectible -= 1;
		sldata->bermap.map[pos.y][pos.x] = '0';
		parrot_del_by_pos(sldata, pos);
		pirate_simple_move(sldata);
	}
	if (c == 'E')
	{
		if (sldata->collectible == 0)
			sldata->won = 1;
		pirate_simple_move(sldata);
	}
}

void	pirate_simple_move(t_sldata *sldata)
{
	sldata->pirate_prev.x = sldata->pirate_pos.x;
	sldata->pirate_prev.y = sldata->pirate_pos.y;
	sldata->pirate_pos.x += sldata->pirate_dir.x;
	sldata->pirate_pos.y += sldata->pirate_dir.y;
	if (0 == ppos_is_still(sldata))
	{
		sldata->moves++;
		sldata->redraw = 1;
		ft_printf("Number of moves: %d\n", sldata->moves);
	}
}

void	draw_pirate(t_sldata *sldata)
{
	if (crab_found(sldata, sldata->pirate_prev) == 0)
	{
		sl_img_to_win(sldata, \
			img_from_ber_coord(sldata, \
			sldata->pirate_prev.y, sldata->pirate_prev.x), \
			sldata->pirate_prev.x, \
			sldata->pirate_prev.y);
	}
	sl_img_to_win(sldata, sldata->images[pirate], \
		sldata->pirate_pos.x, \
		sldata->pirate_pos.y);
}
