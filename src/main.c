/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:41:25 by truello           #+#    #+#             */
/*   Updated: 2023/09/11 18:50:30 by truello          ###   ########.fr       */
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
	t_char	*parsed_grid;
	t_info infos;

	if (!grid)
		return (FALSE);
	if (!parse_infos(grid, &infos))
	{
		free(grid);
		return (FALSE);
	}
	print_infos(&infos);	
	parsed_grid = parse_grid(grid, &infos);
	free(grid);
	free(parsed_grid);
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
