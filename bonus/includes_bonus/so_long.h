/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:09:11 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/18 17:03:10 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define PATH "imgs/wa.xpm imgs/gr.xpm imgs/pl.xpm imgs/co.xpm imgs/ex.xpm"
# define PATH2 "imgs/0.xpm imgs/1.xpm imgs/2.xpm imgs/3.xpm imgs/4.xpm "
# define PATH3 "imgs/5.xpm imgs/6.xpm imgs/7.xpm imgs/8.xpm imgs/9.xpm"
# define PATH4 "imgs/co2.xpm imgs/po.xpm"

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
	void    *txt_number[10];
	void	*txt_bonus[2];
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
	int			enemy_isup;
	int			enemy_pos[2];
	int			left;
	int			right;
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
void	ft_enemy_moove(t_game *game);
void	ft_exit_lost_game(t_game *game);
int		ft_is_map_closed(t_game *game, int j);
void	ft_number_loading(t_game *game);
void	ft_bonus_textures_loading(t_game *game);
void	ft_texture_loading(t_game *game);
void	ft_all_textures(t_game *game);
int		ft_draw_to_map(t_game *game);
void	ft_draw_numbers(t_game *game);
void	ft_draw_ennemy(t_game *game);
int		ft_esc_press(t_game *game);

#endif
