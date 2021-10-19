/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:20:16 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/18 17:04:43 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit_game(t_game *game)
{
	printf("Total numbers of mooves : %d\n", game->nbr_of_moov);
	ft_free(game);
	exit(1);
}

int	ft_esc_press(t_game *game)
{
	ft_exit_game(game);
	return (1);
}

