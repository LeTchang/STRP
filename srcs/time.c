/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/29 17:50:19 by realves           #+#    #+#             */
/*   Updated: 2014/03/29 17:55:37 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

double				get_time_ms()
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}