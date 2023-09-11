/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:16:41 by truello           #+#    #+#             */
/*   Updated: 2023/09/11 19:12:46 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse_util.h"

t_bool	ft_is_char_num(t_char c)
{
	return (c >= 48 && c <= 57);
}

t_bool	ft_is_char_alprint(t_char c)
{
	return (c >= 32 && c <= 126 && !ft_is_char_num(c));
}

t_short	ft_short_atoi(t_char *num)
{
	t_short	r;

	r = 0;
	while (*num)
	{
		if (!ft_is_char_num(*num))
			return (0);
		r += *num - '0';
		r *= 10;
		num++;
	}
	r /= 10;
	return (r);
}

t_char	*ft_strndup(t_char *cpy, unsigned int n)
{
	unsigned int	i;
	t_char			*r;

	i = 0;
	r = (t_char *) malloc(sizeof(t_char) * (n + 1));
	r[n] = 0;
	while (i < n)
	{
		r[i] = cpy[i];
		i++;
	}
	return (r);
}
