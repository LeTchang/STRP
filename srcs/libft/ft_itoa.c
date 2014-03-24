/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 00:36:03 by realves           #+#    #+#             */
/*   Updated: 2014/03/24 21:00:32 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void		ft_itoa_2(int *n, int *i, char *sign_temp, char *str)
{
	*i = 0;
	if (*n == 0)
	{
		str[0] = '0';
		*i = *i + 1;
	}
	else if (*n < 0)
	{
		*sign_temp = '-';
		*n = *n * - 1;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	char	sign_temp;
	int		i;

	str = (char *) malloc(sizeof(char) * 15);
	ft_itoa_2(&n, &i, &sign_temp, str);
	while (n > 0)
	{
		str[i++] = '0' + n % 10;
		n /= 10;
	}
	str[i] = '\0';
	ft_reverse(str);
	i = 0;
	if (sign_temp == '-')
	{
		i = ft_strlen(str) + 1;
		while (i >= 0)
		{
			str[i + 1] = str[i];
			i--;
		}
		str[0] = '-';
	}
	return (str);
}
