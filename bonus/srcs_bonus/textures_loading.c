/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_loading.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:31:27 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/19 13:00:10 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

void	ft_texture_loading(t_game *game)
{
	char	**path_of_img;
	int		i;

	path_of_img = ft_split(PATH, ' ');
	i = 0;
	while (i < 5)
	{
		if (path_of_img[i] == NULL)
		{
			ft_putendl_fd("Mlx Error during texture loading", 2);
			ft_free(game);
			ft_free_tab(path_of_img);
			exit(0);
		}
		game->mlx.txt[i] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
				path_of_img[i], &game->mlx.xwidth, &game->mlx.yheight);
		i++;
	}
	ft_free_tab(path_of_img);
}

void	ft_bonus_textures_loading(t_game *game)
{
	char	**path_of_img;
	int		i;

	i = 0;
	path_of_img = ft_split(PATH4, ' ');
	while (i < 2)
	{
		if (path_of_img == NULL)
		{
			ft_putendl_fd("Mlx error during textures loading.", 2);
			ft_free(game);
			ft_free_tab(path_of_img);
			exit(0);
		}
		game->mlx.txt_bonus[i] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
				path_of_img[i], &game->mlx.xwidth, &game->mlx.yheight);
		i++;
	}
	ft_free_tab(path_of_img);
}

void	ft_number_loading(t_game *game)
{
	char	**path_of_img;
	char	*path_final;
	int		i;

	path_final = ft_strjoin(PATH2, PATH3, 0);
	i = 0;
	path_of_img = ft_split(path_final, ' ');
	while (i < 10)
	{
		if (path_of_img[i] == NULL)
		{
			ft_putendl_fd("Mlx Error during number loading.", 2);
			ft_free(game);
			free(path_final);
			ft_free_tab(path_of_img);
			exit(0);
		}
		game->mlx.txt_number[i] = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
				path_of_img[i], &game->mlx.xwidth, &game->mlx.yheight);
		i++;
	}
	free(path_final);
	ft_free_tab(path_of_img);
}

void	ft_all_textures(t_game *game)
{
	ft_number_loading(game);
	ft_texture_loading(game);
	ft_bonus_textures_loading(game);
}
