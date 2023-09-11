/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:43:40 by truello           #+#    #+#             */
/*   Updated: 2023/09/11 17:38:18 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

t_bool	parse_infos(t_char *grid, t_info *info)
{
	t_short	char_to_skip;

	char_to_skip = parse_nb_line(grid, &(info->nb_line));
	if (grid[char_to_skip + 4] != '\n')
		return (FALSE);
	info->empty = grid[char_to_skip + 1];
	info->replace = grid[char_to_skip + 2];
	info->full = grid[char_to_skip + 3];
	info->nb_col = validate_grid(grid + char_to_skip + 5);
	if (!info->nb_col)
		return (FALSE);
	return (TRUE);
}

t_short	parse_nb_line(t_char *grid, t_short *buf)
{
	int	i;
	int	nb_count;
	t_char	*s_num;
	t_short	nb_line;

	i = 0;
	nb_count = 0;
	while (ft_is_char_num(grid[i++]))
		nb_count++;
	if (nb_count == 0)
		return (0);
	s_num = ft_strndup(grid, nb_count);
	nb_line = ft_short_atoi(s_num);
	*buf = nb_line;
	free(s_num);
	return (nb_count - 1);
}

t_char	*get_grid(char *file_path)
{
	t_char	*grid;
	int	fd;
	int	len;
	char	tmp_c;

	len = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &tmp_c, 1))
		len++;
	close(fd);
	grid = (t_char *) malloc(sizeof(t_char) * (len + 1));
	grid[len] = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	read(fd, grid, len);	
	close(fd);
	return (grid);
}

/*t_char	*get_grid_stdin()
{
	
}*/
