/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:30:25 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/04 11:26:10 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wall(t_sldata *sldata)
{
	size_t	i;

	i = -1;
	while (++i < sldata->bermap.size_x)
	{
		if (sldata->bermap.map[0][i] != '1')
			error_exit(sldata, WALL);
		if (sldata->bermap.map[sldata->bermap.size_y - 1][i] != '1')
			error_exit(sldata, WALL);
	}
	i = 0;
	while (++i < sldata->bermap.size_y - 1)
	{
		if (sldata->bermap.map[i][0] != '1')
			error_exit(sldata, WALL);
		if (sldata->bermap.map[i][sldata->bermap.size_x - 1] != '1')
			error_exit(sldata, WALL);
	}
}

void	check_content(t_sldata *sldata)
{
	size_t	i;
	size_t	j;
	t_cep	cep;	

	init_cep(&cep);
	i = 0;
	while (++i < sldata->bermap.size_y - 1)
	{
		j = 0;
		while (++j < sldata->bermap.size_x - 1)
			cep_count(sldata, &cep, i, j);
	}
	if (cep.c == 0 || cep.e != 1 || cep.p != 1)
		error_exit(sldata, M_CEP);
	sldata->collectible = cep.c;
}

void	check_bermap(t_sldata *sldata)
{
	if (sldata->bermap.size_x < 3 || sldata->bermap.size_y < 3)
		error_exit(sldata, MTS);
	check_wall(sldata);
	check_content(sldata);
	check_path(sldata);
}
