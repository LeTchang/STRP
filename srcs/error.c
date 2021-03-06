/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realves <realves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 20:12:14 by realves           #+#    #+#             */
/*   Updated: 2014/02/27 20:17:15 by realves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void		gm_error(int nb, char *reason)
{
	write(1, reason, ft_strlen(reason));
	write(1, "\n", 1);
	_exit(nb);
}
