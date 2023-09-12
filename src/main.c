/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:41:25 by truello           #+#    #+#             */
/*   Updated: 2023/09/12 14:08:00 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"
#include "../includes/parser.h"
#include "../includes/print_helper.h"

#define STDIN_BUFFER_SIZE 512

/* Resolves the map from every parameters the user gives */
t_bool	resolve_map(char *map_file)
{
	t_char	*grid;
	t_info	infos;

	grid = get_grid(map_file);
	if (!grid)
		return (FALSE);
	if (!parse_infos(grid, &infos))
	{
		free(grid);
		return (FALSE);
	}
	print_infos(&infos);
	solving(grid + infos.char_to_skip, infos);
	free(grid);
	return (TRUE);
}

/* Take the map from the standard input and resolves it */
t_bool	resolve_map_stdin(void)
{
	char		*buffer;
	long int	i;

	i = 0;
	ft_putstr("Put the path of the map you want to solve : ");
	buffer = (char *) malloc(STDIN_BUFFER_SIZE + 1);
	if (!buffer)
		return (FALSE);
	buffer[STDIN_BUFFER_SIZE] = 0;
	while (read(0, buffer + i, 1) > 0 && buffer[i] != '\n')
		i++;
	buffer[i] = 0;
	ft_putchar('\n', 0);
	ft_putstr(buffer);
	ft_putchar('\n', 0);
	resolve_map(buffer);
	free(buffer);
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
	return (0);
}
