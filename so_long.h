/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:36:03 by rertzer           #+#    #+#             */
/*   Updated: 2023/01/05 10:16:07 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>

/* defines */
# define ESCAPE 65307
# define A	97
# define W 119
# define S 115
# define D 100

# define TILE_SIZE	64
# define IMG_MAX 19
# define NEW_CRAB_TIMER 30
# define TIMER 8000
# define WINGS_MOD 7

# define PICTURE_PATH "pictures/"
# define SOIL_FILE "soil.xpm"
# define SEA_FILE "sea.xpm"
# define END_FILE "cross.xpm"
# define PIRATE_FILE "pirate.xpm"
# define PARROT_1_FILE "parrot_1.xpm"
# define PARROT_2_FILE "parrot_2.xpm"
# define PARROT_3_FILE "parrot_3.xpm"
# define PARROT_4_FILE "parrot_4.xpm"
# define CRAB_FILE "crab.xpm"
# define ZERO_FILE "zero.xpm"
# define ONE_FILE "one.xpm"
# define TWO_FILE "two.xpm"
# define THREE_FILE "three.xpm"
# define FOUR_FILE "four.xpm"
# define FIVE_FILE "five.xpm"
# define SIX_FILE "six.xpm"
# define SEVEN_FILE "seven.xpm"
# define EIGHT_FILE "eight.xpm"
# define NINE_FILE "nine.xpm"

/* Error messages */
# define SO_LONG "So long, and thanks for the game"
# define NO_ARG "A map file is required as argument"
# define BAD_F "Invalid .ber file"
# define GNL_N	"Get next line returned NULL"
# define L_MAL "List malloc error"
# define LINE_S ".ber file : invalid line size"
# define F_MAL "Fifo malloc error"
# define MALL "Malloc error"
# define C_MAL "Crab malloc error"
# define P_MAL "Parrot malloc error"
# define J_MAL "ft_strjoin malloc error"
# define MLX	"Mlx error"
# define WALL "Map invalid, there is a break in the wall"
# define MTS	"Map invalid, too small"
# define MIC	"Map invalid, invalid character"
# define M_CEP "Map invalid, collectible, exit or start position invalid"
# define BER "Not a proper .ber file"
# define I_PATH "No proper path found"
# define PIC_E "Picture error"
# define MAP_E "Map error"

typedef struct s_coord
{
	size_t	x;
	size_t	y;
}	t_coord;

typedef struct s_scoord
{
	ssize_t	x;
	ssize_t	y;
}	t_scoord;

typedef struct s_fifo
{
	t_coord			coord;
	struct s_fifo	*next;
}	t_fifo;

typedef struct s_bermap
{
	size_t	size_x;
	size_t	size_y;
	char	**map;
}	t_bermap;

typedef struct s_crab
{
	t_coord			pos;
	t_coord			prev;
	struct s_crab	*next;
}	t_crab;

typedef struct s_sldata
{
	void			*mlx;
	void			*win;
	void			*images[IMG_MAX];
	t_bermap		bermap;
	t_coord			pirate_pos;
	t_coord			pirate_prev;
	t_scoord		pirate_dir;
	t_coord			end_pos;
	t_crab			*crabs;
	t_fifo			*parrots;
	int				collectible;
	unsigned int	seed;
	unsigned int	moves;
	unsigned int	loops;
	unsigned int	wings;
	unsigned int	pirate_loops;
	int				won;
	int				redraw;
}	t_sldata;

typedef struct s_cep
{
	int	c;
	int	e;
	int	p;
}	t_cep;

/* enumerations */
enum	e_images {soil = 10, sea, end, pirate, parrot_1, parrot_2, parrot_3, \
	parrot_4, crab};

/* clean and quit */
void			error_exit(t_sldata *sldata, char *msg);
void			clean_exit(t_sldata *sldata, int status);
void			clean_map(char **map, size_t size_y);
/* init functions */
void			init_bermap(t_sldata *sldata, char*file_name);
void			init_data(t_sldata *sldata);
void			init_cep(t_cep *cep);
void			check_filename(t_sldata *sldata, char *filename);
/* bermap */
void			error_load_bermap(t_sldata *sldata, t_list **lst, int fd, \
		char *msg);
