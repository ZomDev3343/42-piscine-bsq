/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:41:25 by truello           #+#    #+#             */
/*   Updated: 2023/09/12 19:54:14 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"
#include "../includes/parser.h"
#include "../includes/print_helper.h"

/* Resolves the map from every parameters the user gives */
t_bool	resolve_map(char *map_file)
{
	t_char	*grid;
	t_info	infos;
	int		i;

	i = -1;
	grid = get_grid(map_file);
	while (++i < 4)
		if (grid[i] == '\n' || grid[i] == '\0')
			return (FALSE);
	if (!parse_infos(grid, &infos) 
			|| unique_info(infos)
			|| !checkeachcase(infos, grid + infos.char_to_skip)
			|| !check_lines(grid + infos.char_to_skip, infos.nb_line))
	{
		free(grid);
		return (FALSE);
	}
	solving(grid + infos.char_to_skip, infos);
	free(grid);
	return (TRUE);
}

t_bool	resolve_stdin_grid(t_char *grid, t_info *infos)
{
	infos->nb_col = validate_grid(grid);
	if (infos->nb_col == 0
		|| unique_info(*infos)
		|| !checkeachcase(*infos, grid)
		|| !check_lines(grid, infos->nb_line))
	{
		free(grid);
		return (FALSE);
	}
	solving(grid, *infos);
	free(grid);
	return (TRUE);
}

t_char	*get_grid_from_stdin(t_info *infos)
{
	t_char	*buf;
	int		lines_read;
	int		i;

	lines_read = -1;
	i = 0;
	buf = (t_char *) malloc(sizeof(t_char)
			* (STDIN_BUF_SIZE * infos->nb_line) + 1);
	if (!buf)
		return (0);
	while (++lines_read < infos->nb_line)
	{
		while (read(0, buf + i, 1) && buf[i] != '\n')
		{
			i++;
		}
		buf[i] = '\n';
		i++;
	}
	buf[i] = 0;
	return (buf);
}

/* Take the map from the standard input and resolves it */
t_bool	resolve_map_stdin(void)
{
	t_char		*buffer;
	t_char		*infos_str;
	long int	i;
	t_info		infos;

	i = 0;
	infos_str = (t_char *) malloc(18);
	ft_putstr("Put the map you want to solve : \n");
	while (read(0, infos_str + i, 1) && infos_str[i] != '\n' && i < 18)
		i++;
	infos_str[i + 1] = 0;
	if (infos_str[0] == '0' || ft_strlen(infos_str) < 5)
	{
		free(infos_str);
		return (FALSE);
	}
	parse_infos(infos_str, &infos);
	free(infos_str);
	buffer = get_grid_from_stdin(&infos);
	if (!buffer)
		return (FALSE);
	resolve_stdin_grid(buffer, &infos);
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
