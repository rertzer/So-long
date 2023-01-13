/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:18:26 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/02 15:14:57 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_bermap(t_sldata *sldata, char *filename)
{
	int		fd;

	check_filename(sldata, filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit(sldata, strerror(errno));
	load_bermap(sldata, fd);
	close(fd);
}

void	init_cep(t_cep *cep)
{
	cep->c = 0;
	cep->e = 0;
	cep->p = 0;
}

void	init_data(t_sldata *sldata)
{
	int	i;

	sldata->mlx = NULL;
	sldata->win = NULL;
	sldata->bermap.map = NULL;
	sldata->pirate_dir.x = 0;
	sldata->pirate_dir.y = 0;
	sldata->collectible = 0;
	sldata->crabs = NULL;
	sldata->parrots = NULL;
	sldata->moves = 0;
	sldata->pirate_loops = 0;
	sldata->loops = 0;
	sldata->wings = 0;
	sldata->won = 0;
	sldata->seed = 2000000000;
	sldata->redraw = 1;
	i = -1;
	while (++i < IMG_MAX)
		sldata->images[i] = NULL;
}

void	check_filename(t_sldata *sldata, char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (NULL == ext || ft_strncmp(ext, ".ber", 5))
		error_exit(sldata, BER);
}
