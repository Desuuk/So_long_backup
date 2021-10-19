/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermoove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:08:08 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/19 12:56:26 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

void	ft_mooveleft(t_game *game)
{
	if (game->map[game->player_position[1]]
		[game->player_position[0] - 1] == '1')
		return ;
	if (game->map[game->player_position[1]]
		[game->player_position[0] - 1] == 'C')
	{
		game->collectible_numbers--;
		game->map[game->player_position[1]]
		[game->player_position[0] - 1] = '0';
	}
	if (game->map[game->player_position[1]]
		[game->player_position[0] - 1] == 'E')
	{
		if (game->collectible_numbers == 0)
		{
			game->nbr_of_moov++;
			ft_exit_game(game);
		}
		else
			return ;
	}
	game->player_position[0] -= 1;
	game->nbr_of_moov++;
}

void	ft_mooveright(t_game *game)
{
	if (game->map[game->player_position[1]]
		[game->player_position[0] + 1] == '1')
		return ;
	if (game->map[game->player_position[1]]
		[game->player_position[0] + 1] == 'C')
	{
		game->collectible_numbers--;
		game->map[game->player_position[1]]
		[game->player_position[0] + 1] = '0';
	}
	if (game->map[game->player_position[1]]
		[game->player_position[0] + 1] == 'E')
	{
		if (game->collectible_numbers == 0)
		{
			game->nbr_of_moov++;
			ft_exit_game(game);
		}
		else
			return ;
	}
	game->player_position[0] += 1;
	game->nbr_of_moov++;
}

void	ft_moovedown(t_game *game)
{
	if (game->map[game->player_position[1] + 1]
		[game->player_position[0]] == '1')
		return ;
	if (game->map[game->player_position[1] + 1]
		[game->player_position[0]] == 'C')
	{
		game->collectible_numbers--;
		game->map[game->player_position[1] + 1]
		[game->player_position[0]] = '0';
	}
	if (game->map[game->player_position[1] + 1]
		[game->player_position[0]] == 'E')
	{
		if (game->collectible_numbers == 0)
		{
			game->nbr_of_moov++;
			ft_exit_game(game);
		}
		else
			return ;
	}
	game->player_position[1] += 1;
	game->nbr_of_moov++;
}

void	ft_mooveup(t_game *game)
{
	if (game->map[game->player_position[1] - 1]
		[game->player_position[0]] == '1')
		return ;
	if (game->map[game->player_position[1] - 1]
		[game->player_position[0]] == 'C')
	{
		game->collectible_numbers--;
		game->map[game->player_position[1] - 1]
		[game->player_position[0]] = '0';
	}
	if (game->map[game->player_position[1] - 1]
		[game->player_position[0]] == 'E')
	{
		if (game->collectible_numbers == 0)
		{
			game->nbr_of_moov++;
			ft_exit_game(game);
		}
		else
			return ;
	}
	game->player_position[1] -= 1;
	game->nbr_of_moov++;
}