void			load_bermap(t_sldata *sldata, int fd);
t_list			*load_tmp_bermap(t_sldata *sldata, int fd);
/* check path and map copy */
void			check_path(t_sldata *sldata);
t_bermap		*malloc_bermap(t_sldata *sldata);
t_bermap		*copy_bermap(t_sldata *sldata);
void			malloc_map(t_sldata *sldata, t_bermap *copy);
/* check */
void			check_bermap(t_sldata *sldata);
void			check_wall(t_sldata *sldata);
void			check_content(t_sldata *sldata);
/* cep */
void			cep_count(t_sldata *sldata, t_cep *cep, size_t i, size_t j);
int				count_collectible(t_sldata *sldata, size_t i, size_t j);
int				count_exit(t_sldata *sldata, size_t i, size_t j);
int				count_player(t_sldata *sldata, size_t i, size_t j);
/* fifo functions */
void			fifo_push(t_sldata *sldata, t_fifo **fifo, t_coord coord);
t_coord			fifo_pop(t_fifo **fifo);
void			fifo_feed(t_sldata *sldata, t_fifo **fifo, t_bermap *path_map, \
		t_coord pos);
void			fifo_add_neighbor(t_sldata *sldata, t_fifo **fifo, \
		t_bermap *path_map, t_coord coord);
/* little helpers */
void			nada(void *nothing);
size_t			positive(int x);
size_t			within(int x, size_t max);
int				normalize(int i);
unsigned int	ft_random(unsigned int seed);
/* game_init  */
void			init_game(t_sldata *sldata);
void			start_game(t_sldata *sldata);
void			game_exit(t_sldata *sldata, char *msg);
void			sl_img_to_win(t_sldata *sldata, void *img, size_t x, size_t y);
/* map_draw */
void			load_map(t_sldata *sldata);
void			load_pic_files(t_sldata *sldata);
void			draw_map(t_sldata *sldata);
char			*images_file_name(int i);
void			*img_from_ber_coord(t_sldata *sldata, size_t i, size_t j);
/*game events*/
int				the_end(t_sldata *sldata);
int				key_pressed(int keycode, void *data);
int				key_released(int keycode, void *data);
void			redraw(t_sldata *sldata);
/* next frame */
int				next_frame(t_sldata *sldata);
/* pirate pos helper */
int				ppos_is_still(t_sldata *sldata);
void			ppos_set(t_sldata *sldata, ssize_t x, ssize_t y);
int				ppos_direction(t_sldata *sldata);
/*pirate animate*/
void			draw_pirate(t_sldata *sldata);
void			pirate_move(t_sldata *sldata);
void			pirate_simple_move(t_sldata *sldata);
/* crab init*/
void			crab_new(t_sldata *sldata);
t_crab			*crab_last(t_sldata *sldata);
void			crab_kill(t_sldata *sldata);
void			draw_crabs(t_sldata *sldata);
/* crab helper */
unsigned int	crab_count(t_sldata *sldata);
void			crab_catch(t_sldata *sldata);
int				crab_found(t_sldata *sldata, t_coord pos);
unsigned int	ft_random(unsigned int x);
/* crab moves */
void			crabs_move(t_sldata *sldata);
void			crab_move(t_sldata *sldata, t_crab *crab);
t_coord			crab_next_pos(t_sldata *sldata, t_crab *crab);
t_coord			crab_towards_pirate(t_sldata *sldata, t_crab *crab, \
		unsigned int random);
/* counter */
void			draw_counter(t_sldata *sldata);
/* parrots */
void			add_parrot(t_sldata *sldata, t_coord pos);
void			parrot_kill(t_sldata *sldata);
void			draw_parrots(t_sldata *sldata);
void			*get_parrot_img(t_sldata *sldata);
void			parrot_del_by_pos(t_sldata *sldata, t_coord pos);
#endif
