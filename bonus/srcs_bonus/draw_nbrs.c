/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_nbrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:41:19 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/18 16:47:30 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

static int	ft_getsizeof_numbers(t_game *game)
{
	int	tmp;
	int	size;

	size = 0;
	tmp = game->nbr_of_moov;
	while (tmp > 0)
	{
		tmp /= 10;
		size++;
	}
	if (game->nbr_of_moov == 0)
		size = 1;
	if (size > game->x)
	{
		ft_putendl_fd("Map axis X is too small to print number of mooves.", 2);
		ft_free(game);
		exit(0);
	}
	return (size);
}

void	ft_draw_numbers(t_game *game)
{
	int	tmp;
	int	size;

	size = ft_getsizeof_numbers(game) - 1;
	tmp = game->nbr_of_moov;
	while (size >= 0)
	{
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.mlx_win,
			game->mlx.txt_number[(tmp % 10)], size * 16, 0);
		tmp /= 10;
		size--;
	}
}
