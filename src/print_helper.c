/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:25:06 by truello           #+#    #+#             */
/*   Updated: 2023/09/11 15:49:05 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/print_helper.h"

void	print_infos(t_info *infos)
{
	ft_putstr("---INFOS DE LA MAP---\n");
	ft_putstr("- Lignes : ");
	ft_putnbr(infos->nb_line);
	ft_putchar('\n', 0);
	ft_putstr("- Colonnes : ");
	ft_putnbr(infos->nb_col);
	ft_putchar('\n', 0);
	ft_putstr("- Vide : ");
	ft_putchar(infos->empty, 1);
	ft_putstr("- Obstacle : ");
	ft_putchar(infos->replace, 1);
	ft_putstr("- Plein : ");
	ft_putchar(infos->full, 1);
	ft_putstr("------FIN INFOS------\n");
}
