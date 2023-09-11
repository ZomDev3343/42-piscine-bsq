/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:41:25 by truello           #+#    #+#             */
/*   Updated: 2023/09/11 15:44:00 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"
#include "../includes/parser.h"
#include "../includes/print_helper.h"
#include <stdio.h>

/* Take the map from the standard input and resolves it */
t_bool	resolve_map_stdin()
{

	return (TRUE);
}

/* Resolves the map from every parameters the user gives */
t_bool	resolve_map(char *map_file)
{
	t_char	*grid = get_grid(map_file);
	t_info infos;

	if (!grid)
		return (FALSE);
	if (!parse_infos(grid, &infos))
		return (FALSE);
	print_infos(&infos);	
	return (TRUE);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		resolve_map_stdin();
	else
		while (++i < argc)
			resolve_map(argv[i]);
}
