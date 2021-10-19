/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:48:43 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/18 16:29:42 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

static void	ft_ennemy_settings(t_game *game, int i, int j)
{
	game->enemy_isup = 1;
	game->enemy_pos[0] = j;
	game->enemy_pos[1] = i;
}

static int	ft_player_settings(t_game *game, int i, int j)
{
	int	doublon;

	doublon = 1;
	game->player_position[0] = j;
	game->player_position[1] = i;
	game->map[i][j] = '0';
	return (doublon);
}

static int	ft_error_map_checking(int error_number)
{
	if (error_number == 1)
	{
		ft_putendl_fd("Map is not valid. PlayerSpawn issues.", 2);
		return (0);
	}
	if (error_number == 2)
	{
		ft_putendl_fd("Map is not valid. No exit found.", 2);
		return (0);
	}
	if (error_number == 3)
	{
		ft_putendl_fd("Map is not valid. Collectible numbers issues.", 2);
		return (0);
	}
	if (error_number == 4)
	{
		ft_putendl_fd("Map is not valid. Use of non-allowed chars.", 2);
		return (0);
	}
	return (0);
}

static int	ft_check_map2(int is_doublon_P, int is_doublon_E, t_game *game)
{
	int	j;

	j = -1;
	if (is_doublon_P != 1)
		return (ft_error_map_checking(1));
	if (is_doublon_E < 1)
		return (ft_error_map_checking(2));
	if (game->collectible_numbers == 0)
		return (ft_error_map_checking(3));
	if (!ft_is_map_closed(game, j))
		return (0);
	return (1);
}

int	ft_check_map(t_game *game, int i, int is_doublon_P, int is_doublon_E)
{
	int	j;

	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (!ft_check_char(game->map[i][j]))
				return (ft_error_map_checking(4));
			if (game->enemy_isup == 0 && game->map[i][j] == '0')
				ft_ennemy_settings(game, i, j);
			else if (game->map[i][j] == 'P')
				is_doublon_P += ft_player_settings(game, i, j);
			else if (game->map[i][j] == 'E')
				is_doublon_E++;
			else if (game->map[i][j] == 'C')
				game->collectible_numbers++;
		}
	}
	return (ft_check_map2(is_doublon_P, is_doublon_E, game));
}
