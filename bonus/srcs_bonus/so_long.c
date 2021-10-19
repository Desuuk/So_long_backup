/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:05:18 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/19 12:54:58 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

static void	ft_init(t_game *game)
{
	game->collectible_numbers = 0;
	game->x = 0;
	game->y = 0;
	game->nbr_of_moov = 0;
	game->left = 0;
	game->right = 1;
}

void	ft_get_x_y_len(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i][j])
	{
		j++;
	}
	game->x = j;
	while (game->map[i])
	{
		i++;
	}
	game->y = i;
}

int	main(int ac, char **av)
{
	t_game	game;
	char	buff[10000];

	ft_bzero(buff, 10000);
	ft_init(&game);
	if (ac == 2)
	{
		ft_parse_map(&game, av, buff);
		if (!ft_mlx_game_init(&game))
			return (0);
	}
	else
		ft_putendl_fd("Numbers of args is not valid. Please try again", 2);
	return (0);
}
