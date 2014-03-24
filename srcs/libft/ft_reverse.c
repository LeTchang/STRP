/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 18:03:52 by realves           #+#    #+#             */
/*   Updated: 2014/03/24 21:09:34 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	ft_reverse(char *str)
{
	size_t	i;
	size_t	j;
	char	tmp;

	if (str != NULL)
	{
		i = 0;
		j = ft_strlen(str) - 1;
		while (i < j)
		{
			tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
			i++;
			j--;
		}
	}
}
