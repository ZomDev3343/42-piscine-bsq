/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:11:55 by truello           #+#    #+#             */
/*   Updated: 2023/09/12 20:09:09 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser2.h"

int	validate_grid(t_char *grid)
{
	int	i;
	int	line_len;

	if (!grid[0])
		return (0);
	line_len = ft_strlen_c(grid, '\n');
	i = line_len;
	while (grid[++i])
	{
		if (ft_strlen_c(&grid[i], '\n') != line_len)
			return (0);
		i += line_len;
	}
	return (line_len);
}

t_bool	map_error(void)
{
	ft_putstr("map error\n");
	return (FALSE);
}

t_bool	unique_info(t_info info)
{
	if (info.empty == info.full || info.empty == info.replace
		|| info.replace == info.full)
		return (TRUE);
	return (FALSE);
}
