/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:41:26 by truello           #+#    #+#             */
/*   Updated: 2023/09/12 19:52:03 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse_util.h"

t_bool	check_lines(t_char *grid, int nb_lines)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (grid[i])
	{
		if (grid[i] == '\n')
			total++;
		i++;
	}
	return (nb_lines == total);	
}
