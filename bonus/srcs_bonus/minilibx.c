/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:08:07 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/18 16:59:08 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

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
	ft_all_textures(game);
	game->mlx.res_x = (int)(game->x * game->mlx.xwidth);
	game->mlx.res_y = (int)(game->y * game->mlx.yheight);
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx_ptr,
			game->mlx.res_x, game->mlx.res_y, "So_long");
	if (game->mlx.mlx_win == NULL)
		return (ft_error_mlx_init(game, 2));
	game->mlx.mlx_img = mlx_new_image(game->mlx.mlx_ptr,
			game->mlx.res_x, game->mlx.res_y);
	if (game->mlx.mlx_img == NULL)
		return (ft_error_mlx_init(game, 3));
	ft_mlx_hooks(game);
	ft_free(game);
	return (0);
}
