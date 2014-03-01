/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:40:26 by realves           #+#    #+#             */
/*   Updated: 2014/02/27 19:58:22 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int		ft_atoi(const char *str)
{
	int		result;
	int		neg;

	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == 32)
		str++;
	neg = *str == '-' ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && *str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	return (result * neg);
}
