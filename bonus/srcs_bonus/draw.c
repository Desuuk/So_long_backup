/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:39:12 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/18 16:57:02 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

static void	ft_put_wall_n_ground(t_game *game, int i, int j)
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
	else
		return ;
}

static void	ft_draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
		game->mlx.txt[2], game->player_position[0] * 16,
		game->player_position[1] * 16);
}

static void	ft_draw_coin_bonus(t_game *game, int i, int j)
{
	static int	animate = 0;

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

int	ft_draw_to_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->y)
	{
		j = -1;
		while (++j < game->x)
		{
			ft_put_wall_n_ground(game, i, j);
			if (game->map[i][j] == 'C')
				ft_draw_coin_bonus(game, i, j);
			if (game->map[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
					game->mlx.txt[4], j * 16, i * 16);
			}
			ft_draw_ennemy(game);
			ft_draw_player(game);
			ft_draw_numbers(game);
		}
	}
	return (1);
}
