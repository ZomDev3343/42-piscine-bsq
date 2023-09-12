/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:10:22 by truello           #+#    #+#             */
/*   Updated: 2023/09/12 18:53:00 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER2_H
# define PARSER2_H

# include "util.h"

int		validate_grid(t_char *grid);
t_bool	unique_info(t_info info);
t_bool	map_error(void);

#endif
