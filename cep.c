/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cep.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:26:23 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/05 09:58:14 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cep_count(t_sldata *sldata, t_cep *cep, size_t i, size_t j)
{
	char	c;

	c = sldata->bermap.map[i][j];
	if (c == 'C')
		cep->c += count_collectible(sldata, i, j);
	else if (c == 'E')
		cep->e += count_exit(sldata, i, j);
	else if (c == 'P')
		cep->p += count_player(sldata, i, j);
	else if (c != '0' && c != '1')
		error_exit(sldata, MIC);
}

int	count_collectible(t_sldata *sldata, size_t i, size_t j)
{
	t_coord	pos;

	pos.x = j;
	pos.y = i;
	fifo_push(sldata, &(sldata->parrots), pos);
	return (1);
}

int	count_exit(t_sldata *sldata, size_t i, size_t j)
{
	sldata->end_pos.x = j;
	sldata->end_pos.y = i;
	return (1);
}

int	count_player(t_sldata *sldata, size_t i, size_t j)
{
	sldata->pirate_pos.x = j;
	sldata->pirate_pos.y = i;
	sldata->pirate_prev.x = j;
	sldata->pirate_prev.y = i;
	return (1);
}
