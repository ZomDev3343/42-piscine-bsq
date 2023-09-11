/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:46:38 by truello           #+#    #+#             */
/*   Updated: 2023/09/11 18:07:09 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef unsigned char	t_bool;
typedef unsigned char	t_char;
typedef unsigned short	t_short;

# define FALSE 0
# define TRUE 1

typedef struct s_info
{
	t_short	nb_line;
	t_short	nb_col;
	t_char	empty;
	t_char	full;
	t_char	replace;
}	t_info;

int		ft_strlen(t_char *str);
int		ft_strlen_c(t_char *str, char stop_char);
void	ft_putstr(char *str);
void	ft_putchar(char c, t_bool newline);
void	ft_putnbr(int nb);

#endif
