/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:23:53 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/05 10:02:54 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	the_end(t_sldata *sldata)
{
	if (sldata->won == 1)
		ft_printf("Hourra Long John, you won!\n");
	else if (sldata->won == -1)
		ft_printf("So long, John, you're a looser!\nMay the crabs eat you!\n");
	game_exit(sldata, NULL);
	return (1);
}

int	key_pressed(int keycode, void *data)
{
	static int	old_key = 0;
	t_sldata	*sldata;

	sldata = data;
	sldata->seed = sldata->loops;
	if (keycode != old_key)
	{
		sldata->pirate_loops = 0;
		old_key = keycode;
	}
	if (S == keycode)
		ppos_set(sldata, 0, 1);
	else if (W == keycode)
		ppos_set(sldata, 0, -1);
	else if (D == keycode)
		ppos_set(sldata, 1, 0);
	else if (A == keycode)
		ppos_set(sldata, -1, 0);
	return (1);
}

int	key_released(int keycode, void *data)
{
	t_sldata	*sldata;

	sldata = data;
	if (ESCAPE == keycode)
		game_exit(sldata, NULL);
	if (ppos_direction(sldata) == keycode)
		ppos_set(sldata, 0, 0);
	return (1);
}

void	redraw(t_sldata *sldata)
{
	draw_counter(sldata);
	draw_pirate(sldata);
	draw_crabs(sldata);
	draw_parrots(sldata);
}
