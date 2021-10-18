/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_managment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:18:06 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/13 22:22:58 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_tab(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free(t_game *game)
{
	if (game->map)
		ft_free_tab(game->map);
	if (game->mlx.mlx_win)
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.mlx_win);
	if (game->mlx.mlx_ptr)
		free(game->mlx.mlx_ptr);
}
