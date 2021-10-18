/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:09:11 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/18 15:03:10 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define PATH "imgs/wa.xpm imgs/gr.xpm imgs/pl.xpm imgs/co.xpm imgs/ex.xpm"

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_mlx {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	int		xwidth;
	int		yheight;
	void	*txt[5];
	int		res_x;
	int		res_y;
}				t_mlx;

typedef struct s_game
{
	char		**map;
	int			x;
	int			y;
	int			fd;
	int			player_position[2];
	int			collectible_numbers;
	int			nbr_of_moov;
	t_mlx		mlx;
}				t_game;

int		ft_mlx_game_init(t_game *game);
void	ft_parse_map(t_game *game, char **av, char *buff);
int		ft_check_char(char c);
void	ft_free(t_game *game);
int		ft_check_map(t_game *game, int i, int is_doublon_P, int is_doublon_E);
void	ft_get_x_y_len(t_game *game);
void	ft_check_args(char *str);
void	ft_mooveleft(t_game *game);
void	ft_mooveright(t_game *game);
void	ft_moovedown(t_game *game);
void	ft_mooveup(t_game *game);
void	ft_exit_game(t_game *game);
void	ft_free_tab(char **str);
int		ft_is_map_closed(t_game *game, int j);
int		ft_draw_to_map(t_game *game);
int		ft_esc_press(t_game *game);

#endif
