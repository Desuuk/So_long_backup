/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:04:18 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/18 14:45:00 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_is_wall(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
		game->mlx.txt[0], j * 16, i * 16);
}

static void	ft_draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
		game->mlx.txt[2], game->player_position[0] * 16,
		game->player_position[1] * 16);
}

static void	ft_draw_ground(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
		game->mlx.txt[1], j * 16, i * 16);
}

static void	ft_draw_cons(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
		game->mlx.txt[3], j * 16, i * 16);
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
			if (game->map[i][j] == '1')
				ft_is_wall(game, i, j);
			if (game->map[i][j] == '0')
				ft_draw_ground(game, i, j);
			if (game->map[i][j] == 'C')
				ft_draw_cons(game, i, j);
			if (game->map[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
					game->mlx.txt[4], j * 16, i * 16);
			}
			ft_draw_player(game);
		}
	}
	return (1);
}
