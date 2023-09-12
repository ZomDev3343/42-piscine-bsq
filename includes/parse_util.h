/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:14:49 by truello           #+#    #+#             */
/*   Updated: 2023/09/12 19:31:42 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTIL_H
# define PARSE_UTIL_H

# include "util.h"

t_bool	ft_is_char_num(t_char c);
t_bool	ft_is_char_alprint(t_char c);
t_short	ft_short_atoi(t_char *num);
t_char	*ft_strndup(t_char *cpy, unsigned int n);
t_bool	checkeachcase(t_info info, t_char *str);

#endif
