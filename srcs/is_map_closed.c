/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:41:22 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/18 14:54:14 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_is_first_lane_closed(t_game *game, int j)
{
	if (game->map[0][j] != '1')
	{
		ft_putendl_fd("Map is not valid. Not closed in First lane", 2);
		ft_free_tab(game->map);
		exit(0);
	}
	return (1);
}

static int	ft_is_last_collumn_closed(t_game *game, int i, int j)
{
	if (game->map[i][j] != '1')
	{
		ft_putendl_fd("Map is not valid. Not closed in Last column", 2);
		ft_free_tab(game->map);
		exit(0);
	}
	return (1);
}

static int	ft_is_last_lane_closed(t_game *game, int i, int j)
{
	if (game->map[i][j] != '1')
	{
		ft_putendl_fd("Map is not valid. Not closed in Last lane", 2);
		ft_free_tab(game->map);
		exit(0);
	}
	return (1);
}

static int	ft_is_first_collumn_closed(t_game *game, int i, int j)
{
	if (game->map[i][j] != '1')
	{
		ft_putendl_fd("Map is not valid. Not closed in First column", 2);
		ft_free_tab(game->map);
		exit(0);
	}
	return (1);
}

int	ft_is_map_closed(t_game *game, int j)
{
	int	i;

	i = 0;
	ft_get_x_y_len(game);
	while (++j < game->x)
		ft_is_first_lane_closed(game, j);
	j--;
	while (i < game->y)
	{
		ft_is_last_collumn_closed(game, i, j);
		i++;
	}
	i--;
	while (j >= 0)
	{
		ft_is_last_lane_closed(game, i, j);
		j--;
	}
	j++;
	while (i >= 0)
	{
		ft_is_first_collumn_closed(game, i, j);
		i--;
	}
	return (1);
}
