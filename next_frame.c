/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:53 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/05 10:06:43 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	nf_more_crabs(t_sldata *sldata)
{
	unsigned int	crab_nb;

	crab_nb = crab_count(sldata);
	if (sldata->loops > NEW_CRAB_TIMER * TIMER * crab_nb * crab_nb)
	{
		sldata->loops = 0;
		crab_new(sldata);
		sldata->redraw = 1;
	}
}

static void	nf_move_crabs(t_sldata *sldata)
{
	if (sldata->loops % TIMER == 0)
	{
		crabs_move(sldata);
		sldata->wings = (sldata->wings + 1) % WINGS_MOD;
		sldata->redraw = 1;
	}
}

static void	nf_redraw(t_sldata *sldata)
{
	if (sldata->redraw)
	{
		redraw(sldata);
		sldata->redraw = 0;
		crab_catch(sldata);
		if (sldata->won != 0)
			the_end(sldata);
	}
}

int	next_frame(t_sldata *sldata)
{
	sldata->loops++;
	nf_more_crabs(sldata);
	nf_move_crabs(sldata);
	if (sldata->pirate_loops % TIMER == 0)
		pirate_move(sldata);
	nf_redraw(sldata);
	sldata->pirate_loops++;
	return (1);
}
