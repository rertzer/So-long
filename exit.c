/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:04:42 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/05 10:01:32 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(t_sldata *sldata, char *msg)
{		
	ft_printf("Error\n%s\n", msg);
	clean_exit(sldata, 1);
}

void	clean_exit(t_sldata *sldata, int status)
{
	clean_map(sldata->bermap.map, sldata->bermap.size_y);
	if (sldata->parrots)
		parrot_kill(sldata);
	exit(status);
}

void	clean_map(char **map, size_t size_y)
{
	size_t	i;

	i = -1;
	if (NULL == map)
		return ;
	while (++i < size_y)
	{
		if (NULL == map[i])
			break ;
		free(map[i]);
	}
	free(map);
}
