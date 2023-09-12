/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:48:38 by truello           #+#    #+#             */
/*   Updated: 2023/09/12 15:47:35 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

int	ft_strlen(t_char *str)
{
	return (ft_strlen_c(str, '\0'));
}

int	ft_strlen_c(t_char *str, char stop_char)
{
	if (*str == stop_char)
		return (0);
	return (1 + ft_strlen_c(str + 1, stop_char));
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putchar(char c, t_bool newline)
{
	write(1, &c, 1);
	if (newline)
		write(1, "\n", 1);
}

void	ft_putnbr(int nb)
{
	long int	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-', 0);
		nbr *= -1;
	}
	else if (nbr >= 0 && nbr <= 9)
	{
		ft_putchar('0' + nbr, 0);
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}
