/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:48:43 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/13 21:19:15 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_is_map_closed(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_get_x_y_len(game);
	while (j < game->x)
	{
		if (game->map[0][j] != '1')
		{
			ft_putendl_fd("Map is not valid. Not closed in First lane", 2);
			return (0);
		}
		j++;
	}
	j--;
	while (i < game->y)
	{
		if (game->map[i][j] != '1')
		{
			ft_putendl_fd("Map is not valid. Not closed in Last column", 2);
			return (0);
		}
			i++;
	}
	i--;
	while (j >= 0)
	{
		if (game->map[i][j] != '1')
		{
			ft_putendl_fd("Map is not valid. Not closed in Last lane", 2);
			return (0);
		}
			j--;
	}
	j++;
	while (i >= 0)
	{
		if (game->map[i][j] != '1')
		{
			ft_putendl_fd("Map is not valid. Not closed in First column", 2);
			return (0);
		}
			i--;
	}
	return (1);
}

int	ft_check_map(t_game *game, int i, int is_doublon_P, int is_doublon_E)
{
	int j;

	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (!ft_check_char(game->map[i][j]))
			{
				ft_putendl_fd("Map is not valid. Use of non-allowed chars.", 2);
				return (0);
			}
			if (game->enemy_isup == 0 && game->map[i][j] == '0')
			{
				game->enemy_isup = 1;
				game->enemy_pos[0] = j;
				game->enemy_pos[1] = i;
			}
			else if (game->map[i][j] == 'P')
			{
				is_doublon_P++;
				game->player_position[0] = j;
				game->player_position[1] = i;
				game->map[i][j] = '0';
			}
			else if (game->map[i][j] == 'E')
				is_doublon_E++;
			else if (game->map[i][j] == 'C')
				game->collectible_numbers++;
		}
	}
	if (is_doublon_P != 1)
	{
		ft_putendl_fd("Map is not valid. PlayerSpawn issues.", 2);
		return (0);
	}
	if (is_doublon_E < 1)
	{
		ft_putendl_fd("Map is not valid. No exit found.", 2);
		return (0);
	}
	if (game->collectible_numbers == 0)
	{
		ft_putendl_fd("Map is not valid. Collectible numbers issues.", 2);
		return (0);
	}
	printf("NBR OF CLLECTIBLES = %d\n", game->collectible_numbers);
	printf("PlayerPOSITIONX = %d\n PlayerPositionY = %d\n", game->player_position[0], game->player_position[1]);
	if (!ft_is_map_closed(game))
		return (0);
	return (1);
}
