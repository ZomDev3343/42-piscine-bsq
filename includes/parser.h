/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:46:29 by truello           #+#    #+#             */
/*   Updated: 2023/09/12 15:59:23 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "util.h"
# include "parse_util.h"
# include "parser2.h"

# define STDIN_BUF_SIZE 1024

t_bool	parse_infos(t_char *grid, t_info *info);
t_char	*get_grid(char *file_path);
t_char	*get_grid_stdin(void);
t_short	parse_nb_line(t_char *grid, t_short *buf);
t_char	*parse_grid(t_char *grid, t_info *infos);

#endif
