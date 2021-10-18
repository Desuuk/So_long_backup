/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermoove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:08:08 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/13 22:17:37 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit_lost_game(t_game *game)
{
	printf("You lost! try again\n");
	ft_free(game);
	exit(0);
}

void	ft_exit_game(t_game *game)
{
	printf("%d\n", game->nbr_of_moov);
	ft_free(game);
	exit(0);
}

void	ft_enemy_moove(t_game *game)
{
	
	if (game->left < game->right && game->map[game->enemy_pos[1]][game->enemy_pos[0] + 1] != '1')
	{
		if (game->enemy_pos[1] == game->player_position[1] && game->enemy_pos[0] + 1 == game->player_position[0])
		{
			printf("%d\n%d\n%d\n%d\n", game->enemy_pos[1], game->player_position[1], game->enemy_pos[0], game->player_position[0]);
			ft_exit_lost_game(game);
		}
		game->enemy_pos[0] += 1;
		if (game->map[game->enemy_pos[1]][game->enemy_pos[0] + 1] == '1')
		{
			game->left = 1;
			game->right = 0;
		}
	}
	else if (game->left > game->right && game->map[game->enemy_pos[1]][game->enemy_pos[0] - 1] != '1')
	{
		if (game->enemy_pos[1] == game->player_position[1] && game->enemy_pos[0] - 1 == game->player_position[0])
		{
			printf("%d\n%d\n%d\n%d\n", game->enemy_pos[1], game->player_position[1], game->enemy_pos[0], game->player_position[0]);
			ft_exit_lost_game(game);
		}
		game->enemy_pos[0] -= 1;
		if (game->map[game->enemy_pos[1]][game->enemy_pos[0] - 1] == '1')
		{
			game->left = 0;
			game->right = 1;
		}
	}
	else
	{
		ft_putendl_fd("Enemy is unable to moove in this map. Please try again.", 2);
		ft_exit_game(game);
	}
	
}
void	ft_mooveleft(t_game *game)
{
	if (game->map[game->player_position[1]][game->player_position[0] - 1] == '1')
		return ;
	if (game->map[game->player_position[1]][game->player_position[0] - 1] == 'C')
	{
		game->collectible_numbers--;
		game->map[game->player_position[1]][game->player_position[0] - 1] = '0';
	}
	if (game->map[game->player_position[1]][game->player_position[0] - 1] == 'E')
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
	printf("%d\n", game->nbr_of_moov);
}

void	ft_mooveright(t_game *game)
{
	if (game->map[game->player_position[1]][game->player_position[0] + 1] == '1')
		return ;
	if (game->map[game->player_position[1]][game->player_position[0] + 1] == 'C')
	{
		game->collectible_numbers--;
		game->map[game->player_position[1]][game->player_position[0] + 1] = '0';
	}
	if (game->map[game->player_position[1]][game->player_position[0] + 1] == 'E')
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
	printf("%d\n", game->nbr_of_moov);
}


void	ft_moovedown(t_game *game)
{
	if (game->map[game->player_position[1] + 1][game->player_position[0]] == '1')
		return ;
	if (game->map[game->player_position[1] + 1][game->player_position[0]] == 'C')
	{
		game->collectible_numbers--;
		game->map[game->player_position[1] + 1][game->player_position[0]] = '0';
	}
	if (game->map[game->player_position[1] + 1][game->player_position[0]] == 'E')
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
	printf("%d\n", game->nbr_of_moov);
}

void	ft_mooveup(t_game *game)
{
	if (game->map[game->player_position[1] - 1][game->player_position[0]] == '1')
		return ;
	if (game->map[game->player_position[1] - 1][game->player_position[0]] == 'C')
	{
		game->collectible_numbers--;
		game->map[game->player_position[1] - 1][game->player_position[0]] = '0';
	}
	if (game->map[game->player_position[1] - 1][game->player_position[0]] == 'E')
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
	printf("%d\n", game->nbr_of_moov);
}
