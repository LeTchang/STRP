/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 14:05:51 by realves           #+#    #+#             */
/*   Updated: 2014/03/24 21:16:18 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1);
	while (s2[i] != '\0' && n > 0)
	{
		s1[j] = s2[i];
		i++;
		j++;
		n--;
	}
	s1[j] = '\0';
	return (s1);
}
