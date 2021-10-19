/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:57:49 by aloubar           #+#    #+#             */
/*   Updated: 2021/10/19 12:54:22 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

int	ft_check_char(char c)
{
	if (c == 'P' || c == 'E' || c == 'C' || c == '1' || c == '0')
		return (1);
	else
		return (0);
}

void	ft_check_args(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '.' && str[i + 1] == 'b' && str[i + 2] == 'e'
			&& str[i + 3] == 'r' && str[i + 4] == '\0')
			return ;
	}
	ft_putendl_fd("Argument is not valid. Please try again.", 2);
	exit(0);
}
