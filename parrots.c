/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parrots.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:12:04 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/05 10:21:46 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parrot_kill(t_sldata *sldata)
{
	t_fifo	*tmp;

	tmp = sldata->parrots;
	while (tmp)
	{
		sldata->parrots = tmp->next;
		free(tmp);
		tmp = sldata->parrots;
	}
}

void	draw_parrots(t_sldata *sldata)
{
	t_fifo	*parrot;

	parrot = sldata->parrots;
	while (parrot)
	{
		if (0 == crab_found(sldata, parrot->coord))
		{
			sl_img_to_win(sldata, \
				get_parrot_img(sldata), \
				parrot->coord.x, parrot->coord.y);
		}
		parrot = parrot->next;
	}
}

void	*get_parrot_img(t_sldata *sldata)
{
	int		img_nb[WINGS_MOD];

	img_nb[0] = parrot_1;
	img_nb[1] = parrot_2;
	img_nb[2] = parrot_3;
	img_nb[3] = parrot_4;
	img_nb[4] = parrot_3;
	img_nb[5] = parrot_2;
	img_nb[6] = parrot_1;
	return (sldata->images[img_nb[sldata->wings]]);
}

void	parrot_del_by_pos(t_sldata *sldata, t_coord pos)
{
	t_fifo	*parrot;
	t_fifo	*prev;

	prev = NULL;
	parrot = sldata->parrots;
	while (parrot)
	{
		if (parrot->coord.x == pos.x && parrot->coord.y == pos.y)
		{
			if (prev)
				prev->next = parrot->next;
			else
				sldata->parrots = parrot->next;
			free(parrot);
			break ;
		}
		else
		{
			prev = parrot;
			parrot = parrot->next;
		}
	}
}
