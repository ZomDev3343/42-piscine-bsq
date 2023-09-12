/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:43:40 by truello           #+#    #+#             */
/*   Updated: 2023/09/12 19:27:34 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

t_bool	parse_infos(t_char *grid, t_info *info)
{
	int		info_len;
	t_char	*s_num;

	info_len = 0;
	while (grid[info_len] != '\n' && grid[info_len])
		info_len++;
	s_num = ft_strndup(grid, info_len - 3);
	parse_nb_line(s_num, &(info->nb_line));
	free(s_num);
	if (info->nb_line == 0)
		return (FALSE);
	info->char_to_skip = info_len + 1;
	info->empty = grid[info_len - 3];
	info->full = grid[info_len - 2];
	info->replace = grid[info_len - 1];
	info->nb_col = validate_grid(grid + info->char_to_skip);
	if (!info->nb_col)
		return (FALSE);
	return (TRUE);
}

t_short	parse_nb_line(t_char *grid, t_short *buf)
{
	unsigned int	i;
	int				nb_count;
	t_char			*s_num;
	t_short			nb_line;

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
	t_char			*grid;
	int				fd;
	unsigned int	len;
	unsigned int	total_len;
	char			buffer[65536];

	len = 1;
	total_len = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (len)
	{
		len = read(fd, buffer, 65536);
		total_len += len;
	}
	close(fd);
	grid = (t_char *) malloc(sizeof(t_char) * (total_len + 1));
	grid[total_len] = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	read(fd, grid, total_len);
	close(fd);
	return (grid);
}

t_char	*parse_grid(t_char *grid, t_info *infos)
{
	t_char			*parsed;
	unsigned int	parsed_len;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	parsed_len = infos->nb_line * (infos->nb_col);
	parsed = (t_char *) malloc(sizeof(t_char) * parsed_len + 1);
	parsed[parsed_len] = 0;
	while (grid[i] != '\n')
		i++;
	while (grid[i])
	{
		if (grid[i] != '\n')
		{
			parsed[j] = grid[i];
			j++;
		}
		i++;
	}
	return (parsed);
}
