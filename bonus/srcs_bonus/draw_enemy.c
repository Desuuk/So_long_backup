/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:48:30 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/18 16:57:27 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

void	ft_draw_ennemy(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
		game->mlx.txt_bonus[1], game->enemy_pos[0] * 16,
		game->enemy_pos[1] * 16);
}
