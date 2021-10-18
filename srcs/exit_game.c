/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:20:16 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/18 14:52:59 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_esc_press(t_game *game)
{
	ft_exit_game(game);
	exit(0);
	return (1);
}

void	ft_exit_game(t_game *game)
{
	printf("total number of moves :%d\n", game->nbr_of_moov);
	ft_free(game);
	exit(1);
}
