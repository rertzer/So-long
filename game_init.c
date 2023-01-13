/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:13:44 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/05 10:03:45 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_sldata *sldata)
{
	sldata->mlx = mlx_init();
	if (NULL == sldata->mlx)
		game_exit(sldata, MLX);
	sldata->win = mlx_new_window(sldata->mlx, \
			TILE_SIZE * sldata->bermap.size_x, \
			TILE_SIZE * (sldata->bermap.size_y + 1), "So long");
	if (NULL == sldata->win)
		game_exit(sldata, MLX);
	start_game(sldata);
}

void	start_game(t_sldata *sldata)
{
	mlx_hook(sldata->win, 2, (1L << 0), key_pressed, sldata);
	mlx_hook(sldata->win, 3, (1L << 1), key_released, sldata);
	mlx_loop_hook(sldata->mlx, next_frame, sldata);
	mlx_hook(sldata->win, 17, 0L, the_end, sldata);
	load_pic_files(sldata);
	draw_map(sldata);
	mlx_loop(sldata->mlx);
}

void	game_exit(t_sldata *sldata, char *msg)
{
	int	i;

	i = -1;
	while (++i < IMG_MAX)
		mlx_destroy_image(sldata->mlx, sldata->images[i]);
	mlx_clear_window(sldata->mlx, sldata->win);
	mlx_destroy_window(sldata->mlx, sldata->win);
	mlx_destroy_display(sldata->mlx);
	free(sldata->mlx);
	crab_kill(sldata);
	parrot_kill(sldata);
	if (msg != NULL)
		error_exit(sldata, msg);
	else
		clean_exit(sldata, 0);
}

void	sl_img_to_win(t_sldata *sldata, void *img, size_t x, size_t y)
{
	mlx_put_image_to_window(sldata->mlx, sldata->win, img, \
			TILE_SIZE * x, TILE_SIZE * (y + 1));
}
