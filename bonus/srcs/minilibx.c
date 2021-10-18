/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:08:07 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/15 21:02:48 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int ft_esc_press(t_game *game)
{
	ft_exit_game(game);
	exit(0);
	return (1);
}

static int	ft_key_press(int keypressed, t_game *game)
{
	
	if (keypressed == 97)
	{
		ft_mooveleft(game);
		ft_enemy_moove(game);
	}
	if (keypressed == 100)
	{
		ft_mooveright(game);
		ft_enemy_moove(game);
	}
	if (keypressed == 115)
	{
		ft_moovedown(game);
		ft_enemy_moove(game);
	}
	if (keypressed == 119)
	{
		ft_mooveup(game);
		ft_enemy_moove(game);
	}
	if (keypressed == 65307)
		ft_exit_game(game);
	return (keypressed);
}

static int ft_getsizeof_numbers(t_game *game)
{
	int tmp;
	int size;
	
	size = 0;
	tmp = game->nbr_of_moov;
	while (tmp > 0)
	{
		tmp /= 10;
		size++;
	}
	if (game->nbr_of_moov == 0)
		size = 1;
	if (size > game->x)
	{
		ft_putendl_fd("Map axis X is too small to print number of mooves.", 2);
		ft_free(game);
		exit(0);
	}
	return (size);
}

static void ft_draw_numbers(t_game *game)
{
	int tmp;
	int size;

	size = ft_getsizeof_numbers(game) - 1;
	tmp = game->nbr_of_moov;
	while (size >= 0)
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
			game->mlx.txt_number[(tmp % 10)], size * 16, 0);
		tmp /= 10;
		size--;
	}
}

static void ft_draw_coin_bonus(t_game *game, int i, int j)
{
	static int animate = 0;

	if (animate < 50)
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
				game->mlx.txt[3], j * 16, i * 16);
		animate++;
	}	
	else if (animate >= 50 && animate < 100)
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
				game->mlx.txt_bonus[0], j * 16, i * 16);
		animate++;
	}
	if (animate >= 100)
		animate = 0;
}

static int	ft_color(t_game *game)
{
	int i;
	int j;

	i = -1;
	while (++i < game->y)
	{
		j = -1;
		while (++j < game->x)
		{
			if (game->map[i][j] == '1')
			{
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
				game->mlx.txt[0], j * 16, i * 16);
			}
			if (game->map[i][j] == '0')
			{
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
				game->mlx.txt[1], j * 16, i * 16);
			}
			if (game->map[i][j] == 'C')
			{
				ft_draw_coin_bonus(game, i, j);
			}
			if (game->map[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
				game->mlx.txt[4], j * 16, i * 16);
			}
			mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
			game->mlx.txt_bonus[1], game->enemy_pos[0] * 16, game->enemy_pos[1] * 16);
			mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
			game->mlx.txt[2], game->player_position[0] * 16,
			game->player_position[1] * 16);
			ft_draw_numbers(game);
		}
	}
	return (1);
}

static void	ft_texture_loading(t_game *game)
{
	char **path_of_img;
	int i;

	path_of_img = ft_split(PATH, ' ');
	i = 0;
	while (i < 5)
	{
		if (path_of_img[i] == NULL)
		{
			ft_putendl_fd("Mlx Error during texture loading", 2);
			ft_free(game);
			ft_free_tab(path_of_img);
			exit(0);
		}
		game->mlx.txt[i] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			path_of_img[i], &game->mlx.xwidth, &game->mlx.yheight);
		i++;
	}
	ft_free_tab(path_of_img);
}

static void ft_bonus_textures_loading(t_game *game)
{
	char **path_of_img;
	int i;

	i = 0;
	path_of_img = ft_split(PATH4, ' ');
	while (i < 2)
	{
		if (path_of_img == NULL)
		{
			ft_putendl_fd("Mlx error during textures loading.", 2);
			ft_free(game);
			ft_free_tab(path_of_img);
			exit(0);
		}
		game->mlx.txt_bonus[i] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			path_of_img[i], &game->mlx.xwidth, &game->mlx.yheight);
		i++;
	}
	ft_free_tab(path_of_img);
}

static void	ft_number_loading(t_game *game)
{
	char **path_of_img;
	char *Path_final;
	int i;

	Path_final = ft_strjoin(PATH2, PATH3);
	printf("%s\n", Path_final);
	i = 0;
	path_of_img = ft_split(Path_final, ' ');
	while (i < 10)
	{
		if (path_of_img[i] == NULL)
		{
			ft_putendl_fd("Mlx Error during number loading.", 2);
			ft_free(game);
			free(Path_final);
			ft_free_tab(path_of_img);
			exit(0);
		}
		game->mlx.txt_number[i] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			path_of_img[i], &game->mlx.xwidth, &game->mlx.yheight);
		i++;
	}
	free(Path_final);
	ft_free_tab(path_of_img);
}

int minilib(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (game->mlx.mlx_ptr == NULL)
	{
		ft_putendl_fd("Mlx Error.", 2);
		ft_free(game);
		return (0);
	}
	ft_texture_loading(game);
	ft_number_loading(game);
	ft_bonus_textures_loading(game);
	game->mlx.res_x = (int)(game->x * game->mlx.xwidth);
	game->mlx.res_y = (int)(game->y * game->mlx.yheight);
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx_ptr, game->mlx.res_x, game->mlx.res_y, "So_long");
	if (game->mlx.mlx_win == NULL)
	{
		ft_putendl_fd("Mlx Errir.", 2);
		return (0);
	}
	game->mlx.mlx_img = mlx_new_image(game->mlx.mlx_ptr, game->mlx.res_x, game->mlx.res_y);
	if (game->mlx.mlx_img == NULL)
	{
		ft_putendl_fd("Mlx Erryr.", 2);
		return (0);
	}
	mlx_hook(game->mlx.mlx_win, 2, 1L << 0, ft_key_press, game);
	mlx_hook(game->mlx.mlx_win, 17, 1L << 2, ft_esc_press, game);
	mlx_loop_hook(game->mlx.mlx_ptr, ft_color, game);
	mlx_loop(game->mlx.mlx_ptr);
	return (0);
}
