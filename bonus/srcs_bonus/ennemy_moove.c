/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_moove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:04:49 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/18 17:10:48 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

static void	ft_is_error(t_game *game)
{
	ft_putendl_fd("Enemy is unable to moove in this map. Please try again.", 2);
	ft_exit_game(game);
}

static void	ft_check_if_lost(t_game *game, int side)
{
	if (side == 0)
	{
		if (game->enemy_pos[1] == game->player_position[1]
			&& game->enemy_pos[0] + 1 == game->player_position[0])
			ft_exit_lost_game(game);
		else
			return ;
	}
	if (side == 1)
	{
		if (game->enemy_pos[1] == game->player_position[1]
			&& game->enemy_pos[0] - 1 == game->player_position[0])
			ft_exit_lost_game(game);
		else
			return ;
	}
}

void	ft_enemy_moove(t_game *game)
{	
	if (game->left < game->right
		&& game->map[game->enemy_pos[1]][game->enemy_pos[0] + 1] != '1')
	{
		ft_check_if_lost(game, 0);
		game->enemy_pos[0] += 1;
		if (game->map[game->enemy_pos[1]][game->enemy_pos[0] + 1] == '1')
		{
			game->left = 1;
			game->right = 0;
		}
	}
	else if (game->left > game->right
		&& game->map[game->enemy_pos[1]][game->enemy_pos[0] - 1] != '1')
	{
		ft_check_if_lost(game, 1);
		game->enemy_pos[0] -= 1;
		if (game->map[game->enemy_pos[1]][game->enemy_pos[0] - 1] == '1')
		{
			game->left = 0;
			game->right = 1;
		}
	}
	else
		ft_is_error(game);
}
