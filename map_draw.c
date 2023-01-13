/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:18:29 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/05 10:19:06 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_sldata *sldata)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < sldata->bermap.size_y)
	{
		j = -1;
		while (++j < sldata->bermap.size_x)
			sl_img_to_win(sldata, img_from_ber_coord(sldata, i, j), j, i);
	}
}

void	load_pic_files(t_sldata *sldata)
{
	int		dump;
	int		i;
	char	*path;

	i = -1;
	while (++i < IMG_MAX)
	{
		path = ft_strjoin(PICTURE_PATH, images_file_name(i));
		if (path == NULL)
			game_exit(sldata, J_MAL);
		sldata->images[i] = mlx_xpm_file_to_image(sldata->mlx, \
				path, &dump, &dump);
		free(path);
		if (sldata->images[i] == NULL)
			game_exit(sldata, PIC_E);
	}
}

char	*images_file_name(int i)
{
	char	*fna[IMG_MAX];

	fna[0] = ZERO_FILE;
	fna[1] = ONE_FILE;
	fna[2] = TWO_FILE;
	fna[3] = THREE_FILE;
	fna[4] = FOUR_FILE;
	fna[5] = FIVE_FILE;
	fna[6] = SIX_FILE;
	fna[7] = SEVEN_FILE;
	fna[8] = EIGHT_FILE;
	fna[9] = NINE_FILE;
	fna[soil] = SOIL_FILE;
	fna[sea] = SEA_FILE;
	fna[end] = END_FILE;
	fna[pirate] = PIRATE_FILE;
	fna[parrot_1] = PARROT_1_FILE;
	fna[parrot_2] = PARROT_2_FILE;
	fna[parrot_3] = PARROT_3_FILE;
	fna[parrot_4] = PARROT_4_FILE;
	fna[crab] = CRAB_FILE;
	return (fna[i]);
}

void	*img_from_ber_coord(t_sldata *sldata, size_t i, size_t j)
{
	char	c;
	int		img_nb;

	c = sldata->bermap.map[i][j];
	if (c == '0')
		img_nb = soil;
	else if (c == '1')
		img_nb = sea;
	else if (c == 'C')
		img_nb = parrot_1;
	else if (c == 'E')
		img_nb = end;
	else if (c == 'P')
		img_nb = soil;
	else
		game_exit(sldata, MAP_E);
	return (sldata->images[img_nb]);
}
