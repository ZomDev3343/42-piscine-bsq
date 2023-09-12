/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_solution2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:28:41 by jedurand          #+#    #+#             */
/*   Updated: 2023/09/12 14:16:09 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

//pos[0] = x (j), pos[1] = y(i)
void	find_highest(t_short *result, t_info info, t_short *find)
{
	t_short	pos[2];

	pos[1] = 0;
	while (++pos[1] <= info.nb_line)
	{
		pos[0] = 0;
		while (++pos[0] <= info.nb_col)
		{
			if (result[pos[1] * (info.nb_col + 1) + pos[0]] >= find[0])
			{
				if (result[pos[1] * (info.nb_col + 1) + pos[0]] > find[0])
				{
					find[0] = result[pos[1] * (info.nb_col + 1) + pos[0]];
					find[1] = pos[0];
					find[2] = pos[1];
				}
				else if (result[pos[1] * (info.nb_col + 1) + pos[0]] == find[0]
					&& (pos[1] + pos[0]) < (find[1] + find[2]))
				{
					find[1] = pos[0];
					find[2] = pos[1];
				}
			}
		}
	}
}

//count[0] = x (j) , count[1] = y (i)
void	put_bsq(t_char *input, t_info info, t_short *find)
{
	t_short	start_x;
	t_short	end_x;
	t_short	start_y;
	t_short	end_y;
	t_short	count[2];

	start_x = find[1] - find[0] + 1;
	end_x = find[1];
	start_y = find[2] - find[0] + 1;
	end_y = find[2];
	count[1] = start_y;
	while (count[1] <= end_y)
	{
		count[0] = start_x;
		while (count[0] <= end_x)
		{
			input[(count[1] - 1) * (info.nb_col + 1)
				+ count[0] - 1] = info.replace;
			count[0]++;
		}
		count[1]++;
	}
}
