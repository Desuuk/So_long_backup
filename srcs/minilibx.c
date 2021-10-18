/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:08:07 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/18 14:52:35 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_press(int keypressed, t_game *game)
{
	if (keypressed == 97)
		ft_mooveleft(game);
	if (keypressed == 100)
		ft_mooveright(game);
	if (keypressed == 115)
		ft_moovedown(game);
	if (keypressed == 119)
		ft_mooveup(game);
	if (keypressed == 65307)
		ft_exit_game(game);
	return (keypressed);
}

static void	ft_texture_loading(t_game *game)
{
	char	**path_of_img;
	int		i;

	path_of_img = ft_split(PATH, ' ');
	i = 0;
	while (i < 5)
	{
		if (path_of_img[i] == NULL)
		{
			ft_putendl_fd("Mlx Error", 2);
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

static void	ft_mlx_hooks(t_game *game)
{
	mlx_hook(game->mlx.mlx_win, 2, 1L << 0, ft_key_press, game);
	mlx_hook(game->mlx.mlx_win, 17, 1L << 2, ft_esc_press, game);
	mlx_loop_hook(game->mlx.mlx_ptr, ft_draw_to_map, game);
	mlx_loop(game->mlx.mlx_ptr);
}

static int	ft_error_mlx_init(t_game *game, int error_number)
{
	if (error_number == 1)
	{
		ft_putendl_fd("Mlx Error. Mlx_init has failed.", 2);
		ft_free(game);
		return (0);
	}
	if (error_number == 2)
	{
		ft_putendl_fd("Mlx Error. Mlx_New_Window has failed.", 2);
		ft_free(game);
		return (0);
	}
	if (error_number == 3)
	{
		ft_putendl_fd("Mlx Error. Mlx_New_Image has failed.", 2);
		ft_free(game);
		return (0);
	}
	return (0);
}

int	ft_mlx_game_init(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (game->mlx.mlx_ptr == NULL)
		return (ft_error_mlx_init(game, 1));
	ft_texture_loading(game);
	game->mlx.res_x = (int)(game->x * game->mlx.xwidth);
	game->mlx.res_y = (int)(game->y * game->mlx.yheight);
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx_ptr,
			game->mlx.res_x, game->mlx.res_y, "So_long");
	if (game->mlx.mlx_win == NULL)
		return (ft_error_mlx_init(game, 2));
	game->mlx.mlx_img = mlx_new_image(game->mlx.mlx_ptr, game->mlx.res_x,
			game->mlx.res_y);
	if (game->mlx.mlx_img == NULL)
		return (ft_error_mlx_init(game, 3));
	ft_mlx_hooks(game);
	ft_free(game);
	return (0);
}
