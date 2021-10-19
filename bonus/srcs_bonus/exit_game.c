/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:02:04 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/19 12:56:41 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

int	ft_esc_press(t_game *game)
{
	ft_exit_game(game);
	exit(0);
	return (1);
}

void	ft_exit_game(t_game *game)
{
	ft_free(game);
	exit(1);
}

void	ft_exit_lost_game(t_game *game)
{
	printf("You lost. Try again!\n");
	ft_exit_game(game);
}