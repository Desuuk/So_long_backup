/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:38:20 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/18 14:54:51 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**ft_parse_and_fill_map(char *buff)
{
	char	**map;
	int		i;

	i = 0;
	map = ft_split(buff, '\n');
	if (map == NULL)
	{
		ft_putendl_fd("Map allocation has failed. Please try again.", 2);
		exit(0);
	}
	while (map[i])
	{
		if (map[i + 1] && ft_strlen(map[i]) != ft_strlen(map[i + 1]))
		{
			ft_putendl_fd("Map is not valid. Not a rectangle.", 2);
			ft_free_tab(map);
			exit(0);
		}
		i++;
	}
	return (map);
}

static void	ft_open_and_read(t_game *game, char **av, char *buff)
{
	int	ret;

	ret = 0;
	game->fd = open(av[1], O_RDONLY);
	if (game->fd <= 0)
	{
		ft_putendl_fd("File opening has failed. Please try again.", 2);
		exit(0);
	}
	ret = read(game->fd, buff, 10000);
	close(game->fd);
	if (ret >= 9999)
	{
		ft_putendl_fd("Read cannot hold more than 10k character!", 2);
		exit(0);
	}
	if (ret <= 0)
	{
		ft_putendl_fd("File reading has failed. Please try again.", 2);
		exit(0);
	}
}

void	ft_parse_map(t_game *game, char **av, char *buff)
{
	ft_check_args(av[1]);
	ft_open_and_read(game, av, buff);
	game->map = ft_parse_and_fill_map(buff);
	if (!ft_check_map(game, -1, 0, 0))
	{
		ft_free_tab(game->map);
		exit(0);
	}
}
