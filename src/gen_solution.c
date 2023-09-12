/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_solution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedurand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:22:05 by jedurand          #+#    #+#             */
/*   Updated: 2023/09/12 14:15:52 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

t_short	*gen_arr(t_char *input, t_info info)
{
	t_short	i;
	t_short	j;
	t_short	*result;
	t_char	current_char;

	result = malloc(sizeof(t_short) * ((info.nb_line + 1) * (info.nb_col + 1)));
	i = -1;
	while (++i <= info.nb_col)
		result[i] = 0;
	i = 0;
	while (++i <= info.nb_line)
	{
		result[i * (info.nb_col + 1)] = 0;
		j = 0;
		while (++j <= info.nb_col)
		{
			current_char = input[(i - 1) * (info.nb_col + 1) + j - 1];
			if (current_char == info.full)
				result[i * (info.nb_col + 1) + j] = 0;
			else if (current_char == info.empty)
				result[i * (info.nb_col + 1) + j] = 1;
		}
	}
	return (result);
}

t_short	lowest(t_short top, t_short left, t_short diag)
{
	if (top <= left && top <= diag)
		return (top + 1);
	else if (left <= top && left <= diag)
		return (left + 1);
	else
		return (diag + 1);
}

// Modify the matrix according to the rules   
t_short	*process_arr(t_short *result, t_info info)
{
	t_short	i;
	t_short	j;
	t_short	top;
	t_short	left;
	t_short	diag;

	i = 0;
	while (++i <= info.nb_line)
	{
		j = 0;
		while (++j <= info.nb_col)
		{
			if (result[i * (info.nb_col + 1) + j] == 1)
			{
				top = result[(i - 1) * (info.nb_col + 1) + j];
				left = result[i * (info.nb_col + 1) + j - 1];
				diag = result[(i - 1) * (info.nb_col + 1) + j - 1];
				result[i * (info.nb_col + 1) + j] = lowest(top, left, diag);
			}
		}
	}
	return (result);
}

void	print_2d_array(t_char *input, t_info info)
{
	write(1, input, info.nb_line * (info.nb_col + 1));
}

//find[0] = highest, find[1] = x (j), find[2] = y (i)
void	solving(t_char *input, t_info info)
{
	t_short	find[3];
	t_short	*result;

	find[0] = 0;
	find[1] = 0;
	find[2] = 0;
	result = gen_arr(input, info);
	result = process_arr(result, info);
	find_highest(result, info, find);
	put_bsq(input, info, find);
	print_2d_array(input, info);
	free(result);
}

/*int	main(void)
{
	t_info info;
	info.nb_line = 20;
	info.nb_col = 20;
	info.empty = '.';
	info.full = 'o';
	info.replace = 'X';
	t_char input[] = "....................\n...........o.......o\n.o..................\n.........o..o..o....\n....o...............\n.........o..........\n................o...\n.o.......o........o.\n....oo........o.....\n..........o.........\n....................\n....................\n.......o............\no..................o\n...o...............o\n....................\n..........o.........\n...............oo...\n..........o.........\n....................\n";

	solving(input, info);}*/
	//unsigned short	*result;
	//result = solving(input, info);
	// Print the result array
	/*int i;
	i = 0;
	while (i < ((info.nb_line + 1) * (info.nb_col + 1))) {
	    printf("%d", result[i]);
	    if ((i + 1) % (info.nb_col + 1) == 0) {
		printf("\n");
	    }
	    i++;
	}
	return (0);}*/
